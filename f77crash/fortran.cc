/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 127 "fortran.y"


#ifdef DEBUG
#   define YYDEBUG 1
#endif

#define NOEXT(x)

#include <iostream>
#include <f77crash/crossrefs.h>
#include <f77crash/cursor.h>
#include <f77crash/lex.h>


/* Line 371 of yacc.c  */
#line 83 "fortran.cc"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "fortran.h".  */
#ifndef YY_YY_FORTRAN_H_INCLUDED
# define YY_YY_FORTRAN_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     SEOF = 0,
     SEOS = 1,
     SCOMMENT = 2,
     SLABEL = 3,
     SUNKNOWN = 4,
     SHOLLERITH = 5,
     SICON = 6,
     SRCON = 7,
     SDCON = 8,
     SBITCON = 9,
     SOCTCON = 10,
     SHEXCON = 11,
     STRUE = 12,
     SFALSE = 13,
     SNAME = 14,
     SNAMEEQ = 15,
     SFIELD = 16,
     SSCALE = 17,
     SINCLUDE = 18,
     SLET = 19,
     SASSIGN = 20,
     SAUTOMATIC = 21,
     SBACKSPACE = 22,
     SBLOCK = 23,
     SCALL = 24,
     SCHARACTER = 25,
     SCLOSE = 26,
     SCOMMON = 27,
     SCOMPLEX = 28,
     SCONTINUE = 29,
     SDATA = 30,
     SDCOMPLEX = 31,
     SDIMENSION = 32,
     SDO = 33,
     SDOUBLE = 34,
     SELSE = 35,
     SELSEIF = 36,
     SEND = 37,
     SENDFILE = 38,
     SENDIF = 39,
     SENTRY = 40,
     SEQUIV = 41,
     SEXTERNAL = 42,
     SFORMAT = 43,
     SFUNCTION = 44,
     SGOTO = 45,
     SASGOTO = 46,
     SCOMPGOTO = 47,
     SARITHIF = 48,
     SLOGIF = 49,
     SIMPLICIT = 50,
     SINQUIRE = 51,
     SINTEGER = 52,
     SINTRINSIC = 53,
     SLOGICAL = 54,
     SNAMELIST = 55,
     SOPEN = 56,
     SPARAM = 57,
     SPAUSE = 58,
     SPRINT = 59,
     SPROGRAM = 60,
     SPUNCH = 61,
     SREAD = 62,
     SREAL = 63,
     SRETURN = 64,
     SREWIND = 65,
     SSAVE = 66,
     SSTATIC = 67,
     SSTOP = 68,
     SSUBROUTINE = 69,
     STHEN = 70,
     STO = 71,
     SUNDEFINED = 72,
     SWRITE = 73,
     SLPAR = 74,
     SRPAR = 75,
     SEQUALS = 76,
     SCOLON = 77,
     SCOMMA = 78,
     SCURRENCY = 79,
     SPLUS = 80,
     SMINUS = 81,
     SSTAR = 82,
     SSLASH = 83,
     SPOWER = 84,
     SCONCAT = 85,
     SAND = 86,
     SOR = 87,
     SNEQV = 88,
     SEQV = 89,
     SNOT = 90,
     SEQ = 91,
     SLT = 92,
     SGT = 93,
     SLE = 94,
     SGE = 95,
     SNE = 96,
     SENDDO = 97,
     SWHILE = 98,
     SSLASHD = 99,
     SBYTE = 100,
     SRECURSIVE = 101,
     SIMPLICITNONE = 102
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 144 "fortran.y"

        int           ival;
        char          *sval;
        const Cursor  *curs;
        

