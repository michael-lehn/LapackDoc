/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
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
/* Line 2058 of yacc.c  */
#line 144 "fortran.y"

        int           ival;
        char          *sval;
        const Cursor  *curs;
        

/* Line 2058 of yacc.c  */
#line 169 "fortran.h"
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
