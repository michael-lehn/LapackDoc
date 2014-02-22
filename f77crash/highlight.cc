#include <f77crash/highlight.h>

enum Keyword {
    Void          = 0,
    Identifier    = 1,
    Statement     = 2,
    Comment       = 3,
    Constant      = 4,
    String        = 5,
    UnitStatement = 6,
    Type          = 7,
    _numKeywords  = 8
};

static std::string  tag[_numKeywords];
static Keyword      keyword[NUM_TOKENS+1];

void
initHighlight()
{
    tag[Void]              = std::string("");
    tag[Identifier]        = std::string("IDENTIFIER");
    tag[Statement]         = std::string("STATEMENT");
    tag[Comment]           = std::string("COMMENT");
    tag[Constant]          = std::string("CONSTANT");
    tag[String]            = std::string("STRING");
    tag[UnitStatement]     = std::string("UNITSTATEMENT");
    tag[Type]              = std::string("TYPE");

    keyword[SCOMMENT]      = Comment;

    keyword[SCALL]         = Identifier;

    keyword[SDO]           = Statement;
    keyword[SENDDO]        = Statement;
    keyword[SLOGIF]        = Statement;
    keyword[SENDIF]        = Statement;
    keyword[SELSEIF]       = Statement;
    keyword[SELSE]         = Statement;
    keyword[STHEN]         = Statement;
    keyword[SEQUALS]       = Statement;
    keyword[SCONTINUE]     = Statement;
    keyword[SSTOP]         = Statement;
    keyword[SFORMAT]       = Statement;
    keyword[SREAD]         = Statement;
    keyword[SOPEN]         = Statement;
    keyword[SWRITE]        = Statement;
    keyword[SNE]           = Statement;
    keyword[SOR]           = Statement;
    keyword[SAND]          = Statement;
    keyword[SEQ]           = Statement;
    keyword[SLT]           = Statement;
    keyword[SLE]           = Statement;
    keyword[SGT]           = Statement;
    keyword[SGE]           = Statement;
    keyword[SNOT]          = Statement;
    keyword[SMINUS]        = Statement;
    keyword[SPLUS]         = Statement;
    keyword[SSTAR]         = Statement;
    keyword[SSLASH]        = Statement;
    keyword[SRETURN]       = Statement;
    keyword[SGOTO]         = Statement;

    keyword[STRUE]         = Constant;
    keyword[SFALSE]        = Constant;
    keyword[SICON]         = Constant;
    keyword[SRCON]         = Constant;
    keyword[SDCON]         = Constant;
    keyword[SBITCON]       = Constant;
    keyword[SOCTCON]       = Constant;
    keyword[SHEXCON]       = Constant;

    keyword[SHOLLERITH]    = String;

    keyword[SPROGRAM]      = UnitStatement;
    keyword[SSUBROUTINE]   = UnitStatement;
    keyword[SRECURSIVE]    = UnitStatement;
    keyword[SEND]          = UnitStatement;

    keyword[SCOMMON]       = Type;
    keyword[SDATA]         = Type;
    keyword[SIMPLICIT]     = Type;
    keyword[SIMPLICITNONE] = Type;
    keyword[SINTEGER]      = Type;
    keyword[SCHARACTER]    = Type;
    keyword[SDOUBLE]       = Type;
    keyword[SDCOMPLEX]     = Type;
    keyword[SREAL]         = Type;
    keyword[SCOMPLEX]      = Type;
    keyword[SLOGICAL]      = Type;
    keyword[SPARAM]        = Type;
    keyword[SEXTERNAL]     = Type;
    keyword[SINTRINSIC]    = Type;
}

bool
isHighlighted(int tokenId)
{
    return keyword[tokenId] != Void;
}

const std::string &
getHighlightTag(int tokenId)
{
    return tag[keyword[tokenId]];
}
