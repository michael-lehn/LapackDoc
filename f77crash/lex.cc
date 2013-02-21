/*
 *  This software is derived from f2c (http://www.netlib.org/f2c)
 *
 *  Copyright 1990, 1992 - 1997, 1999, 2000 by AT&T, Lucent Technologies
 *  and Bellcore.
 *
 *  See the LICENCE file for the permission notice and warranty disclaimer
 *  provided by the f2c authors.
 *
 */

#include <f77crash/auxiliary.h>
#include <f77crash/cursor.h>
#include <f77crash/highlight.h>
#include <f77crash/lex.h>
#include <f77crash/tokens.h>

#include <cassert>
#include <cctype>
#include <climits>
#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>

static bool initialized = false;

enum Warn72 {
    Ignore = 0,
    Error = 1,
    FreeFormat = 2
};

static Warn72          warn72;
static bool            noExtension;
static bool            useBackspace;
static bool            shiftCase;

static const int       MAX_CODEBUFFER_SIZE = 10000;
static const int       MAX_CONTINUATIONS   = 99;
static const int       MAX_NAMELENGTH      = 50;
static const char      QUOTE_MARK          = 2;

static std::ifstream   input;
static std::string     filename;

static char            *bufferBegin, *bufferEnd;


enum CardType {
    STEOF = 1,
    STINITIAL = 2,
    STCONTINUE = 3
};

static CardType        cardType;
static char            *cardNext, *cardEnd;
long                   lineNumber;
static long            thisLine, previousLine;
static char            *nextCharacter = 0,
                       *previousCharacter = 0,
                       *lastCharacter;
static char            *lineStart[MAX_CONTINUATIONS];

namespace CrunchInfo {

    struct Pos
    {
        long line;
        int  col;

        Pos() : line(0), col(0) {}

        Pos(long _line, int _col) : line(_line), col(_col) {}
    };

    static std::vector<Pos> pos;
    static const char       *begin, *last;
    static char             **lineStart;
    static long             lineNumber;

    static void
    init(const char *_begin, const char *_last,
         long _lineNumber, char *_lineStart[])
    {
        begin       = _begin;
        last        = _last;
        lineStart   = _lineStart;
        lineNumber  = _lineNumber;
        pos.clear();
    }

    static void
    store(const char *i, const char *j)
    {
        long k;
        long col = i - begin;

        for (k=0; i>=lineStart[k]; ++k) {
            col = i - lineStart[k];
        }
        if ((unsigned int)(j-begin) >= pos.size()) {
            pos.resize(2*long(j-begin+1));
        }
        pos[j-begin] = Pos(lineNumber+k, col);
    }

    static long
    getCurrentLine(const char *i)
    {
        long k;
        for (k=0; i>=lineStart[k]; ++k) {
        }
        return lineNumber+k;
    }

    static long
    getCurrentCol(const char *i)
    {
        long k;
        long col = i - begin;
        for (k=0; i>=lineStart[k]; ++k) {
            col = i - lineStart[k];
        }
        return col;
    }


    static long
    getLine(const char *j)
    {
        if (j-begin>=0 && (unsigned int)(j-begin)<pos.size()) {
            return pos[j-begin].line;
        }
        return -1;
    }

    static long
    getCol(const char *j)
    {
        if (j-begin>=0 && (unsigned int)(j-begin)<pos.size()) {
            return pos[j-begin].col;
        }
        return -1;
    }

} // namespace CrunchInfo

static int             statementNumber;
static int             nextStatementNumber;
static int             parenthesesLevel;
static bool            parenthesesSeen;
static bool            exposedComma, exposedEqual;
static bool            needWhileKey;

enum LexState {
    NEWSTMT = 1,
    FIRSTTOKEN = 2,
    OTHERTOKEN = 3,
    RETEOS = 4
};

static LexState        lexState = NEWSTMT;
static int             stkey;

int                    yyStatementNumber;

int                    tokenLength;
char                   *token = 0;
static int             reservedTokenLength = 502;

int                    newDeclaration;
int                    needKeyword;
bool                   inioctl;

static char            commentStart[1 << CHAR_BIT];
static char            escapes[1 << CHAR_BIT];

struct Punctuation
{
    char c;
    int  value;
};

static struct Punctuation punctuation[] =
{
    { '(', SLPAR     },
    { ')', SRPAR     },
    { '=', SEQUALS   },
    { ',', SCOMMA    },
    { '+', SPLUS     },
    { '-', SMINUS    },
    { '*', SSTAR     },
    { '/', SSLASH    },
    { '$', SCURRENCY },
    { ':', SCOLON    },
    { '<', SLT       },
    { '>', SGT       },
    { 0,   0         }
};

struct DotOp
{
    const char  *name;
    int         value;
};

static struct DotOp  dotOp[] =
{
    { "and.",   SAND   },
    { "or.",    SOR    },
    { "not.",   SNOT   },
    { "true.",  STRUE  },
    { "false.", SFALSE },
    { "eq.",    SEQ    },
    { "ne.",    SNE    },
    { "lt.",    SLT    },
    { "le.",    SLE    },
    { "gt.",    SGT    },
    { "ge.",    SGE    },
    { "neqv.",  SNEQV  },
    { "eqv.",   SEQV   },
    { 0,        0      }
};