/* Line 387 of yacc.c  */
#line 238 "fortran.cc"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_FORTRAN_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 266 "fortran.cc"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1424

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  105
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  119
/* YYNRULES -- Number of rules.  */
#define YYNRULES  309
/* YYNRULES -- Number of states.  */
#define YYNSTATES  554

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   257

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     8,    11,    14,    17,    21,    25,
      28,    30,    32,    36,    41,    45,    50,    55,    60,    66,
      70,    71,    73,    75,    76,    78,    81,    85,    87,    91,
      93,    97,    98,   101,   105,   107,   111,   113,   115,   117,
     119,   121,   123,   125,   127,   129,   131,   133,   135,   138,
     140,   146,   154,   160,   166,   167,   170,   172,   174,   176,
     178,   180,   182,   184,   186,   188,   190,   192,   194,   196,
     197,   201,   206,   213,   217,   222,   228,   232,   234,   238,
     242,   246,   250,   254,   258,   262,   266,   268,   272,   276,
     280,   281,   288,   289,   290,   291,   294,   298,   300,   304,
     306,   309,   311,   313,   317,   319,   321,   323,   327,   331,
     334,   336,   342,   344,   348,   349,   353,   354,   357,   361,
     363,   367,   369,   371,   373,   377,   379,   383,   387,   389,
     394,   396,   397,   400,   402,   406,   408,   412,   414,   416,
     419,   424,   426,   430,   431,   432,   434,   436,   440,   442,
     446,   448,   450,   452,   456,   460,   464,   468,   471,   475,
     479,   483,   487,   491,   494,   498,   500,   502,   504,   506,
     508,   510,   512,   514,   516,   519,   524,   530,   536,   537,
     539,   541,   543,   545,   547,   549,   551,   553,   555,   557,
     563,   565,   567,   569,   571,   575,   577,   579,   583,   587,
     591,   595,   598,   602,   604,   610,   615,   617,   620,   623,
     624,   632,   635,   638,   640,   646,   650,   652,   653,   659,
     664,   670,   673,   675,   677,   688,   690,   694,   699,   703,
     707,   709,   711,   715,   719,   727,   735,   736,   738,   742,
     744,   748,   750,   753,   755,   757,   759,   763,   764,   765,
     766,   768,   771,   774,   777,   780,   783,   786,   789,   793,
     798,   803,   806,   810,   815,   817,   821,   825,   827,   829,
     831,   835,   837,   839,   841,   843,   845,   849,   853,   855,
     859,   861,   863,   865,   868,   871,   874,   876,   880,   884,
     889,   894,   896,   900,   902,   908,   910,   912,   914,   918,
     922,   926,   930,   934,   938,   940,   944,   950,   956,   962
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     106,     0,    -1,    -1,   106,   107,     3,    -1,   108,   109,
      -1,   108,   121,    -1,   108,   184,    -1,   108,    20,   120,
      -1,   108,    39,   201,    -1,   108,     6,    -1,     1,    -1,
       5,    -1,    62,   110,   113,    -1,    62,   110,   113,   114,
      -1,    25,   110,   113,    -1,    71,   110,   111,   117,    -1,
     103,   110,   111,   117,    -1,    46,   110,   111,   117,    -1,
     124,    46,   110,   111,   117,    -1,    42,   111,   117,    -1,
      -1,   112,    -1,    16,    -1,    -1,   111,    -1,    76,    77,
      -1,    76,   115,    77,    -1,   116,    -1,   115,    80,   116,
      -1,    16,    -1,    16,    78,    16,    -1,    -1,    76,    77,
      -1,    76,   118,    77,    -1,   119,    -1,   118,    80,   119,
      -1,   112,    -1,    84,    -1,     7,    -1,   122,    -1,   128,
      -1,   130,    -1,   131,    -1,   132,    -1,   135,    -1,   158,
      -1,   165,    -1,    68,    -1,    68,   144,    -1,    45,    -1,
      59,   168,    76,   146,    77,    -1,   124,   195,   112,   168,
     123,   151,   127,    -1,   122,    80,   112,   151,   127,    -1,
     122,   101,   138,   140,   101,    -1,    -1,   125,   127,    -1,
     126,    -1,    54,    -1,    65,    -1,    30,    -1,    36,    -1,
      33,    -1,    56,    -1,    27,    -1,    74,    -1,    34,    -1,
      23,    -1,    69,    -1,   102,    -1,    -1,    76,   171,    77,
      -1,    84,   202,   171,   203,    -1,    84,   202,    76,    84,
      77,   203,    -1,    29,   168,   148,    -1,    29,   168,   129,
     148,    -1,   128,   195,   129,   195,   148,    -1,   128,    80,
     148,    -1,    87,    -1,    85,    16,    85,    -1,    44,   168,
     112,    -1,   130,    80,   112,    -1,    55,   168,   112,    -1,
     131,    80,   112,    -1,    43,   168,   133,    -1,   132,    80,
     133,    -1,    76,   134,    77,    -1,   175,    -1,   134,    80,
     175,    -1,    32,   136,   137,    -1,   135,   195,   137,    -1,
      -1,   138,   150,    85,   139,   140,    85,    -1,    -1,    -1,
      -1,   141,   142,    -1,   140,    80,   142,    -1,   143,    -1,
     178,    84,   143,    -1,   178,    -1,   173,   178,    -1,   180,
      -1,   145,    -1,   144,    80,   145,    -1,   112,    -1,   129,
      -1,   147,    -1,   146,    80,   147,    -1,   112,    78,   171,
      -1,   112,   151,    -1,   175,    -1,    76,   150,    80,   188,
      77,    -1,   149,    -1,   150,    80,   149,    -1,    -1,    76,
     152,    77,    -1,    -1,   153,   154,    -1,   152,    80,   154,
      -1,   155,    -1,   171,    79,   155,    -1,    84,    -1,   171,
      -1,   157,    -1,   156,    80,   157,    -1,     8,    -1,    52,
     168,   159,    -1,   158,    80,   159,    -1,   104,    -1,   160,
      76,   162,    77,    -1,   160,    -1,    -1,   161,   124,    -1,
     163,    -1,   162,    80,   163,    -1,   164,    -1,   164,    83,
     164,    -1,    16,    -1,    57,    -1,   165,   166,    -1,    85,
     112,    85,   167,    -1,   112,    -1,   167,    80,   112,    -1,
      -1,    -1,   170,    -1,   171,    -1,   170,    80,   171,    -1,
     172,    -1,    76,   171,    77,    -1,   180,    -1,   175,    -1,
     179,    -1,   171,   173,   171,    -1,   171,    84,   171,    -1,
     171,    85,   171,    -1,   171,    86,   171,    -1,   173,   171,
      -1,   171,   174,   171,    -1,   171,    91,   171,    -1,   171,
      90,   171,    -1,   171,    89,   171,    -1,   171,    88,   171,
      -1,    92,   171,    -1,   171,    87,   171,    -1,    82,    -1,
      83,    -1,    93,    -1,    95,    -1,    94,    -1,    97,    -1,
      96,    -1,    98,    -1,   112,    -1,   112,   176,    -1,   112,
      76,   169,    77,    -1,   112,    76,   169,    77,   176,    -1,
      76,   177,    79,   177,    77,    -1,    -1,   171,    -1,   112,
      -1,   179,    -1,    14,    -1,    15,    -1,     7,    -1,     8,
      -1,     9,    -1,    10,    -1,   181,    -1,    76,   172,    80,
     172,    77,    -1,    13,    -1,    12,    -1,    11,    -1,   183,
      -1,    76,   182,    77,    -1,   175,    -1,   179,    -1,   182,
     173,   182,    -1,   182,    84,   182,    -1,   182,    85,   182,
      -1,   182,    86,   182,    -1,   173,   182,    -1,   182,    87,
     182,    -1,   191,    -1,   186,   201,   157,   195,   189,    -1,
     186,   201,   195,   189,    -1,    99,    -1,   187,   191,    -1,
     187,    72,    -1,    -1,    38,   201,    76,   185,   171,    77,
      72,    -1,    37,   201,    -1,    41,   201,    -1,    35,    -1,
      51,   201,    76,   171,    77,    -1,   112,    78,   200,    -1,
     188,    -1,    -1,   100,   190,    76,   171,    77,    -1,   193,
     175,    78,   171,    -1,    22,   201,   192,    73,   112,    -1,
      31,   201,    -1,   194,    -1,   204,    -1,    50,   201,    76,
     171,    77,   157,    80,   157,    80,   157,    -1,   196,    -1,
     196,    76,    77,    -1,   196,    76,   197,    77,    -1,    66,
     201,   177,    -1,   199,   201,   177,    -1,     8,    -1,    21,
      -1,    47,   201,   157,    -1,    48,   201,   112,    -1,    48,
     201,   112,   195,    76,   156,    77,    -1,    49,   201,    76,
     156,    77,   195,   171,    -1,    -1,    80,    -1,    26,   201,
     112,    -1,   198,    -1,   197,    80,   198,    -1,   171,    -1,
      84,   157,    -1,    60,    -1,    70,    -1,   171,    -1,   200,
      80,   171,    -1,    -1,    -1,    -1,   205,    -1,   206,   211,
      -1,   206,   183,    -1,   206,    84,    -1,   206,    86,    -1,
     208,   211,    -1,   215,   211,    -1,   215,   210,    -1,   215,
     211,   218,    -1,   215,   210,    80,   218,    -1,   215,   211,
      80,   218,    -1,   216,   211,    -1,   216,   211,   220,    -1,
     216,   211,    80,   220,    -1,   217,    -1,   217,    80,   220,
      -1,   207,   201,   223,    -1,    24,    -1,    67,    -1,    40,
      -1,   209,   201,   223,    -1,    53,    -1,    58,    -1,    28,
      -1,   183,    -1,    84,    -1,    76,   182,    77,    -1,    76,
     212,    77,    -1,   213,    -1,   212,    80,   213,    -1,   182,
      -1,    84,    -1,    86,    -1,   214,   171,    -1,   214,    84,
      -1,   214,    86,    -1,    17,    -1,    64,   201,   223,    -1,
      75,   201,   223,    -1,    61,   201,   182,   223,    -1,    61,
     201,    84,   223,    -1,   219,    -1,   218,    80,   219,    -1,
     175,    -1,    76,   218,    80,   188,    77,    -1,   172,    -1,
     222,    -1,   221,    -1,   172,    80,   172,    -1,   172,    80,
     222,    -1,   222,    80,   172,    -1,   222,    80,   222,    -1,
     221,    80,   172,    -1,   221,    80,   222,    -1,   180,    -1,
      76,   171,    77,    -1,    76,   172,    80,   188,    77,    -1,
      76,   222,    80,   188,    77,    -1,    76,   221,    80,   188,
      77,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   170,   170,   171,   174,   176,   177,   179,   181,   183,
     185,   189,   201,   206,   211,   213,   218,   223,   228,   233,
     238,   241,   247,   255,   258,   265,   266,   269,   270,   273,
     274,   278,   279,   281,   285,   287,   291,   295,   301,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   314,   316,
     320,   324,   331,   338,   343,   348,   354,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   375,
     377,   381,   384,   389,   391,   393,   395,   399,   401,   405,
     410,   417,   421,   427,   428,   431,   435,   437,   441,   442,
     446,   449,   453,   455,   457,   457,   458,   461,   463,   467,
     468,   470,   473,   474,   477,   479,   482,   483,   486,   490,
     494,   496,   500,   502,   507,   509,   514,   514,   515,   518,
     520,   524,   526,   529,   531,   535,   547,   549,   550,   553,
     554,   558,   558,   561,   562,   565,   567,   571,   575,   576,
     579,   583,   585,   590,   593,   594,   598,   600,   605,   606,
     607,   610,   611,   612,   614,   616,   618,   620,   622,   624,
     626,   628,   630,   632,   634,   638,   639,   642,   643,   644,
     645,   646,   647,   650,   652,   654,   656,   660,   665,   666,
     669,   671,   674,   675,   676,   677,   678,   679,   680,   683,
     687,   689,   691,   695,   696,   700,   701,   702,   704,   706,
     708,   710,   712,   716,   717,   721,   728,   734,   736,   737,
     737,   739,   741,   745,   753,   757,   761,   762,   762,   766,
     768,   770,   771,   772,   774,   776,   778,   780,   782,   784,
     788,   792,   797,   799,   801,   803,   807,   808,   811,   815,
     817,   821,   822,   826,   828,   832,   834,   839,   843,   847,
     851,   855,   856,   858,   860,   862,   863,   865,   867,   869,
     871,   873,   875,   877,   879,   881,   885,   888,   890,   892,
     896,   899,   901,   903,   907,   909,   913,   915,   919,   920,
     923,   925,   927,   929,   931,   933,   937,   941,   945,   949,
     951,   955,   957,   961,   963,   967,   969,   971,   974,   976,
     978,   980,   982,   984,   988,   990,   992,   994,   996,  1001
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "SEOF", "error", "$undefined", "SEOS", "SCOMMENT", "SLABEL", "SUNKNOWN",
  "SHOLLERITH", "SICON", "SRCON", "SDCON", "SBITCON", "SOCTCON", "SHEXCON",
  "STRUE", "SFALSE", "SNAME", "SNAMEEQ", "SFIELD", "SSCALE", "SINCLUDE",
  "SLET", "SASSIGN", "SAUTOMATIC", "SBACKSPACE", "SBLOCK", "SCALL",
  "SCHARACTER", "SCLOSE", "SCOMMON", "SCOMPLEX", "SCONTINUE", "SDATA",
  "SDCOMPLEX", "SDIMENSION", "SDO", "SDOUBLE", "SELSE", "SELSEIF", "SEND",
  "SENDFILE", "SENDIF", "SENTRY", "SEQUIV", "SEXTERNAL", "SFORMAT",
  "SFUNCTION", "SGOTO", "SASGOTO", "SCOMPGOTO", "SARITHIF", "SLOGIF",
  "SIMPLICIT", "SINQUIRE", "SINTEGER", "SINTRINSIC", "SLOGICAL",
  "SNAMELIST", "SOPEN", "SPARAM", "SPAUSE", "SPRINT", "SPROGRAM", "SPUNCH",
  "SREAD", "SREAL", "SRETURN", "SREWIND", "SSAVE", "SSTATIC", "SSTOP",
  "SSUBROUTINE", "STHEN", "STO", "SUNDEFINED", "SWRITE", "SLPAR", "SRPAR",
  "SEQUALS", "SCOLON", "SCOMMA", "SCURRENCY", "SPLUS", "SMINUS", "SSTAR",
  "SSLASH", "SPOWER", "SCONCAT", "SAND", "SOR", "SNEQV", "SEQV", "SNOT",
  "SEQ", "SLT", "SGT", "SLE", "SGE", "SNE", "SENDDO", "SWHILE", "SSLASHD",
  "SBYTE", "SRECURSIVE", "SIMPLICITNONE", "$accept", "program", "stat",
  "thislabel", "entry", "new_proc", "entryname", "name", "progname",
  "progarglist", "progargs", "progarg", "arglist", "args", "arg",
  "filename", "spec", "dcl", "new_dcl", "type", "typespec", "typename",
  "lengspec", "common", "comblock", "external", "intrinsic", "equivalence",
  "equivset", "equivlist", "data", "in_data", "datalist", "datainit",
  "datapop", "vallist", "$@1", "val", "value", "savelist", "saveitem",
  "paramlist", "paramitem", "var", "datavar", "datavarlist", "dims",
  "dimlist", "$@2", "dim", "ubound", "labellist", "label", "implicit",
  "implist", "imptype", "$@3", "letgroups", "letgroup", "letter",
  "namelist", "namelistentry", "namelistlist", "in_dcl", "funarglist",
  "funargs", "expr", "uexpr", "addop", "relop", "lhs", "substring",
  "opt_expr", "simple", "simple_const", "complex_const", "bit_const",
  "fexpr", "unpar_fexpr", "exec", "$@4", "begin_do", "logif", "dospec",
  "dospecw", "$@5", "iffable", "assignlabel", "let", "goto", "opt_comma",
  "call", "callarglist", "callarg", "stop", "exprlist", "end_spec",
  "intonlyon", "intonlyoff", "io", "io1", "iofmove", "fmkwd", "iofctl",
  "ctlkwd", "infmt", "ioctl", "ctllist", "ioclause", "nameeq", "read",
  "write", "print", "inlist", "inelt", "outlist", "out2", "other",
  "in_ioctl", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   105,   106,   106,   107,   107,   107,   107,   107,   107,
     107,   108,   109,   109,   109,   109,   109,   109,   109,   109,
     110,   111,   112,   113,   113,   114,   114,   115,   115,   116,
     116,   117,   117,   117,   118,   118,   119,   119,   120,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   122,   122,   122,   123,   124,   125,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   127,
     127,   127,   127,   128,   128,   128,   128,   129,   129,   130,
     130,   131,   131,   132,   132,   133,   134,   134,   135,   135,
     136,   137,   138,   139,   141,   140,   140,   142,   142,   143,
     143,   143,   144,   144,   145,   145,   146,   146,   147,   148,
     149,   149,   150,   150,   151,   151,   153,   152,   152,   154,
     154,   155,   155,   156,   156,   157,   158,   158,   158,   159,
     159,   161,   160,   162,   162,   163,   163,   164,   165,   165,
     166,   167,   167,   168,   169,   169,   170,   170,   171,   171,
     171,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   173,   173,   174,   174,   174,
     174,   174,   174,   175,   175,   175,   175,   176,   177,   177,
     178,   178,   179,   179,   179,   179,   179,   179,   179,   180,
     181,   181,   181,   182,   182,   183,   183,   183,   183,   183,
     183,   183,   183,   184,   184,   184,   184,   184,   184,   185,
     184,   184,   184,   186,   187,   188,   189,   190,   189,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     192,   193,   194,   194,   194,   194,   195,   195,   196,   197,
     197,   198,   198,   199,   199,   200,   200,   201,   202,   203,
     204,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   206,   207,   207,   207,
     208,   209,   209,   209,   210,   210,   211,   211,   212,   212,
     213,   213,   213,   213,   213,   213,   214,   215,   216,   217,
     217,   218,   218,   219,   219,   220,   220,   220,   221,   221,
     221,   221,   221,   221,   222,   222,   222,   222,   222,   223
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     3,     2,     2,     2,     3,     3,     2,
       1,     1,     3,     4,     3,     4,     4,     4,     5,     3,
       0,     1,     1,     0,     1,     2,     3,     1,     3,     1,
       3,     0,     2,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       5,     7,     5,     5,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       3,     4,     6,     3,     4,     5,     3,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     3,     3,     3,
       0,     6,     0,     0,     0,     2,     3,     1,     3,     1,
       2,     1,     1,     3,     1,     1,     1,     3,     3,     2,
       1,     5,     1,     3,     0,     3,     0,     2,     3,     1,
       3,     1,     1,     1,     3,     1,     3,     3,     1,     4,
       1,     0,     2,     1,     3,     1,     3,     1,     1,     2,
       4,     1,     3,     0,     0,     1,     1,     3,     1,     3,
       1,     1,     1,     3,     3,     3,     3,     2,     3,     3,
       3,     3,     3,     2,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     4,     5,     5,     0,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       1,     1,     1,     1,     3,     1,     1,     3,     3,     3,
       3,     2,     3,     1,     5,     4,     1,     2,     2,     0,
       7,     2,     2,     1,     5,     3,     1,     0,     5,     4,
       5,     2,     1,     1,    10,     1,     3,     4,     3,     3,
       1,     1,     3,     3,     7,     7,     0,     1,     3,     1,
       3,     1,     2,     1,     1,     1,     3,     0,     0,     0,
       1,     2,     2,     2,     2,     2,     2,     2,     3,     4,
       4,     2,     3,     4,     1,     3,     3,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     3,     3,     1,     3,
       1,     1,     1,     2,     2,     2,     1,     3,     3,     4,
       4,     1,     3,     1,     5,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     1,     3,     5,     5,     5,     0
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,    10,    11,     0,     0,     3,     9,     0,
     231,   247,    66,   267,    20,   247,    63,   273,   143,    59,
     247,    90,    61,    65,   213,    60,   247,   247,   247,   269,
     247,     0,   143,   143,    49,    20,   247,   247,   247,   247,
     247,   143,   271,    57,   143,    62,   138,   272,   143,   243,
     247,    20,   247,    58,   247,   268,    47,    67,   244,    20,
      64,   247,   206,    68,    20,   128,     4,     5,    39,   236,
      69,    56,   236,    41,    42,    43,   236,    45,    46,     6,
     247,     0,   203,     0,   222,   225,   247,   223,   250,     0,
     247,     0,   247,     0,     0,   264,    38,     7,     0,    23,
       0,     0,   221,    92,   211,     0,     8,   212,    22,    31,
      21,     0,     0,     0,     0,     0,     0,     0,     0,   131,
       0,     0,     0,    23,   309,   178,     0,    77,   104,   105,
      48,   102,     0,   309,     0,     0,    92,    20,   237,     0,
       0,   248,    55,   237,     0,     0,     0,     0,    92,   131,
       0,   139,   236,   208,   207,   173,     0,     0,   178,   184,
     185,   186,   187,   192,   191,   190,   182,   183,     0,   165,
     166,   253,   254,     0,   195,   196,   188,     0,   193,   251,
     309,     0,   255,   309,   275,   193,   257,   256,   261,     0,
     230,     0,    24,    14,   238,   114,     0,    73,    88,     0,
     209,     0,    19,     0,    83,    79,    31,   125,   232,   233,
       0,     0,     0,   126,   130,     0,    81,     0,     0,   309,
     309,   193,    12,   287,     0,     0,   179,   148,     0,   151,
     228,   152,   150,     0,     0,    31,   288,    31,   114,    94,
       0,   143,     0,     0,    76,   236,    80,    82,    84,    89,
     127,     0,   236,     0,   144,   174,     0,   226,     0,   241,
       0,   239,   229,   286,   281,   282,   280,     0,   278,     0,
     201,     0,     0,     0,     0,     0,   266,   280,   270,     0,
       0,     0,   293,   258,   291,     0,     0,     0,   148,   150,
     262,   297,   296,   265,     0,   116,   109,    74,     0,   112,
       0,   110,     0,    32,    37,    36,     0,    34,     0,    86,
      17,     0,     0,   123,     0,     0,     0,   132,     0,     0,
     106,     0,   290,   289,     0,    13,     0,   148,   163,     0,
       0,     0,     0,     0,     0,     0,     0,   167,   169,   168,
     171,   170,   172,     0,     0,   157,    78,   103,    15,    16,
      69,     0,     0,    31,    54,    70,     0,   249,     0,     0,
       0,   217,     0,   216,   205,     0,   145,   146,     0,   219,
     242,   227,     0,   194,   277,     0,   284,   285,   283,   198,
     199,   200,   202,   197,   276,   259,     0,   260,     0,     0,
     148,     0,     0,   263,     0,     0,     0,   220,     0,     0,
       0,     0,    93,     0,    33,     0,    85,     0,     0,   236,
       0,     0,   214,   137,     0,   133,   135,     0,    50,     0,
     194,    29,    25,     0,    27,   149,     0,   154,   155,   156,
     164,   162,   161,   160,   159,   153,   158,    52,     0,    53,
       0,   180,    95,    97,     0,    99,   181,   101,    18,   114,
       0,    71,    75,   141,   140,   204,     0,     0,   175,     0,
     178,   240,   280,   279,     0,   292,   149,     0,     0,     0,
     148,   299,   148,   303,   148,   301,   115,     0,   121,   117,
     119,   122,     0,   113,    94,     0,    35,    87,     0,     0,
     124,     0,   129,     0,     0,   108,   107,     0,    26,     0,
     148,    96,   100,     0,    69,   249,     0,     0,   245,   215,
     178,   176,   147,     0,   173,     0,   148,     0,     0,     0,
     118,     0,     0,     0,   210,   234,   235,     0,   134,   136,
      30,    28,   189,    98,    99,    51,    72,   142,     0,     0,
     177,   294,   306,   308,   307,   120,   122,   111,    91,     0,
     218,   246,     0,   224
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     5,     6,    66,    99,   192,   155,   193,   325,
     423,   424,   202,   306,   307,    97,    67,    68,   449,    69,
      70,    71,   142,    72,   129,    73,    74,    75,   204,   308,
      76,   103,   198,   199,   484,   351,   352,   442,   443,   130,
     131,   319,   320,   197,   299,   300,   296,   398,   399,   479,
     480,   312,   313,    77,   213,   214,   215,   414,   415,   416,
      78,   151,   454,   101,   365,   366,   287,   227,   228,   344,
     229,   255,   368,   445,   231,   232,   176,   177,   221,    79,
     302,    80,    81,   363,   364,   456,    82,   191,    83,    84,
     139,    85,   260,   261,    86,   509,    98,   243,   451,    87,
      88,    89,    90,    91,    92,   186,   179,   267,   268,   269,
      93,    94,    95,   283,   284,   290,   291,   292,   223
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -428
static const yytype_int16 yypact[] =
{
    -428,    78,  -428,  -428,  -428,    19,   775,  -428,  -428,    42,
    -428,  -428,  -428,  -428,  -428,  -428,  -428,  -428,  -428,  -428,
    -428,  -428,  -428,  -428,  -428,  -428,  -428,  -428,  -428,  -428,
    -428,    26,  -428,  -428,  -428,  -428,  -428,  -428,  -428,  -428,
    -428,  -428,  -428,  -428,  -428,  -428,  -428,  -428,  -428,  -428,
    -428,  -428,  -428,  -428,  -428,  -428,    35,  -428,  -428,  -428,
    -428,  -428,  -428,  -428,  -428,  -428,  -428,  -428,   -43,    -5,
     -24,  -428,     8,   -32,   -25,   -14,    16,    25,     6,  -428,
    -428,  1109,  -428,    26,  -428,    54,  -428,  -428,  -428,   917,
    -428,    55,  -428,   931,    55,    36,  -428,  -428,   158,    26,
      26,    35,  -428,  -428,  -428,    92,  -428,  -428,  -428,    96,
    -428,   102,    26,    26,   171,    26,   108,   109,   123,  -428,
      26,   136,  1037,    26,  -428,   873,   194,  -428,  -428,  -428,
     144,  -428,    26,  -428,    26,    26,  -428,  -428,  -428,    26,
     873,  -428,  -428,    26,   232,    26,    26,   102,  -428,  -428,
      26,  -428,    27,  -428,  -428,   149,   155,   537,   873,  -428,
    -428,  -428,  -428,  -428,  -428,  -428,  -428,  -428,   906,  -428,
    -428,  -428,  -428,  1068,  -428,  -428,  -428,   255,   248,  -428,
    -428,   906,  -428,  -428,  -428,    30,   172,    95,   626,   884,
    -428,   183,  -428,  -428,  -428,   181,    26,  -428,  -428,    71,
    -428,    -4,  -428,    26,  -428,  -428,    96,  -428,  -428,    84,
     171,   873,   873,  -428,   189,   214,  -428,    26,  1068,  -428,
     255,  -428,   211,  -428,   873,   873,  1013,  -428,   873,  -428,
    -428,  -428,  -428,   186,    35,    96,  -428,    96,   181,  -428,
      26,  -428,  1103,   895,  -428,   197,  -428,  -428,  -428,  -428,
    -428,   208,   197,    -7,   644,  -428,   873,  -428,   171,  1013,
      81,  -428,  -428,  -428,  -428,  -428,   277,    97,  -428,   512,
     215,  1068,  1068,  1068,  1068,  1068,  -428,   298,  -428,   125,
     125,   125,  -428,   222,  -428,   884,   884,  1013,    44,    47,
    -428,   230,   238,  -428,    26,  -428,  -428,  -428,    71,  -428,
     -13,  -428,   873,  -428,  -428,  -428,   134,  -428,   139,  -428,
    -428,   218,   162,  -428,  1125,  1147,   315,  -428,   257,   169,
    -428,   421,  -428,  -428,    -3,  -428,  1169,   263,   944,   873,
     873,   873,   873,   873,   873,   873,   873,  -428,  -428,  -428,
    -428,  -428,  -428,   873,   873,   270,  -428,  -428,  -428,  -428,
     -24,    68,  1078,    96,  -428,  -428,   655,  1013,    26,    26,
      -7,  -428,   294,  -428,  -428,   299,   297,  1255,   307,  1013,
    -428,  -428,   666,    41,  -428,   906,  -428,  -428,  1013,   215,
     215,   215,   240,   281,  -428,   222,   309,   222,   125,  1191,
     313,   314,   316,  -428,   884,   884,   884,  -428,   187,   776,
     317,    71,  -428,  1213,  -428,    11,  -428,    26,   171,   197,
     171,   171,  -428,  -428,   195,  -428,   295,   873,  -428,    26,
    -428,   321,  -428,   196,  -428,  -428,   873,   270,   270,   270,
     454,   944,  1309,  1292,  1292,   285,  1326,  -428,  1078,  -428,
     873,  -428,  -428,  -428,   752,   303,  -428,  -428,  -428,   181,
     323,  -428,  -428,  -428,   322,  -428,   327,   873,   328,   873,
     873,  -428,   255,  -428,   125,  -428,    58,   884,   884,   884,
      59,  -428,    60,  -428,    62,  -428,  -428,   776,  -428,  -428,
    -428,  1275,    71,  -428,  -428,   334,  -428,  -428,   201,   873,
    -428,   329,  -428,   315,   315,  1013,  -428,   392,  -428,   394,
     337,  -428,  -428,  1078,   -24,  -428,    26,   873,  1013,   331,
     873,  -428,  1013,   339,    77,   340,   205,   341,   342,   345,
    -428,   776,   346,    64,  -428,  -428,  1013,   171,  -428,  -428,
    -428,  -428,  -428,  -428,  -428,  -428,  -428,  -428,  1235,   873,
    -428,  -428,  -428,  -428,  -428,  -428,  1013,  -428,  -428,   344,
    -428,  1013,   171,  -428
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -428,  -428,  -428,  -428,  -428,   -19,     0,   -31,   304,  -428,
    -428,   -73,  -199,  -428,    23,  -428,  -428,  -428,  -428,   216,
    -428,  -428,  -348,  -428,   -58,  -428,  -428,  -428,   283,  -428,
    -428,  -428,   284,   305,  -428,   -49,  -428,     1,   -63,  -428,
     213,  -428,    29,  -140,  -383,   151,  -234,  -428,  -428,   -35,
     -71,    45,  -106,  -428,   310,  -428,  -428,  -428,   -41,   -40,
    -428,  -428,  -428,   -18,  -428,  -428,   233,  -160,   -83,  -428,
     312,    -2,  -124,  -427,    40,  -135,  -428,   -45,    74,  -428,
    -428,  -428,  -428,  -262,   100,  -428,   381,  -428,  -428,  -428,
     -52,  -428,  -428,    93,  -428,  -428,   982,  -428,   -39,  -428,
    -428,  -428,  -428,  -428,  -428,  -428,   104,  -428,    89,  -428,
    -428,  -428,  -428,    10,  -367,  -184,   182,  -214,   -74
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -306
static const yytype_int16 yytable[] =
{
     110,   230,   437,   244,   350,   293,   173,   310,   208,   108,
     173,   -40,   108,   421,   111,   112,   113,   502,   483,   -44,
     144,   465,     7,   119,   148,   128,   120,   108,   288,   288,
     121,   109,   123,  -274,   262,   207,   348,   135,   349,   173,
     132,   137,   108,   196,  -276,   134,   252,  -295,   145,    96,
    -304,   108,   140,   289,   289,   146,   297,  -276,   136,   236,
     141,  -305,  -298,  -302,   327,  -300,   147,   401,   110,   194,
     195,   392,   402,   303,   422,   138,   534,   220,     2,     3,
     304,   205,   110,     4,   209,   173,   245,   108,   143,   216,
     173,   150,   110,   361,   275,   304,   138,   465,   173,   483,
     253,   110,   393,   110,   238,   149,   276,   138,   241,   278,
    -274,   108,   195,   206,   246,   247,   189,  -276,   240,   251,
     126,  -276,   127,   266,   394,   390,   288,  -304,   270,   175,
     157,   181,   235,   175,   237,   173,   277,   275,  -305,  -298,
    -302,   108,  -300,   343,   438,   322,   323,   298,   438,   548,
     289,   289,   370,   254,   448,   457,   535,   311,   371,   343,
    -236,   372,   175,   178,   138,   195,   190,   185,   200,   439,
     305,   280,   201,   321,   374,   281,   343,   375,   203,   207,
     471,   473,   475,   275,   210,   211,   318,   275,   173,   173,
     173,   173,   173,   358,   275,   182,   327,   187,   188,   212,
     360,   280,   515,   128,   343,   517,   518,   519,   175,   110,
     233,   404,   217,   175,   405,   504,   406,   447,   452,   407,
     522,   175,   362,   354,   234,   254,   379,   380,   381,   382,
     383,   343,   343,   256,   470,   472,   474,    12,   275,   409,
     353,    16,   410,   343,    19,   343,   418,    22,    23,   419,
      25,  -252,   279,   471,   473,   475,   294,   295,   175,   289,
     289,   289,   343,   397,   476,   316,   500,   477,    43,   444,
      45,   346,   492,   498,   343,   493,   499,   138,   525,    53,
     327,   410,   532,    57,   343,  -298,   343,   324,    60,   385,
     386,   387,   173,   359,   408,   343,   275,   275,   275,   275,
     275,   273,   388,   447,   490,   491,   343,   516,   472,   474,
     395,   175,   175,   175,   175,   175,    63,   126,   396,   127,
     343,   441,   169,   170,   271,   272,   273,   195,   453,   362,
     462,   413,   289,   289,   289,   417,   513,   169,   170,   271,
     272,   273,   274,   426,   343,   343,   343,   343,   343,   343,
     343,   343,   343,   343,   373,   444,   331,   489,   226,   169,
     170,   271,   272,   273,   274,   271,   272,   273,   447,   329,
     330,   331,   457,   242,   305,   384,   458,   459,   494,   275,
     169,   170,   271,   272,   273,   274,   460,   503,   318,   464,
     259,   226,   446,   467,   468,   156,   469,   482,   343,   497,
     505,   174,   506,   507,   510,   174,   524,   441,   530,   527,
     421,   539,   343,   441,   532,   175,   540,   541,   542,   543,
     444,   549,   544,   547,   552,   343,   531,   222,   486,   343,
     248,   317,   249,   514,   174,   523,   514,   514,   514,   501,
     533,   239,   520,   343,   314,   315,   553,   347,   496,   400,
     545,   514,   528,   488,   529,   343,   511,   326,   328,   250,
     455,   345,   154,   343,   463,   461,   536,   391,   343,     0,
       0,     0,   441,     0,     0,   537,   357,     0,   446,     0,
     174,     0,     0,     0,   446,   174,     0,   367,     0,   369,
       0,     0,     0,   174,     0,     0,     0,     0,   420,   282,
       0,     0,   378,   169,   170,   271,   272,   273,   274,     0,
       0,   301,     0,     0,     0,   309,     0,     0,   389,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   108,     0,
     174,     0,     0,     0,     0,   403,   169,   170,   329,   330,
     331,     0,     0,   446,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   108,     0,     0,     0,     0,     0,     0,
       0,     0,   427,   428,   429,   430,   431,   432,   433,   434,
       0,     0,     0,     0,     0,     0,   435,   436,     0,     0,
       0,     0,     0,   174,   174,   174,   174,   174,   224,   326,
       0,   282,   282,   282,   169,   170,   376,     0,   377,     0,
       0,     0,     0,     0,   225,   259,     0,     0,     0,     0,
     301,     0,     0,   224,   257,     0,     0,     0,     0,   169,
     170,   258,     0,     0,     0,     0,     0,     0,     0,   225,
       0,     0,   481,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   108,     0,     0,     0,     0,     0,     0,     0,
     495,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     108,     0,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   108,     0,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   108,     0,     0,     0,     0,   174,     0,     0,
     508,     0,   512,   226,     0,     0,     0,     0,     0,     0,
     282,     0,   285,     0,     0,     0,   286,     0,   169,   170,
     481,     0,     0,   301,     0,     0,     0,     0,   225,   487,
     224,     0,   526,  -178,     0,     0,   169,   170,     0,     0,
       0,   224,     0,     0,     0,     0,   225,   169,   170,   450,
     538,     0,   224,   226,     0,     0,     0,   225,   169,   170,
     258,     0,     0,     0,   546,     0,     0,     0,   225,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   108,     0,
       0,     0,   551,     0,     0,     0,   282,     0,     0,     0,
       0,     8,     0,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   108,     0,   301,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,     0,    52,
      53,    54,    55,    56,    57,    58,    59,     0,     0,    60,
      61,     0,   224,     0,     0,     0,     0,     0,   169,   170,
     478,     0,     0,     0,     0,     0,     0,     0,   225,     0,
       0,     0,     0,     0,    62,     0,     0,    63,    64,    65,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   108,
       0,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     108,     0,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   108,     0,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   108,   263,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   108,     0,     0,     0,     0,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   108,     0,   224,
       0,     0,     0,     0,     0,   169,   170,     0,     0,     0,
     285,     0,     0,     0,     0,   225,   169,   170,     0,     0,
       0,   356,     0,     0,     0,     0,   225,   169,   170,     0,
       0,     0,   218,     0,     0,     0,     0,   225,   169,   170,
     264,     0,   265,   168,     0,     0,     0,   100,     0,   169,
     170,   171,   102,   172,     0,     0,     0,   168,   104,   105,
     106,     0,   107,   169,   170,   184,     0,     0,   114,   115,
     116,   117,   118,     0,     0,     0,   169,   170,   329,   330,
     331,   332,   122,     0,   124,     0,   125,   337,   338,   339,
     340,   341,   342,   133,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   108,     0,     0,     0,     0,     0,     0,
       0,     0,   152,     0,     0,     0,     0,     0,   158,     0,
       0,     0,   180,     0,   183,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   108,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   108,   169,   170,   329,   330,   331,
     332,   333,   334,   335,   336,     0,   337,   338,   339,   340,
     341,   342,     0,   218,     0,     0,     0,     0,     0,   169,
     170,   219,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    11,     0,    13,     0,    15,     0,    17,     0,     0,
      20,     0,     0,     0,   218,     0,     0,     0,     0,    29,
     169,   170,     0,     0,   440,     0,    36,    37,    38,    39,
     169,   170,    42,     0,     0,     0,     0,    47,     0,    49,
      50,     0,     0,    52,     0,    54,    55,     0,     0,    58,
     355,   153,     0,     0,    61,   169,   170,   329,   330,   331,
     332,   333,   334,   335,   336,     0,   337,   338,   339,   340,
     341,   342,   411,     0,     0,     0,     0,   169,   170,   329,
     330,   331,   332,   333,   334,   335,   336,     0,   337,   338,
     339,   340,   341,   342,   412,     0,     0,     0,     0,   169,
     170,   329,   330,   331,   332,   333,   334,   335,   336,     0,
     337,   338,   339,   340,   341,   342,   425,     0,     0,     0,
       0,   169,   170,   329,   330,   331,   332,   333,   334,   335,
     336,     0,   337,   338,   339,   340,   341,   342,   466,     0,
       0,     0,     0,   169,   170,   329,   330,   331,   332,   333,
     334,   335,   336,     0,   337,   338,   339,   340,   341,   342,
     485,     0,     0,     0,     0,   169,   170,   329,   330,   331,
     332,   333,   334,   335,   336,     0,   337,   338,   339,   340,
     341,   342,   550,     0,     0,     0,     0,   169,   170,   329,
     330,   331,   332,   333,   334,   335,   336,     0,   337,   338,
     339,   340,   341,   342,  -179,     0,     0,   169,   170,   329,
     330,   331,   332,   333,   334,   335,   336,     0,   337,   338,
     339,   340,   341,   342,   521,     0,     0,   169,   170,   329,
     330,   331,   332,   333,   334,   335,   336,     0,   337,   338,
     339,   340,   341,   342,   169,   170,   329,   330,   331,   332,
     333,   334,     0,     0,     0,   337,   338,   339,   340,   341,
     342,   169,   170,   329,   330,   331,   332,   333,     0,     0,
       0,     0,   337,   338,   339,   340,   341,   342,   169,   170,
     329,   330,   331,   332,     0,     0,     0,     0,     0,  -306,
    -306,  -306,  -306,  -306,  -306
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-428)))

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-306)))

