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

#ifndef F77CRASH_AUXILIARY_H
#define F77CRASH_AUXILIARY_H 1

void
initAuxiliary();

int
hexToInt(char c);

bool
isAlpha_(int c);

bool
isAlphaNum_(int c);

unsigned char
letter(char c);

#endif // F77CRASH_AUXILIARY_H