struct Key
{
    const char  *name;
    int         value;
};

static const Key *keyStart[26], *keyEnd[26];

static const Key  key[] =
{
    { "assign",          SASSIGN       },
    { "automatic",       SAUTOMATIC    },
    { "backspace",       SBACKSPACE    },
    { "blockdata",       SBLOCK        },
    { "byte",            SBYTE         },
    { "call",            SCALL         },
    { "character",       SCHARACTER    },
    { "close",           SCLOSE        },
    { "common",          SCOMMON       },
    { "complex",         SCOMPLEX      },
    { "continue",        SCONTINUE     },
    { "data",            SDATA         },
    { "dimension",       SDIMENSION    },
    { "doubleprecision", SDOUBLE       },
    { "doublecomplex",   SDCOMPLEX     },
    { "elseif",          SELSEIF       },
    { "else",            SELSE         },
    { "endfile",         SENDFILE      },
    { "endif",           SENDIF        },
    { "enddo",           SENDDO        },
    { "end",             SEND          },
    { "entry",           SENTRY        },
    { "equivalence",     SEQUIV        },
    { "external",        SEXTERNAL     },
    { "format",          SFORMAT       },
    { "function",        SFUNCTION     },
    { "goto",            SGOTO         },
    { "implicitnone",    SIMPLICITNONE },
    { "implicit",        SIMPLICIT     },
    { "include",         SINCLUDE      },
    { "inquire",         SINQUIRE      },
    { "intrinsic",       SINTRINSIC    },
    { "integer",         SINTEGER      },
    { "logical",         SLOGICAL      },
    { "namelist",        SNAMELIST     },
    { "none",            SUNDEFINED    },
    { "open",            SOPEN         },
    { "parameter",       SPARAM        },
    { "pause",           SPAUSE        },
    { "print",           SPRINT        },
    { "program",         SPROGRAM      },
    { "punch",           SPUNCH        },
    { "read",            SREAD         },
    { "real",            SREAL         },
    { "recursivesubroutine", SRECURSIVE    },
    { "return",          SRETURN       },
    { "rewind",          SREWIND       },
    { "save",            SSAVE         },
    { "static",          SSTATIC       },
    { "stop",            SSTOP         },
    { "subroutine",      SSUBROUTINE   },
    { "then",            STHEN         },
    { "undefined",       SUNDEFINED    },
    { "while",           SWHILE        },
    { "write",           SWRITE        },
    { 0,                 0             }
};

//
//  Forward declarations of internal functions
//
static void
setCursor(int tokenId);

static void
adjustTokenLength(int newLength);

static char
escape(char c);

static bool
popInputFile();

static CardType
getInputCards();

static CardType
getNextInputCard(bool noContinuationAllowed);

static void
crunch();

static void
analyze();

static int
getKeyword();

static int
getToken(bool intOnly);

static int
hexCheck(int key);


//
//  Implementation
//

void
initLex()
{
    initAuxiliary();
    initHighlight();

    warn72       = Ignore;
    noExtension  = false;
    useBackspace = true;
    shiftCase    = true;

//
//  Init buffer for storing source code, input cards, ...
//
    bufferBegin = new char[MAX_CODEBUFFER_SIZE];
    assert(bufferBegin);
    bufferEnd = bufferBegin + MAX_CODEBUFFER_SIZE - 1;

    cardNext = 0;
    cardEnd  = bufferBegin;

    parenthesesLevel = 0;
    parenthesesSeen  = false;

//
//  Init lookup-table for characters starting comment 
//
    commentStart[(unsigned char)('c')] = 1;
    commentStart[(unsigned char)('C')] = 1;
    commentStart[(unsigned char)('*')] = 1;
    commentStart[(unsigned char)('!')] = 1;
    commentStart[(unsigned char)('#')] = 1;

//
//  Init lookup-table for escaping characters
//
    for (int i=0; i < (1<<CHAR_BIT); ++i) {
        escapes[i] = i;
    }
    escapes[(unsigned char)('b')] = '\b';
    escapes[(unsigned char)('t')] = '\t';
    escapes[(unsigned char)('n')] = '\n';
    escapes[(unsigned char)('f')] = '\f';
    escapes[(unsigned char)('r')] = '\r';
    escapes[(unsigned char)('0')] = 0;

//
//  Init lookup-table for Fortran keywords
//
    for (int i = 0; i<26; ++i) {
        keyStart[i] = 0;
    }

    for (const Key *pk=key; pk->name; ++pk) {
        unsigned char j = letter(pk->name[0]);
        if (keyStart[j] == 0) {
            keyStart[j] = pk;
        }
        keyEnd[j] = pk;
    }

//
//  Reserve memory for token string
//
    adjustTokenLength(reservedTokenLength);

    initialized = true;
}

