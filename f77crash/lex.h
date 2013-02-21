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

#ifndef F77CRASH_LEX_H
#define F77CRASH_LEX_H 1

#include <string>

void
initLex();

int
yylex();

void
yyerror(const char *s);

void
flushLine();


void
doInputFile(const char *filename);

extern int   yyStatementNumber;
extern long  lineNumber;
extern char  *token;
extern int   tokenLength;

//
//  States determined and set/controlled by the parser
//
extern int   newDeclaration;
extern int   needKeyword;
extern bool  inioctl;

#endif // F77CRASH_LEX_H