static const yytype_int16 yycheck[] =
{
      31,   125,   350,   143,   238,   189,    89,   206,   114,    16,
      93,     3,    16,    16,    32,    33,    35,   444,   401,     3,
      72,   388,     3,    41,    76,    56,    44,    16,   188,   189,
      48,    31,    51,     3,   158,     8,   235,    80,   237,   122,
      59,    46,    16,   101,     3,    64,   152,     3,    80,     7,
       3,    16,    76,   188,   189,    80,   196,    16,   101,   133,
      84,     3,     3,     3,   224,     3,    80,    80,    99,   100,
     101,   285,    85,    77,    77,    80,   503,   122,     0,     1,
      84,   112,   113,     5,   115,   168,   144,    16,    80,   120,
     173,    85,   123,   100,   177,    84,    80,   464,   181,   482,
     152,   132,   286,   134,   135,    80,   180,    80,   139,   183,
      80,    16,   143,   113,   145,   146,    80,    76,   137,   150,
      85,    80,    87,   168,    80,   285,   286,    80,   173,    89,
      76,    76,   132,    93,   134,   218,   181,   220,    80,    80,
      80,    16,    80,   226,    80,   219,   220,    76,    80,    85,
     285,   286,   258,    76,   353,    78,   504,   209,    77,   242,
      76,    80,   122,    89,    80,   196,     8,    93,    76,   101,
     201,    76,    76,   218,    77,    80,   259,    80,    76,     8,
     394,   395,   396,   266,    76,    76,   217,   270,   271,   272,
     273,   274,   275,   245,   277,    91,   356,    93,    94,    76,
     252,    76,   464,   234,   287,   467,   468,   469,   168,   240,
      16,    77,    76,   173,    80,   449,    77,   352,   358,    80,
     482,   181,   253,   241,    80,    76,   271,   272,   273,   274,
     275,   314,   315,    78,   394,   395,   396,    23,   321,    77,
     240,    27,    80,   326,    30,   328,    77,    33,    34,    80,
      36,     3,    80,   467,   468,   469,    73,    76,   218,   394,
     395,   396,   345,   294,    77,    76,   426,    80,    54,   352,
      56,    85,    77,    77,   357,    80,    80,    80,    77,    65,
     440,    80,    77,    69,   367,    80,   369,    76,    74,   279,
     280,   281,   375,    85,    76,   378,   379,   380,   381,   382,
     383,    86,    80,   438,   410,   411,   389,   467,   468,   469,
      80,   271,   272,   273,   274,   275,   102,    85,    80,    87,
     403,   352,    82,    83,    84,    85,    86,   358,   359,   360,
     375,    16,   467,   468,   469,    78,   460,    82,    83,    84,
      85,    86,    87,    80,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,    77,   438,    86,   409,   125,    82,
      83,    84,    85,    86,    87,    84,    85,    86,   503,    84,
      85,    86,    78,   140,   405,    77,    77,    80,    83,   462,
      82,    83,    84,    85,    86,    87,    79,    84,   419,    80,
     157,   158,   352,    80,    80,    83,    80,    80,   481,    78,
      77,    89,    80,    76,    76,    93,    72,   438,    16,    80,
      16,    80,   495,   444,    77,   375,    77,    77,    77,    77,
     503,   527,    77,    77,    80,   508,   499,   123,   405,   512,
     147,   215,   148,   464,   122,   484,   467,   468,   469,   438,
     503,   136,   477,   526,   211,   212,   552,   234,   419,   298,
     521,   482,   493,   408,   494,   538,   458,   224,   225,   149,
     360,   228,    81,   546,   375,   372,   505,   285,   551,    -1,
      -1,    -1,   503,    -1,    -1,   506,   243,    -1,   438,    -1,
     168,    -1,    -1,    -1,   444,   173,    -1,   254,    -1,   256,
      -1,    -1,    -1,   181,    -1,    -1,    -1,    -1,    77,   187,
      -1,    -1,   269,    82,    83,    84,    85,    86,    87,    -1,
      -1,   199,    -1,    -1,    -1,   203,    -1,    -1,   285,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
     218,    -1,    -1,    -1,    -1,   302,    82,    83,    84,    85,
      86,    -1,    -1,   503,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   329,   330,   331,   332,   333,   334,   335,   336,
      -1,    -1,    -1,    -1,    -1,    -1,   343,   344,    -1,    -1,
      -1,    -1,    -1,   271,   272,   273,   274,   275,    76,   356,
      -1,   279,   280,   281,    82,    83,    84,    -1,    86,    -1,
      -1,    -1,    -1,    -1,    92,   372,    -1,    -1,    -1,    -1,
     298,    -1,    -1,    76,    77,    -1,    -1,    -1,    -1,    82,
      83,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      -1,    -1,   399,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     417,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,   375,    -1,    -1,
     457,    -1,   459,   460,    -1,    -1,    -1,    -1,    -1,    -1,
     388,    -1,    76,    -1,    -1,    -1,    80,    -1,    82,    83,
     477,    -1,    -1,   401,    -1,    -1,    -1,    -1,    92,   407,
      76,    -1,   489,    79,    -1,    -1,    82,    83,    -1,    -1,
      -1,    76,    -1,    -1,    -1,    -1,    92,    82,    83,    84,
     507,    -1,    76,   510,    -1,    -1,    -1,    92,    82,    83,
      84,    -1,    -1,    -1,   521,    -1,    -1,    -1,    92,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,   539,    -1,    -1,    -1,   464,    -1,    -1,    -1,
      -1,     6,    -1,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,   482,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    -1,    64,
      65,    66,    67,    68,    69,    70,    71,    -1,    -1,    74,
      75,    -1,    76,    -1,    -1,    -1,    -1,    -1,    82,    83,
      84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,
      -1,    -1,    -1,    -1,    99,    -1,    -1,   102,   103,   104,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    76,
      -1,    -1,    -1,    -1,    -1,    82,    83,    -1,    -1,    -1,
      76,    -1,    -1,    -1,    -1,    92,    82,    83,    -1,    -1,
      -1,    76,    -1,    -1,    -1,    -1,    92,    82,    83,    -1,
      -1,    -1,    76,    -1,    -1,    -1,    -1,    92,    82,    83,
      84,    -1,    86,    76,    -1,    -1,    -1,    15,    -1,    82,
      83,    84,    20,    86,    -1,    -1,    -1,    76,    26,    27,
      28,    -1,    30,    82,    83,    84,    -1,    -1,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    82,    83,    84,    85,
      86,    87,    50,    -1,    52,    -1,    54,    93,    94,    95,
      96,    97,    98,    61,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    80,    -1,    -1,    -1,    -1,    -1,    86,    -1,
      -1,    -1,    90,    -1,    92,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    -1,    93,    94,    95,    96,
      97,    98,    -1,    76,    -1,    -1,    -1,    -1,    -1,    82,
      83,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      21,    22,    -1,    24,    -1,    26,    -1,    28,    -1,    -1,
      31,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    40,
      82,    83,    -1,    -1,    76,    -1,    47,    48,    49,    50,
      82,    83,    53,    -1,    -1,    -1,    -1,    58,    -1,    60,
      61,    -1,    -1,    64,    -1,    66,    67,    -1,    -1,    70,
      77,    72,    -1,    -1,    75,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    -1,    93,    94,    95,    96,
      97,    98,    77,    -1,    -1,    -1,    -1,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    -1,    93,    94,
      95,    96,    97,    98,    77,    -1,    -1,    -1,    -1,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    -1,
      93,    94,    95,    96,    97,    98,    77,    -1,    -1,    -1,
      -1,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    -1,    93,    94,    95,    96,    97,    98,    77,    -1,
      -1,    -1,    -1,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    -1,    93,    94,    95,    96,    97,    98,
      77,    -1,    -1,    -1,    -1,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    -1,    93,    94,    95,    96,
      97,    98,    77,    -1,    -1,    -1,    -1,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    -1,    93,    94,
      95,    96,    97,    98,    79,    -1,    -1,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    -1,    93,    94,
      95,    96,    97,    98,    79,    -1,    -1,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    -1,    93,    94,
      95,    96,    97,    98,    82,    83,    84,    85,    86,    87,
      88,    89,    -1,    -1,    -1,    93,    94,    95,    96,    97,
      98,    82,    83,    84,    85,    86,    87,    88,    -1,    -1,
      -1,    -1,    93,    94,    95,    96,    97,    98,    82,    83,
      84,    85,    86,    87,    -1,    -1,    -1,    -1,    -1,    93,
      94,    95,    96,    97,    98
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   106,     0,     1,     5,   107,   108,     3,     6,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    64,    65,    66,    67,    68,    69,    70,    71,
      74,    75,    99,   102,   103,   104,   109,   121,   122,   124,
     125,   126,   128,   130,   131,   132,   135,   158,   165,   184,
     186,   187,   191,   193,   194,   196,   199,   204,   205,   206,
     207,   208,   209,   215,   216,   217,     7,   120,   201,   110,
     201,   168,   201,   136,   201,   201,   201,   201,    16,   111,
     112,   168,   168,   110,   201,   201,   201,   201,   201,   168,
     168,   168,   201,   110,   201,   201,    85,    87,   112,   129,
     144,   145,   110,   201,   110,    80,   101,    46,    80,   195,
      76,    84,   127,    80,   195,    80,    80,    80,   195,    80,
      85,   166,   201,    72,   191,   112,   175,    76,   201,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    76,    82,
      83,    84,    86,   173,   175,   179,   181,   182,   183,   211,
     201,    76,   211,   201,    84,   183,   210,   211,   211,    80,
       8,   192,   111,   113,   112,   112,   129,   148,   137,   138,
      76,    76,   117,    76,   133,   112,   111,     8,   157,   112,
      76,    76,    76,   159,   160,   161,   112,    76,    76,    84,
     182,   183,   113,   223,    76,    92,   171,   172,   173,   175,
     177,   179,   180,    16,    80,   111,   223,   111,   112,   138,
     110,   112,   171,   202,   148,   129,   112,   112,   133,   137,
     159,   112,   157,   195,    76,   176,    78,    77,    84,   171,
     197,   198,   177,    17,    84,    86,   182,   212,   213,   214,
     182,    84,    85,    86,    87,   173,   223,   182,   223,    80,
      76,    80,   175,   218,   219,    76,    80,   171,   172,   180,
     220,   221,   222,   220,    73,    76,   151,   148,    76,   149,
     150,   175,   185,    77,    84,   112,   118,   119,   134,   175,
     117,   195,   156,   157,   171,   171,    76,   124,   112,   146,
     147,   182,   223,   223,    76,   114,   171,   172,   171,    84,
      85,    86,    87,    88,    89,    90,    91,    93,    94,    95,
      96,    97,    98,   173,   174,   171,    85,   145,   117,   117,
     151,   140,   141,   111,   168,    77,    76,   171,   195,    85,
     195,   100,   112,   188,   189,   169,   170,   171,   177,   171,
     157,    77,    80,    77,    77,    80,    84,    86,   171,   182,
     182,   182,   182,   182,    77,   218,   218,   218,    80,   171,
     172,   221,   222,   220,    80,    80,    80,   112,   152,   153,
     150,    80,    85,   171,    77,    80,    77,    80,    76,    77,
      80,    77,    77,    16,   162,   163,   164,    78,    77,    80,
      77,    16,    77,   115,   116,    77,    80,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   127,    80,   101,
      76,   112,   142,   143,   173,   178,   179,   180,   117,   123,
      84,   203,   148,   112,   167,   189,   190,    78,    77,    80,
      79,   198,   182,   213,    80,   219,    77,    80,    80,    80,
     172,   222,   172,   222,   172,   222,    77,    80,    84,   154,
     155,   171,    80,   149,   139,    77,   119,   175,   156,   195,
     157,   157,    77,    80,    83,   171,   147,    78,    77,    80,
     172,   142,   178,    84,   151,    77,    80,    76,   171,   200,
      76,   176,   171,   177,   112,   188,   172,   188,   188,   188,
     154,    79,   188,   140,    72,    77,   171,    80,   163,   164,
      16,   116,    77,   143,   178,   127,   203,   112,   171,    80,
      77,    77,    77,    77,    77,   155,   171,    77,    85,   157,
      77,   171,    80,   157
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 4:
/* Line 1792 of yacc.c  */
#line 175 "fortran.y"
    {}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 178 "fortran.y"
    {}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 180 "fortran.y"
    {}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 182 "fortran.y"
    {}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 184 "fortran.y"
    {}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 186 "fortran.y"
    {}
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 190 "fortran.y"
    {
/*
            if (yyStatementNumber) {
                std::cerr << "Label " << yyStatementNumber
                          << " define in line " << lineNumber
                          << std::endl;
            }
*/
        }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 202 "fortran.y"
    {
                    CrossRefs::defs[*((yyvsp[(3) - (3)].curs))] = "PROGRAM";
                    CrossRefs::currentRoutine = ((yyvsp[(3) - (3)].curs))->content;
                }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 207 "fortran.y"
    {
                    CrossRefs::defs[*((yyvsp[(3) - (4)].curs))] = "PROGRAM";
                    CrossRefs::currentRoutine = ((yyvsp[(3) - (4)].curs))->content;
                }
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 212 "fortran.y"
    {}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 214 "fortran.y"
    {
                    CrossRefs::defs[*((yyvsp[(3) - (4)].curs))] = "SUBROUTINE";
                    CrossRefs::currentRoutine = ((yyvsp[(3) - (4)].curs))->content;
                }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 219 "fortran.y"
    {
                    CrossRefs::defs[*((yyvsp[(3) - (4)].curs))] = "SUBROUTINE";
                    CrossRefs::currentRoutine = ((yyvsp[(3) - (4)].curs))->content;
                }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 224 "fortran.y"
    {
                    CrossRefs::defs[*((yyvsp[(3) - (4)].curs))] = "FUNCTION";
                    CrossRefs::currentRoutine = ((yyvsp[(3) - (4)].curs))->content;
                }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 229 "fortran.y"
    {
                    CrossRefs::defs[*((yyvsp[(4) - (5)].curs))] = "FUNCTION";
                    CrossRefs::currentRoutine = ((yyvsp[(4) - (5)].curs))->content;
                }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 234 "fortran.y"
    {}
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 238 "fortran.y"
    {}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 242 "fortran.y"
    {
                    (yyval.curs) = (yyvsp[(1) - (1)].curs);
                }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 248 "fortran.y"
    {
                    CrossRefs::name[cursor] = cursor.content;
                    (yyval.curs) = &(CrossRefs::name.find(cursor)->first);
                }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 255 "fortran.y"
    {
                    (yyval.curs) = &voidCursor;
                }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 259 "fortran.y"
    {
                    (yyval.curs) = (yyvsp[(1) - (1)].curs);
                }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 278 "fortran.y"
    {}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 280 "fortran.y"
    {}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 282 "fortran.y"
    {}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 286 "fortran.y"
    {}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 288 "fortran.y"
    {}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 292 "fortran.y"
    {
                    CrossRefs::args[((yyvsp[(1) - (1)].curs))->content] = *((yyvsp[(1) - (1)].curs));
                }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 296 "fortran.y"
    { }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 302 "fortran.y"
    {}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 313 "fortran.y"
    {}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 315 "fortran.y"
    {}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 317 "fortran.y"
    {
            flushLine();
        }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 321 "fortran.y"
    {}
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 325 "fortran.y"
    {
            const Cursor *nameCursor = (yyvsp[(3) - (7)].curs);

            CrossRefs::declaration[nameCursor->content] = *nameCursor;
            CrossRefs::variable[nameCursor->content]    = lineNumber;
        }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 332 "fortran.y"
    {
            const Cursor *nameCursor = (yyvsp[(3) - (5)].curs);

            CrossRefs::declaration[nameCursor->content] = *nameCursor;
            CrossRefs::variable[nameCursor->content]    = lineNumber;
        }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 339 "fortran.y"
    {
        }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 343 "fortran.y"
    {
                //printf("new_dcl\n");
            }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 349 "fortran.y"
    {
            (yyval.ival) = (yyvsp[(1) - (2)].ival);
        }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 355 "fortran.y"
    {
            (yyval.ival) = (yyvsp[(1) - (1)].ival);
        }
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 360 "fortran.y"
    { (yyval.ival) = 1; }
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 361 "fortran.y"
    { (yyval.ival) = 2; }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 362 "fortran.y"
    { (yyval.ival) = 3; }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 363 "fortran.y"
    { (yyval.ival) = 4; }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 364 "fortran.y"
    { (yyval.ival) = 5; }
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 365 "fortran.y"
    { (yyval.ival) = 6; }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 366 "fortran.y"
    { (yyval.ival) = 7; }
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 367 "fortran.y"
    { (yyval.ival) = 8; }
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 368 "fortran.y"
    { (yyval.ival) = 9; }
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 369 "fortran.y"
    { NOEXT("AUTOMATIC statement"); (yyval.ival) = 10; }
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 370 "fortran.y"
    { NOEXT("STATIC statement"); (yyval.ival) = 11; }
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 371 "fortran.y"
    { (yyval.ival) = 12; }
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 375 "fortran.y"
    {
        }
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 378 "fortran.y"
    {
            // this rule was added as a hack
        }
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 382 "fortran.y"
    {
        }
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 385 "fortran.y"
    {
        }
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 390 "fortran.y"
    { }
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 392 "fortran.y"
    { }
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 394 "fortran.y"
    { }
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 396 "fortran.y"
    { }
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 400 "fortran.y"
    { }
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 402 "fortran.y"
    { }
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 406 "fortran.y"
    {
            CrossRefs::external[cursor.content] = cursor.fromLine;
            CrossRefs::call[CrossRefs::currentRoutine].push_back(cursor.content);
        }
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 411 "fortran.y"
    {
            CrossRefs::external[cursor.content] = cursor.fromLine;
            CrossRefs::call[CrossRefs::currentRoutine].push_back(cursor.content);
        }
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 418 "fortran.y"
    {
            CrossRefs::intrinsic[cursor.content] = cursor.fromLine;
        }
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 422 "fortran.y"
    {
            CrossRefs::intrinsic[cursor.content] = cursor.fromLine;
        }
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 432 "fortran.y"
    { }
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 436 "fortran.y"
    { }
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 438 "fortran.y"
    { }
    break;

  case 90:
/* Line 1792 of yacc.c  */
#line 446 "fortran.y"
    { }
    break;

  case 91:
/* Line 1792 of yacc.c  */
#line 450 "fortran.y"
    { }
    break;

  case 92:
/* Line 1792 of yacc.c  */
#line 453 "fortran.y"
    { }
    break;

  case 93:
/* Line 1792 of yacc.c  */
#line 455 "fortran.y"
    { }
    break;

  case 94:
/* Line 1792 of yacc.c  */
#line 457 "fortran.y"
    { }
    break;

  case 97:
/* Line 1792 of yacc.c  */
#line 462 "fortran.y"
    { }
    break;

  case 98:
/* Line 1792 of yacc.c  */
#line 464 "fortran.y"
    { }
    break;

  case 100:
/* Line 1792 of yacc.c  */
#line 469 "fortran.y"
    { }
    break;

  case 104:
/* Line 1792 of yacc.c  */
#line 478 "fortran.y"
    { }
    break;

  case 108:
/* Line 1792 of yacc.c  */
#line 487 "fortran.y"
    { }
    break;

  case 109:
/* Line 1792 of yacc.c  */
#line 491 "fortran.y"
    {}
    break;

  case 110:
/* Line 1792 of yacc.c  */
#line 495 "fortran.y"
    { }
    break;

  case 111:
/* Line 1792 of yacc.c  */
#line 497 "fortran.y"
    { }
    break;

  case 112:
/* Line 1792 of yacc.c  */
#line 501 "fortran.y"
    { }
    break;

  case 113:
/* Line 1792 of yacc.c  */
#line 503 "fortran.y"
    { }
    break;

  case 114:
/* Line 1792 of yacc.c  */
#line 507 "fortran.y"
    {
        }
    break;

  case 115:
/* Line 1792 of yacc.c  */
#line 510 "fortran.y"
    {
        }
    break;

  case 116:
/* Line 1792 of yacc.c  */
#line 514 "fortran.y"
    { }
    break;

  case 119:
/* Line 1792 of yacc.c  */
#line 519 "fortran.y"
    { }
    break;

  case 120:
/* Line 1792 of yacc.c  */
#line 521 "fortran.y"
    { }
    break;

  case 121:
/* Line 1792 of yacc.c  */
#line 525 "fortran.y"
    { }
    break;

  case 123:
/* Line 1792 of yacc.c  */
#line 530 "fortran.y"
    { }
    break;

  case 124:
/* Line 1792 of yacc.c  */
#line 532 "fortran.y"
    { }
    break;

  case 125:
/* Line 1792 of yacc.c  */
#line 536 "fortran.y"
    {
/*
            std::cerr << "label:" << std::endl;
            std::cerr << "      token = "   << token << std::endl;
            std::cerr << "      content = " << Cursor::content << std::endl;
            std::cerr << "      stno = "    << yyStatementNumber << std::endl;
            $$ = atoi(token);
*/
        }
    break;

  case 126:
/* Line 1792 of yacc.c  */
#line 548 "fortran.y"
    { }
    break;

  case 130:
/* Line 1792 of yacc.c  */
#line 555 "fortran.y"
    { }
    break;

  case 131:
/* Line 1792 of yacc.c  */
#line 558 "fortran.y"
    { }
    break;

  case 135:
/* Line 1792 of yacc.c  */
#line 566 "fortran.y"
    { }
    break;

  case 136:
/* Line 1792 of yacc.c  */
#line 568 "fortran.y"
    { }
    break;

  case 137:
/* Line 1792 of yacc.c  */
#line 572 "fortran.y"
    { }
    break;

  case 140:
/* Line 1792 of yacc.c  */
#line 580 "fortran.y"
    { }
    break;

  case 141:
/* Line 1792 of yacc.c  */
#line 584 "fortran.y"
    { }
    break;

  case 142:
/* Line 1792 of yacc.c  */
#line 586 "fortran.y"
    { }
    break;

  case 143:
/* Line 1792 of yacc.c  */
#line 590 "fortran.y"
    { }
    break;

  case 144:
/* Line 1792 of yacc.c  */
#line 593 "fortran.y"
    {}
    break;

  case 145:
/* Line 1792 of yacc.c  */
#line 595 "fortran.y"
    {}
    break;

  case 146:
/* Line 1792 of yacc.c  */
#line 599 "fortran.y"
    {}
    break;

  case 147:
/* Line 1792 of yacc.c  */
#line 601 "fortran.y"
    {}
    break;

  case 149:
/* Line 1792 of yacc.c  */
#line 606 "fortran.y"
    {}
    break;

  case 153:
/* Line 1792 of yacc.c  */
#line 613 "fortran.y"
    {}
    break;

  case 154:
/* Line 1792 of yacc.c  */
#line 615 "fortran.y"
    {}
    break;

  case 155:
/* Line 1792 of yacc.c  */
#line 617 "fortran.y"
    {}
    break;

  case 156:
/* Line 1792 of yacc.c  */
#line 619 "fortran.y"
    {}
    break;

  case 157:
/* Line 1792 of yacc.c  */
#line 621 "fortran.y"
    {}
    break;

  case 158:
/* Line 1792 of yacc.c  */
#line 623 "fortran.y"
    {}
    break;

  case 159:
/* Line 1792 of yacc.c  */
#line 625 "fortran.y"
    { }
    break;

  case 160:
/* Line 1792 of yacc.c  */
#line 627 "fortran.y"
    { }
    break;

  case 161:
/* Line 1792 of yacc.c  */
#line 629 "fortran.y"
    {}
    break;

  case 162:
/* Line 1792 of yacc.c  */
#line 631 "fortran.y"
    {}
    break;

  case 163:
/* Line 1792 of yacc.c  */
#line 633 "fortran.y"
    {}
    break;

  case 164:
/* Line 1792 of yacc.c  */
#line 635 "fortran.y"
    { }
    break;

  case 165:
/* Line 1792 of yacc.c  */
#line 638 "fortran.y"
    {}
    break;

  case 166:
/* Line 1792 of yacc.c  */
#line 639 "fortran.y"
    {}
    break;

  case 167:
/* Line 1792 of yacc.c  */
#line 642 "fortran.y"
    {}
    break;

  case 168:
/* Line 1792 of yacc.c  */
#line 643 "fortran.y"
    {}
    break;

  case 169:
/* Line 1792 of yacc.c  */
#line 644 "fortran.y"
    {}
    break;

  case 170:
/* Line 1792 of yacc.c  */
#line 645 "fortran.y"
    {}
    break;

  case 171:
/* Line 1792 of yacc.c  */
#line 646 "fortran.y"
    {}
    break;

  case 172:
/* Line 1792 of yacc.c  */
#line 647 "fortran.y"
    {}
    break;

  case 173:
/* Line 1792 of yacc.c  */
#line 651 "fortran.y"
    {}
    break;

  case 174:
/* Line 1792 of yacc.c  */
#line 653 "fortran.y"
    {}
    break;

  case 175:
/* Line 1792 of yacc.c  */
#line 655 "fortran.y"
    {}
    break;

  case 176:
/* Line 1792 of yacc.c  */
#line 657 "fortran.y"
    {}
    break;

  case 177:
/* Line 1792 of yacc.c  */
#line 661 "fortran.y"
    {}
    break;

  case 178:
/* Line 1792 of yacc.c  */
#line 665 "fortran.y"
    {}
    break;

  case 180:
/* Line 1792 of yacc.c  */
#line 670 "fortran.y"
    {}
    break;

  case 182:
/* Line 1792 of yacc.c  */
#line 674 "fortran.y"
    {}
    break;

  case 183:
/* Line 1792 of yacc.c  */
#line 675 "fortran.y"
    {}
    break;

  case 184:
/* Line 1792 of yacc.c  */
#line 676 "fortran.y"
    {}
    break;

  case 185:
/* Line 1792 of yacc.c  */
#line 677 "fortran.y"
    {}
    break;

  case 186:
/* Line 1792 of yacc.c  */
#line 678 "fortran.y"
    {}
    break;

  case 187:
/* Line 1792 of yacc.c  */
#line 679 "fortran.y"
    {}
    break;

  case 189:
/* Line 1792 of yacc.c  */
#line 684 "fortran.y"
    {}
    break;

  case 190:
/* Line 1792 of yacc.c  */
#line 688 "fortran.y"
    { NOEXT("hex constant");}
    break;

  case 191:
/* Line 1792 of yacc.c  */
#line 690 "fortran.y"
    { NOEXT("octal constant");}
    break;

  case 192:
/* Line 1792 of yacc.c  */
#line 692 "fortran.y"
    { NOEXT("binary constant");}
    break;

  case 194:
/* Line 1792 of yacc.c  */
#line 697 "fortran.y"
    {}
    break;

  case 197:
/* Line 1792 of yacc.c  */
#line 703 "fortran.y"
    {}
    break;

  case 198:
/* Line 1792 of yacc.c  */
#line 705 "fortran.y"
    {}
    break;

  case 199:
/* Line 1792 of yacc.c  */
#line 707 "fortran.y"
    {}
    break;

  case 200:
/* Line 1792 of yacc.c  */
#line 709 "fortran.y"
    {}
    break;

  case 201:
/* Line 1792 of yacc.c  */
#line 711 "fortran.y"
    {}
    break;

  case 202:
/* Line 1792 of yacc.c  */
#line 713 "fortran.y"
    { }
    break;

  case 204:
/* Line 1792 of yacc.c  */
#line 718 "fortran.y"
    {
//            std::cerr << "DO LABEL = " << $3 << std::endl;
        }
    break;

  case 205:
/* Line 1792 of yacc.c  */
#line 722 "fortran.y"
    {
            NOEXT("DO without label");
//            std::cerr << "DO-loop expecting enddo in line "
//                      << lineNumber
//                      << std::endl;
        }
    break;

  case 206:
/* Line 1792 of yacc.c  */
#line 729 "fortran.y"
    {
//                    std::cerr << "ENDDO: " << Cursor::content
//                              << " line " << Cursor::fromLine
//                              << std::endl;
                }
    break;

  case 207:
/* Line 1792 of yacc.c  */
#line 735 "fortran.y"
    {}
    break;

  case 209:
/* Line 1792 of yacc.c  */
#line 737 "fortran.y"
    {}
    break;

  case 210:
/* Line 1792 of yacc.c  */
#line 738 "fortran.y"
    {}
    break;

  case 211:
/* Line 1792 of yacc.c  */
#line 740 "fortran.y"
    {}
    break;

  case 212:
/* Line 1792 of yacc.c  */
#line 742 "fortran.y"
    {}
    break;

  case 213:
/* Line 1792 of yacc.c  */
#line 746 "fortran.y"
    {
//            std::cerr << "DO loop > " << Cursor::content
//                     << " line " << Cursor::fromLine
//                     << std::endl;
        }
    break;

  case 214:
/* Line 1792 of yacc.c  */
#line 754 "fortran.y"
    {}
    break;

  case 215:
/* Line 1792 of yacc.c  */
#line 758 "fortran.y"
    {}
    break;

  case 217:
/* Line 1792 of yacc.c  */
#line 762 "fortran.y"
    {}
    break;

  case 218:
/* Line 1792 of yacc.c  */
#line 763 "fortran.y"
    {}
    break;

  case 219:
/* Line 1792 of yacc.c  */
#line 767 "fortran.y"
    {}
    break;

  case 220:
/* Line 1792 of yacc.c  */
#line 769 "fortran.y"
    {}
    break;

  case 223:
/* Line 1792 of yacc.c  */
#line 773 "fortran.y"
    {}
    break;

  case 224:
/* Line 1792 of yacc.c  */
#line 775 "fortran.y"
    {}
    break;

  case 225:
/* Line 1792 of yacc.c  */
#line 777 "fortran.y"
    {}
    break;

  case 226:
/* Line 1792 of yacc.c  */
#line 779 "fortran.y"
    {}
    break;

  case 227:
/* Line 1792 of yacc.c  */
#line 781 "fortran.y"
    {}
    break;

  case 228:
/* Line 1792 of yacc.c  */
#line 783 "fortran.y"
    {}
    break;

  case 229:
/* Line 1792 of yacc.c  */
#line 785 "fortran.y"
    {}
    break;

  case 230:
/* Line 1792 of yacc.c  */
#line 789 "fortran.y"
    {}
    break;

  case 231:
/* Line 1792 of yacc.c  */
#line 793 "fortran.y"
    {
                }
    break;

  case 232:
/* Line 1792 of yacc.c  */
#line 798 "fortran.y"
    {}
    break;

  case 233:
/* Line 1792 of yacc.c  */
#line 800 "fortran.y"
    {}
    break;

  case 234:
/* Line 1792 of yacc.c  */
#line 802 "fortran.y"
    {}
    break;

  case 235:
/* Line 1792 of yacc.c  */
#line 804 "fortran.y"
    {}
    break;

  case 238:
/* Line 1792 of yacc.c  */
#line 812 "fortran.y"
    { }
    break;

  case 239:
/* Line 1792 of yacc.c  */
#line 816 "fortran.y"
    {}
    break;

  case 240:
/* Line 1792 of yacc.c  */
#line 818 "fortran.y"
    {}
    break;

  case 242:
/* Line 1792 of yacc.c  */
#line 823 "fortran.y"
    {}
    break;

  case 243:
/* Line 1792 of yacc.c  */
#line 827 "fortran.y"
    {}
    break;

  case 244:
/* Line 1792 of yacc.c  */
#line 829 "fortran.y"
    {}
    break;

  case 245:
/* Line 1792 of yacc.c  */
#line 833 "fortran.y"
    {}
    break;

  case 246:
/* Line 1792 of yacc.c  */
#line 835 "fortran.y"
    {}
    break;

  case 247:
/* Line 1792 of yacc.c  */
#line 839 "fortran.y"
    {}
    break;

  case 248:
/* Line 1792 of yacc.c  */
#line 843 "fortran.y"
    {}
    break;

  case 249:
/* Line 1792 of yacc.c  */
#line 847 "fortran.y"
    {}
    break;

  case 250:
/* Line 1792 of yacc.c  */
#line 852 "fortran.y"
    {}
    break;

  case 252:
/* Line 1792 of yacc.c  */
#line 857 "fortran.y"
    {}
    break;

  case 253:
/* Line 1792 of yacc.c  */
#line 859 "fortran.y"
    {}
    break;

  case 254:
/* Line 1792 of yacc.c  */
#line 861 "fortran.y"
    {}
    break;

  case 256:
/* Line 1792 of yacc.c  */
#line 864 "fortran.y"
    {}
    break;

  case 257:
/* Line 1792 of yacc.c  */
#line 866 "fortran.y"
    {}
    break;

  case 258:
/* Line 1792 of yacc.c  */
#line 868 "fortran.y"
    {}
    break;

  case 259:
/* Line 1792 of yacc.c  */
#line 870 "fortran.y"
    {}
    break;

  case 260:
/* Line 1792 of yacc.c  */
#line 872 "fortran.y"
    {}
    break;

  case 261:
/* Line 1792 of yacc.c  */
#line 874 "fortran.y"
    {}
    break;

  case 262:
/* Line 1792 of yacc.c  */
#line 876 "fortran.y"
    {}
    break;

  case 263:
/* Line 1792 of yacc.c  */
#line 878 "fortran.y"
    {}
    break;

  case 264:
/* Line 1792 of yacc.c  */
#line 880 "fortran.y"
    {}
    break;

  case 265:
/* Line 1792 of yacc.c  */
#line 882 "fortran.y"
    {}
    break;

  case 267:
/* Line 1792 of yacc.c  */
#line 889 "fortran.y"
    {}
    break;

  case 268:
/* Line 1792 of yacc.c  */
#line 891 "fortran.y"
    {}
    break;

  case 269:
/* Line 1792 of yacc.c  */
#line 893 "fortran.y"
    {}
    break;

  case 271:
/* Line 1792 of yacc.c  */
#line 900 "fortran.y"
    {}
    break;

  case 272:
/* Line 1792 of yacc.c  */
#line 902 "fortran.y"
    {}
    break;

  case 273:
/* Line 1792 of yacc.c  */
#line 904 "fortran.y"
    {}
    break;

  case 274:
/* Line 1792 of yacc.c  */
#line 908 "fortran.y"
    {}
    break;

  case 275:
/* Line 1792 of yacc.c  */
#line 910 "fortran.y"
    {}
    break;

  case 276:
/* Line 1792 of yacc.c  */
#line 914 "fortran.y"
    {}
    break;

  case 277:
/* Line 1792 of yacc.c  */
#line 916 "fortran.y"
    {}
    break;

  case 280:
/* Line 1792 of yacc.c  */
#line 924 "fortran.y"
    {}
    break;

  case 281:
/* Line 1792 of yacc.c  */
#line 926 "fortran.y"
    {}
    break;

  case 282:
/* Line 1792 of yacc.c  */
#line 928 "fortran.y"
    {}
    break;

  case 283:
/* Line 1792 of yacc.c  */
#line 930 "fortran.y"
    {}
    break;

  case 284:
/* Line 1792 of yacc.c  */
#line 932 "fortran.y"
    {}
    break;

  case 285:
/* Line 1792 of yacc.c  */
#line 934 "fortran.y"
    {}
    break;

  case 286:
/* Line 1792 of yacc.c  */
#line 938 "fortran.y"
    {}
    break;

  case 287:
/* Line 1792 of yacc.c  */
#line 942 "fortran.y"
    {}
    break;

  case 288:
/* Line 1792 of yacc.c  */
#line 946 "fortran.y"
    {}
    break;

  case 289:
/* Line 1792 of yacc.c  */
#line 950 "fortran.y"
    {}
    break;

  case 290:
/* Line 1792 of yacc.c  */
#line 952 "fortran.y"
    {}
    break;

  case 291:
/* Line 1792 of yacc.c  */
#line 956 "fortran.y"
    {}
    break;

  case 292:
/* Line 1792 of yacc.c  */
#line 958 "fortran.y"
    {}
    break;

  case 293:
/* Line 1792 of yacc.c  */
#line 962 "fortran.y"
    {}
    break;

  case 294:
/* Line 1792 of yacc.c  */
#line 964 "fortran.y"
    {}
    break;

  case 295:
/* Line 1792 of yacc.c  */
#line 968 "fortran.y"
    {}
    break;

  case 296:
/* Line 1792 of yacc.c  */
#line 970 "fortran.y"
    {}
    break;

  case 298:
/* Line 1792 of yacc.c  */
#line 975 "fortran.y"
    {}
    break;

  case 299:
/* Line 1792 of yacc.c  */
#line 977 "fortran.y"
    {}
    break;

  case 300:
/* Line 1792 of yacc.c  */
#line 979 "fortran.y"
    {}
    break;

  case 301:
/* Line 1792 of yacc.c  */
#line 981 "fortran.y"
    {}
    break;

  case 302:
/* Line 1792 of yacc.c  */
#line 983 "fortran.y"
    {}
    break;

  case 303:
/* Line 1792 of yacc.c  */
#line 985 "fortran.y"
    {}
    break;

  case 304:
/* Line 1792 of yacc.c  */
#line 989 "fortran.y"
    {}
    break;

  case 305:
/* Line 1792 of yacc.c  */
#line 991 "fortran.y"
    {}
    break;

  case 306:
/* Line 1792 of yacc.c  */
#line 993 "fortran.y"
    {}
    break;

  case 307:
/* Line 1792 of yacc.c  */
#line 995 "fortran.y"
    {}
    break;

  case 308:
/* Line 1792 of yacc.c  */
#line 997 "fortran.y"
    {}
    break;

  case 309:
/* Line 1792 of yacc.c  */
#line 1001 "fortran.y"
    {}
    break;


/* Line 1792 of yacc.c  */
#line 3720 "fortran.cc"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