int
yylex()
{
    assert(initialized);

    static int  tokenNumber;
    int         returnValue;

    previousCharacter = nextCharacter;

    switch (lexState) {

    case NEWSTMT:
//
//      need a new statement
//
        returnValue = getInputCards();
        if (returnValue == STEOF) {
            returnValue = SEOF;
            break;
        }
        crunch();
        tokenNumber = 0;
        lexState = FIRSTTOKEN;
        yyStatementNumber = statementNumber;
        statementNumber = nextStatementNumber;
        tokenLength = 0;
        returnValue = SLABEL;
        break;

first:

    case FIRSTTOKEN:
//
//      first step on a statement
//
        analyze();
        lexState = OTHERTOKEN;
        tokenNumber = 1;
        returnValue = stkey;
        break;

    case OTHERTOKEN:
//
//      return next token
//
        if (nextCharacter > lastCharacter) {
            goto reteos;
        }
        ++tokenNumber;
        if ((stkey==SLOGIF || stkey==SELSEIF) && parenthesesLevel==0
         && tokenNumber>3)
        {
            goto first;
        }

        if (stkey==SASSIGN && tokenNumber==3 && nextCharacter<lastCharacter
         && nextCharacter[0]=='t' && nextCharacter[1]=='o')
        {
            nextCharacter += 2;
            returnValue = STO;
            break;
        }

        if (tokenNumber == 2 && stkey == SDO) {
            returnValue = getToken(true);
        } else {
            returnValue = getToken(false);
        }
        break;

reteos:

    case RETEOS:
        lexState = NEWSTMT;
        returnValue = SEOS;
        break;

    default:
        std::cerr << "Error in line " << lineNumber
                  << ": impossible lexstate " << lexState
                  << std::endl;
        exit(1);
        break;
    }

    setCursor(returnValue);

    return returnValue;
}

void
yyerror(const char *s)
{
    /*
        std::cerr << "Error in line " << lineNumber
                  << ": " << s
                  << std::endl;
    */
}

void
flushLine()
{
        lexState = RETEOS;
}

static void
setCursor(int tokenId)
{
    cursor.fromLine        = CrunchInfo::getLine(previousCharacter);
    cursor.fromCol         = CrunchInfo::getCol(previousCharacter);
    cursor.toLine          = CrunchInfo::getLine(nextCharacter-1);
    cursor.toCol           = CrunchInfo::getCol(nextCharacter-1);

    cursor.tokenId         = tokenId;
    cursor.statementNumber = yyStatementNumber;

    size_t len = 0;

    if (previousCharacter >= bufferBegin
     && previousCharacter <= nextCharacter
     && nextCharacter <= bufferEnd)
    {
        len = nextCharacter - previousCharacter;
    }

    cursor.content.replace(0, cursor.content.size(), previousCharacter, len);

    if (isHighlighted(tokenId)) {
        std::cout << getHighlightTag(tokenId) << ",";
        std::cout << cursor.fromLine-1 << "." << cursor.fromCol+6 << ":"
                  << cursor.toLine-1 << "." << cursor.toCol+6 << ",";
        std::cout << yyStatementNumber << ","
                  << tokenId << "," << cursor.content
                  << std::endl;
    }
}

static void
adjustTokenLength(int newLength)
{
    while (reservedTokenLength < newLength) {
        reservedTokenLength = 2*reservedTokenLength + 2;
    }

    if ((token = (char *)(realloc(token, reservedTokenLength)))) {
        return;
    }

    std::cerr << "adjtoklen: realloc(" << reservedTokenLength
              << ") failure!" << std::endl;

    exit(2);
}

static char
escape(char c)
{
    typedef unsigned char uchar;
    return escapes[uchar(c)];
}

//
//  Public interface
//

void
doInputFile(const char *filename)
{
    assert(cardNext==0);
    assert(cardEnd==bufferBegin);

    input.open(filename, std::ifstream::in);
}

static bool
popInputFile()
{
    return false;
}


static CardType
getInputCards()
{

top:

    if (cardNext == 0) {
        cardNext        = bufferBegin;
        cardType        = getNextInputCard(true);
        statementNumber = nextStatementNumber;
        previousLine    = thisLine;
    }

    if (cardType == STEOF) {
        if (popInputFile()) {
            goto top;
        } else {
            return STEOF;
        }
    }

    if (cardType == STCONTINUE) {
        lineNumber = thisLine;
        cardNext   = 0;
        goto top;
    }

//
// Get rid of unused space at the head of the buffer */
//
    if (cardNext > bufferBegin) {
        const char *q = cardNext;
        char       *p = bufferBegin;
        while (q < cardEnd) {
            *p++ = *q++;
        }
        cardEnd = p;
    }

//
// Be aware that the input (i.e. the string at the address  cardNext)   is NOT
// NULL-terminated
//
// This loop merges all continuations into one long statement, AND puts the next
// card to be read at the end of the buffer (i.e. it stores the look-ahead card
// when there's room)
//
    int numberOfContinuations = 0;

    for (;;) {
        cardNext = cardEnd;

        if (numberOfContinuations >= MAX_CONTINUATIONS
         || cardNext+66 > bufferEnd)
        {
            lineNumber = thisLine;
            std::cerr << "Error in line " << lineNumber
                      << ": too many continuation lines"
                      << std::endl;
        }

        lineStart[numberOfContinuations++] = cardNext;

        if ((cardType = getNextInputCard(false)) != STCONTINUE) {
            break;
        }

        if (numberOfContinuations == 20 && noExtension) {
            lineNumber = thisLine;
            std::cerr << "Error: more than 19 continuation lines." << std::endl;
        }
    }

    nextCharacter = bufferBegin;
    lastCharacter = cardNext - 1;

    lineNumber   = previousLine;
    previousLine = thisLine;

    return(STINITIAL);
}

static CardType
getNextInputCard(bool noContinuationAllowed)
{
    assert(input.is_open());

    bool ampersant;
    bool specialLine;          // Special line - true when the line is allowed
                               // to have more than 66 characters (e.g. the
                               // "&" shorthand for continuation, use of a "\t"
                               // to skip part of the label columns)

    static char a[6];          // Statement label buffer
    static char *aEnd = a+6;

    char        buf72[24];
    char        *atend;
    char        *p, *bEnd;

    int         c;

    assert(cardNext!=0);

top:
    cardEnd     = cardNext;
    bEnd        = cardNext + 66;
    ampersant   = false;
    specialLine = false;

    assert(cardEnd<=bufferEnd);

//
//  Handle the continuation shorthand of "&" in the first column, which stands
//  for "     x"
//
    if ((c=input.get()) == '&') {
        a[0] = c;
        a[1] = 0;
        a[5] = 'x';
        ampersant = specialLine = true;
        bEnd = bufferEnd;
        p = aEnd;
    }
//
//  Handle the Comment cards (a 'C', 'c', '*', or '!' in the first column).
//
    else if (commentStart[c & ((1<<CHAR_BIT) - 1)]) {
        if (input.eof()) {
            return STEOF;
        }
        if (c == '#') {
            *cardEnd++ = c;
            while ((c=input.get()) != '\n') {
                if (c==EOF) {
                    return STEOF;
                } else if (cardEnd<bufferEnd) {
                    *cardEnd++ = c;
                }
            }
            ++thisLine;
            *cardEnd = 0;

            p = cardNext;
            if (cardNext[1]==' ') {
                p += 2;
            } else if (!strncmp(cardNext, "#line", 6)) {
                p += 6;
            } else {
bad_cpp:
                lineNumber = thisLine;
                std::cerr << "Error in line " << lineNumber << std::endl;
                std::cerr << "Bad # line: " << cardNext << std::endl;
                goto top;
            }

            if (*p < '1' || *p > '9') {
                goto bad_cpp;
            }
            long L = *p - '0';
            while ((c = *++p) >= '0' && c <= '9') {
                L = 10*L + c - '0';
            }
            while (c == ' ') {
                c = *++p;
            }
            if (!c) {
                /* accept "# 1234" */
                std::cerr << "TODO: Keeping track of changed line numbers"
                          << std::endl;
                thisLine = L - 1;
                goto top;
            }
            if (c != '"') {
                goto bad_cpp;
            }
            char *newFilename = p+1;
            while (*++p != '"') {
                if (!*p) {
                    goto bad_cpp;
                }
            }
            *p = 0;
            thisLine = L-1;
            std::cerr << "TODO: Keeping track of changed line numbers"
                      << std::endl;

            if (!filename.c_str()
             || strcmp(filename.c_str(), newFilename))
            {
                std::cerr << "TODO: Keeping track of changed file name"
                           << std::endl;
                filename = std::string(newFilename);
            }
            goto top;
        }

        std::cout << "COMMENT,"
                  << thisLine << ".0:" << thisLine << ".-1"
                  << std::endl;

        while (!input.eof() && ((c = input.get()) != '\n')) {
        }

        if (input.eof()) {
            if (c != '\n') {
                // To allow the line index to increment correctly
                return STEOF;
            }
        }

        ++thisLine;
        goto top;
    }

//
//  Load buffer   a   with the statement label
//
    else if (c!=EOF) {

        // a tab in columns 1-6 skips to column 7
        input.unget();
        for (p=a; p<aEnd && (c=input.get())!='\n' && c!=EOF; ) {
            if (c=='\t') {

                // The tab character translates into blank characters in the
                // statement label
                atend = p;
                while (p<aEnd) {
                    *p++ = ' ';
                }
                specialLine = true;
                bEnd = bufferEnd;
            } else {
                *p++ = c;
            }
        }
    }

//
//  By now we've read either a continuation character or the statement label
//  field
//
    if (c==EOF) {
        return STEOF;
    }

//
//  The next 'if' block handles lines that have fewer than 7 characters
//
    if (c=='\n') {
        while (p<aEnd) {
            *p++ = ' ';
        }

        //
        //  Blank out the buffer on lines which are not longer than 66
        //  characters
        if (! specialLine) {
            while (cardEnd<bEnd) {
                *cardEnd++ = ' ';
            }
        }
    } else {
        //  read body of line
        if (warn72==FreeFormat) {
            specialLine = true;
            bEnd = bufferEnd;
        }
        while (cardEnd<bEnd && (c=input.get())!='\n' && c!=EOF ) {
            *cardEnd++ = c;
        }
        if (c==EOF) {
            return STEOF;
        }

        //  Drop any extra characters on the input card; this usually means
        //  those after column 72

        if (c!='\n') {
            int i = 0;
            while( (c=input.get())!='\n' && c != EOF) {
                if (i<23 && c!='\r') {
                    buf72[i++] = c;
                }
            }
            if (warn72!=Ignore && i && !specialLine) {
                buf72[i] = 0;
                if (i>=23) {
                    strcpy(buf72+20, "...");
                }
                lineNumber = thisLine + 1;
                std::cerr << "Error in line " << lineNumber << std::endl;
                std::cerr << "text after column 72: " << buf72 << std::endl;
            }
            if(c == EOF) {
                return STEOF;
            }
        }

        if (! specialLine) {
            while(cardEnd<bEnd) {
                *cardEnd++ = ' ';
            }
        }
    }

//
//  The flow of control usually gets to this line (unless an earlier RETURN has
//  been taken) */
//
    ++thisLine;

    if (!isspace(a[5]) && a[5]!='0') {
        //  Fortran 77 specifies that a 0 in column 6
        //  does not signify continuation

        if (!ampersant) {
            for (p=a; p<aEnd; ) {
                if (*p++=='!' && p!=aEnd) {
                    goto initcheck;
                }
            }
        }
        if (noContinuationAllowed) {
            lineNumber = thisLine;
            std::cerr << "Error in line " << lineNumber << ": "
                      << "illegal continuation card (starts \""
                      << std::string(a, 0, 6) << "\")"
                      << std::endl;
        } else if (!ampersant && strncmp(a, "     ", 5)) {
            lineNumber = thisLine;
            std::cerr << "Error in line " << lineNumber << ": "
                      << "illegal continuation card (starts \""
                      << std::string(a, 0, 6) << "\")"
                      << std::endl;
        }
        return STCONTINUE;
    }

initcheck:
    for (p=a; p<atend; ++p) {
        if (!isspace(*p)) {
            if (*p++ != '!') {
                goto initline;
            }
            printf("COMMENT,%ld.%ld:%ld.-1\n",
                   thisLine-1, p-a-1, thisLine-1);
            goto top;
        }
    }
    for (p=cardNext; p<cardEnd; ++p) {
        if (!isspace(*p)) {
            if (*p++ != '!') {
                goto initline;
            }
            printf("COMMENT,%ld.%ld:%ld.-1\n",
                   thisLine-1, p-cardNext+5, thisLine-1);
            goto top;
        }
    }

//
// Skip over blank cards by reading the next one right away
//

    goto top;

initline:

//
// Set  nextStatementNumber  equal to the integer value of the statement label
//
    nextStatementNumber = 0;
    bEnd = a + 5;
    for (p=a; p<bEnd; ++p) {
        if (!isspace(*p)) {
            if (isdigit(*p)) {
                nextStatementNumber = 10*nextStatementNumber + (*p - '0');
            } else if (*p == '!') {
                printf("COMMENT,%ld.%ld:%ld.-1",
                       thisLine-1, p-a-1, thisLine-1);
                cardEnd = cardNext;
                break;
            } else {
                lineNumber = thisLine;
                std::cerr << "Error in line " << lineNumber << ": "
                          << "nondigit in statement label field \""
                          << std::string(a, 0, 5) << "\")"
                          << std::endl;
            }
        }
    }
    return STINITIAL;
}

static void
crunch()
{
//
//  i is the next input character to be looked at
//  j is the next output character
//
    char *i, *j;
    char *previousString = bufferBegin;

    exposedComma = false;
    exposedEqual = false;

    parenthesesLevel = 0;
    parenthesesSeen  = false;

    CrunchInfo::init(bufferBegin, lastCharacter, lineNumber, lineStart);

    int k = 0;

    for (i=j=bufferBegin; i<=lastCharacter; ++i) {

        if (isspace(*i)) {
            continue;
        }
        if (*i == '!') {
            long currLine = CrunchInfo::getCurrentLine(i);
            int currCol  = CrunchInfo::getCurrentCol(i) + 7;

            printf("COMMENT,%ld.%d:%ld.-1\n",
                   currLine-1, currCol-1, currLine-1);

            while (i >= lineStart[k]) {
                if (++k >= MAX_CONTINUATIONS) {
                    std::cerr << "Error in line " << lineNumber
                              << ": too many continuation lines"
                              << " (MAX_CONTINUATIONS = " << MAX_CONTINUATIONS
                              << ")" << std::endl;
                    exit(1);
                }
            }
            i = lineStart[k] - 1;
            continue;
        }

        if (*i=='\'' ||  *i=='"') {
//
//          Keep everything in a quoted string
//
            int  length = 0;
            char quote = *i;

            *j = QUOTE_MARK;
            CrunchInfo::store(i, j);

            for(;;) {
                if (++i > lastCharacter) {
                    std::cerr << "Error in line " << lineNumber
                              << ": unbalanced quotes; closing quote supplied"
                              << std::endl;
                    if (j >= lastCharacter) {
                        j = lastCharacter - 1;
                    }
                    break;
                }
                if (*i == quote) {
                    if (i<lastCharacter && i[1]==quote) {
                        ++i;
                    } else {
                        break;
                    }
                } else if(*i=='\\' && i<lastCharacter && useBackspace) {
                    ++i;
                    *i = escape(*i);
                }
                *++j = *i;
                CrunchInfo::store(i, j);
                length++;
            }

            if ((length = j - bufferBegin) > reservedTokenLength) {
                adjustTokenLength(length);
            }

            j[1] = QUOTE_MARK;
            CrunchInfo::store(i, j+1);

            j += 2;
            previousString = j;

        } else if ((*i=='h' || *i=='H') && j>previousString) {
//
//          Test for Hollerith strings
//
            char *j0 = j - 1;
            if (! isdigit(*j0)) {
                goto copychar;
            }

            int hollerithLength = *j0 - '0';
            int ten = 10;

            char *j1 = previousString;
            if (j1 > bufferBegin && j1[-1] == QUOTE_MARK) {
                --j1;
            }
            if (j1+4 < j) {
                j1 = j-4;
            }
            for (;;) {
                if (j0-- <= j1) {
                    goto copychar;
                }
                if (! isdigit(*j0 )) {
                    break;
                }
                hollerithLength += ten * (*j0-'0');
                ten*=10;
            }
//
//          A Hollerith string must be preceded by a punctuation mark.
//          '*' is possible only as repetition factor in a data statement
//          not, in particular, in character*2h .
//          To avoid some confusion with missing commas in FORMAT statements,
//          treat a preceding string as a punctuation mark.
//
            if (!(*j0=='*' && bufferBegin[0]=='d')
             && *j0!='/' && *j0!='(' && *j0!=',' && *j0!='=' && *j0!='.'
             && *j0 != QUOTE_MARK)
            {
                goto copychar;
            }
            int hollerithLength0 = hollerithLength;
            if (i+hollerithLength > lastCharacter) {
                std::cerr << "Error in line " << lineNumber
                          << ": " << hollerithLength << "H too big"
                          << std::endl;
                hollerithLength = lastCharacter - i;
                hollerithLength0 = -1;
            }
            j0[1] = QUOTE_MARK;
            j = j0 + 1;
            while (hollerithLength-- > 0) {
                if (++i > lastCharacter) {
hol_overflow:
                    if (hollerithLength0 >= 0) {
                        std::cerr << "Error in line " << lineNumber
                                  << "escapes make " << hollerithLength0
                                  << "H too big" << std::endl;
                    }
                    break;
                }
                if (*i == '\\' && useBackspace) {
                    if (++i > lastCharacter) {
                        goto hol_overflow;
                    }
                    *i = escape(*i);
                }
                *++j = *i;
                CrunchInfo::store(i, j);
            }
            j[1] = QUOTE_MARK;
            CrunchInfo::store(i, j+1);
            j+=2;
            previousString = j;

        } else {

            if (*i == '(') {
                ++parenthesesLevel;
                parenthesesSeen = true;
            } else if (*i == ')') {
                --parenthesesLevel;
            } else if (parenthesesLevel == 0) {
                if (*i == '=') {
                    exposedEqual = true;
                } else if (*i == ',') {
                    exposedComma = true;
                }
            }
copychar:
//
//          not a string or space -- copy, shifting case if necessary
//
            if (shiftCase && isupper(*i)) {
                *j++ = tolower(*i);
            } else {
                *j++ = *i;
            }
            CrunchInfo::store(i, j-1);
        }
    }

    lastCharacter = j - 1;
    nextCharacter = bufferBegin;
}

static void
analyze()
{
    if (parenthesesLevel != 0) {
        std::cerr << "Error in line " << lineNumber
                  << ": unbalanced parentheses, statement skipped"
                  << std::endl;
        stkey = SUNKNOWN;
//
//      prevent double error msg
//
        lastCharacter = bufferBegin - 1;
        return;
    }

    if (nextCharacter+2<=lastCharacter
     && nextCharacter[0]=='i' && nextCharacter[1]=='f'
     && nextCharacter[2]=='(')
    {
//
//      assignment or if statement -- look at character after balancing paren
//
        char *i;
        parenthesesLevel = 1;
        for (i=nextCharacter+3 ; i<=lastCharacter; ++i) {
            if (*i == QUOTE_MARK) {
                while (*++i != QUOTE_MARK) {
                }
            } else if (*i == '(') {
                ++parenthesesLevel;
            } else if (*i == ')') {
                if (--parenthesesLevel == 0) {
                    break;
                }
            }
        }
        if (i >= lastCharacter) {
            stkey = SLOGIF;
        } else if (i[1] == '=') {
            stkey = SLET;
        } else if (isdigit(i[1])) {
            stkey = SARITHIF;
        } else {
            stkey = SLOGIF;
        }
        if (stkey != SLET) {
            nextCharacter += 2;
        }

    } else if (exposedEqual) {
//
//      may be an assignment
//
        if (exposedComma && nextCharacter<lastCharacter
         && nextCharacter[0]=='d' && nextCharacter[1]=='o')
        {
            stkey = SDO;
            nextCharacter += 2;
        } else {
            stkey = SLET;
        }

    } else if (parenthesesSeen && (nextCharacter + 7 < lastCharacter)
//             screen out "double..." early
            && nextCharacter[2] != 'u'
            && nextCharacter[0] == 'd' && nextCharacter[1] == 'o'
            && ((nextCharacter[2] >= '0' && nextCharacter[2] <= '9')
                || nextCharacter[2] == ','
                || nextCharacter[2] == 'w'))
    {
        stkey = SDO;
        nextCharacter += 2;
        needWhileKey = true;

    } else {
//
//      otherwise search for keyword
//
        stkey = getKeyword();
        if (stkey==SGOTO && lastCharacter>=nextCharacter) {
            if (nextCharacter[0]=='(') {
                stkey = SCOMPGOTO;
            } else if (isAlpha_(*nextCharacter)) {
                stkey = SASGOTO;
            }
        }
    }
    parenthesesLevel = 0;
}

static int
getKeyword()
{
    if (! isAlpha_(*nextCharacter)) {
        return SUNKNOWN;
    }

    unsigned char k = letter(nextCharacter[0]);

    if (const Key *pk = keyStart[k]) {
        for (const Key *pend = keyEnd[k]; pk<=pend; ++pk ) {

            const char *i = pk->name;
            char       *j = nextCharacter;

            while (*++i==*++j && *i!='\0') {
            }

            if (*i=='\0' && j<=lastCharacter+1) {
                nextCharacter = j;
                return pk->value;
            }
        }
    }
    return SUNKNOWN;
}

static int
getToken(bool intOnly)
{
    static const char *expMinus = "X**-Y treated as X**(-Y)",
                      *expPlus  = "X**+Y treated as X**(+Y)";

    bool haveDot = false;
    bool haveExp = false;
    bool haveDouble = false;

    char *p, *i;

    int c = (unsigned char)(*nextCharacter);

    if (c == QUOTE_MARK) {
        ++nextCharacter;
        p = token;
        while (*nextCharacter != QUOTE_MARK) {
            *p++ = *nextCharacter++;
        }
        tokenLength = p - token;
        *p = 0;
//
//      allow octal, binary, hex constants of the form 'abc'x (etc.)
//
        int value;
        if (++nextCharacter <= lastCharacter
         && isAlpha_(value = (unsigned char)(*nextCharacter)))
        {
            ++nextCharacter;
            return hexCheck(value);
        }
        return SHOLLERITH;
    }

    if (needKeyword) {
        needKeyword = false;
        return getKeyword();
    }

    for (Punctuation *pp=punctuation; pp->c; ++pp) {

        if (c == pp->c) {
            int value = pp->value;
            if (++nextCharacter <= lastCharacter) {
                switch (c) {

                case '/':
                    switch (*nextCharacter) {

                        case '/':
                            nextCharacter++;
                            value = SCONCAT;
                            break;

                        case '=':
                            goto sne;

                        default:
                            if (newDeclaration && parenthesesLevel == 0) {
                                value = SSLASHD;
                            }
                    }
                    return value;

                case '*':
                    if (*nextCharacter == '*') {
                        nextCharacter++;
                        if (noExtension && nextCharacter <= lastCharacter) {
                            switch (*nextCharacter) {

                            case '-':
                               std::cerr << "Error in line " << lineNumber
                                         << expMinus << std::endl;
                               break;

                            case '+':
                               std::cerr << "Error in line " << lineNumber
                                         << expPlus << std::endl;
                            }
                        }
                        return SPOWER;
                    }
                    break;

                case '<':
                    switch(*nextCharacter) {

                    case '=':
                        nextCharacter++;
                        value = SLE;
                        break;

                    case '>':
 sne:
                        nextCharacter++;
                        value = SNE;
                    }
                    goto extchk;

                case '=':
                    if (*nextCharacter == '=') {
                        nextCharacter++;
                        value = SEQ;
                        goto extchk;
                    }
                    break;

                case '>':
                    if (*nextCharacter == '=') {
                        nextCharacter++;
                        value = SGE;
                    }
 extchk:
                    if (noExtension) {
                        std::cerr << "Error in line " << lineNumber
                                  << "Fortran 8x comparison operator"
                                  << std::endl;
                    }
                    return value;
                }
            } else if (c == '/' && newDeclaration && parenthesesLevel == 0) {
                return SSLASHD;
            }
            switch (value) {

                case SLPAR:
                    ++parenthesesLevel;
                    break;

                case SRPAR:
                    --parenthesesLevel;
            }
            return value;
        }
    }

    if (c == '.') {

        if (nextCharacter >= lastCharacter) {
            goto badchar;
        } else if (isdigit(nextCharacter[1])) {
            goto numconst;
        } else {
            const char *j;

            for (DotOp *pd=dotOp; (j=pd->name) ; ++pd) {
                for (i=nextCharacter+1; i<=lastCharacter; ++i) {
                    if (*i != *j) {
                        break;
                    } else if (*i != '.') {
                        ++j;
                    } else {
                        nextCharacter = i+1;
                        return pd->value;
                    }
                }
            }
            goto badchar;
        }

    }

    if (isAlpha_(c)) {
        p = token;
        *p++ = *nextCharacter++;
        while (nextCharacter<=lastCharacter) {
            if (isAlphaNum_((unsigned char)(*nextCharacter))) {
                *p++ = *nextCharacter++;
            } else {
                break;
            }
        }

        tokenLength = p - token;
        *p = 0;

        if (needWhileKey) {
            needKeyword = 0;
            if (tokenLength == 5 && nextCharacter <= lastCharacter
             && *nextCharacter == '(' // )
             && !strcmp(token,"while"))
            {
                return SWHILE;
            }
        }

        if (inioctl && nextCharacter<=lastCharacter && *nextCharacter=='=') {
            ++nextCharacter;
            return SNAMEEQ;
        }

        if (tokenLength>8 && !strncmp(token, "function", 8)
         && isAlpha_((unsigned char)(token[8]))
         && nextCharacter < lastCharacter && nextCharacter[0]=='(' &&
         (nextCharacter[1]==')' || isAlpha_((unsigned char)(nextCharacter[1]))))
        {
            nextCharacter -= (tokenLength - 8);
            return SFUNCTION;
        }

        if (tokenLength > MAX_NAMELENGTH) {
            char buff[2*MAX_NAMELENGTH+50];
            if (tokenLength >= MAX_NAMELENGTH+10) {
                sprintf(buff,
                "name %.*s... too long, truncated to %.*s",
                MAX_NAMELENGTH+6, token, MAX_NAMELENGTH, token);
            } else {
                sprintf(buff,
                "name %s too long, truncated to %.*s",
                token, MAX_NAMELENGTH, token);
            }
            std::cerr << "Error in line " << lineNumber
                      << ": " << buff << std::endl;
            tokenLength = MAX_NAMELENGTH;
            token[MAX_NAMELENGTH] = '\0';
        }

        if (tokenLength==1 && *nextCharacter==QUOTE_MARK) {
            int value = token[0];
            ++nextCharacter;
            for (p=token; *nextCharacter!=QUOTE_MARK; ) {
                *p++ = *nextCharacter++;
            }
            ++nextCharacter;
            tokenLength = p - token;
            *p = 0;
            return hexCheck(value);
        }
        return(SNAME);
    }

    if (isdigit(c)) {
//
//      Check for NAG's special hex constant
//
        if ((nextCharacter[1] == '#' && nextCharacter < lastCharacter)
        ||  (nextCharacter[2] == '#' && isdigit(nextCharacter[1]) &&
             lastCharacter - nextCharacter >= 2))
        {

            int radix = atoi(nextCharacter);
            p = 0;
            if (*++nextCharacter != '#') {
                ++nextCharacter;
            }
            if (radix != 2 && radix != 8 && radix != 16) {
                std::cerr << "Error in line " << lineNumber
                          << ":invalid base " << radix
                          << " for constant, defaulting to hex"
                          << std::endl;
                radix = 16;
            }
            if (++nextCharacter > lastCharacter) {
                goto badchar;
            }

            for (p = token; hexToInt(*nextCharacter) < radix;) {
                *p++ = *nextCharacter++;
                if (nextCharacter > lastCharacter) {
                    break;
                }
            }
            tokenLength = p - token;
            *p = 0;
            return (radix == 16) ? SHEXCON
                                 : ((radix == 8) ? SOCTCON
                                                 : SBITCON);
        }
    } else {
        goto badchar;
    }

numconst:

    char *n1;

    for (n1 = nextCharacter; nextCharacter<=lastCharacter; ++nextCharacter) {
        if (*nextCharacter == '.') {
            if (haveDot) {
                break;
            } else if (nextCharacter+2<=lastCharacter
                    && isAlpha_((unsigned char)(nextCharacter[1]))
                    && isAlpha_((unsigned char)(nextCharacter[2])))
            {
                break;
            } else {
                haveDot = true;
            }
        } else if (! isdigit((unsigned char)(*nextCharacter))) {
            if (!intOnly && (*nextCharacter=='d' || *nextCharacter=='e') ) {
                p = nextCharacter;
                haveExp = true;
                if (*nextCharacter == 'd') {
                    haveDouble = true;
                }
                if (nextCharacter<lastCharacter) {
                    if (nextCharacter[1]=='+' || nextCharacter[1]=='-') {
                        ++nextCharacter;
                    }
                }
                if (! isdigit(*++nextCharacter)) {
                    nextCharacter = p;
                    haveDouble = haveExp = false;
                    break;
                }
                for (++nextCharacter;
                     nextCharacter<=lastCharacter
                     && isdigit((unsigned char)(*nextCharacter));
                     ++nextCharacter);
            }
            break;
        }
    }

    p = token;
    i = n1;

    while (i < nextCharacter) {
        *p++ = *i++;
    }
    tokenLength = p - token;
    *p = 0;

    if (haveDouble) {
        return SDCON;
    }

    if (haveDot || haveExp) {
        return SRCON;
    }

    return SICON;

badchar:

    bufferBegin[0] = *nextCharacter++;
    return SUNKNOWN;
}

static int
hexCheck(int key)
{
    static const char *kindName[3] = { "hexadecimal", "octal", "binary" };

    int radix, kind;

    switch (key) {

    case 'z':
    case 'Z':
    case 'x':
    case 'X':
        radix = 16;
        key = SHEXCON;
        kind = 0;
        break;

    case 'o':
    case 'O':
        radix = 8;
        key = SOCTCON;
        kind= 1;
        break;

    case 'b':
    case 'B':
        radix = 2;
        key = SBITCON;
        kind = 2;
        break;

    default:
        std::cerr << "Error in line " << lineNumber
                  << ": bad bit identifier"
                  << std::endl;;
        return SNAME;
    }

    for (char *p = token; *p; p++) {
        if (hexToInt(*p) >= radix) {
            std::cerr << "Error in line " << lineNumber
                      << ": invalid " << kindName[kind] << " character"
                      << std::endl;
            break;
        }
    }
    return key;

}

