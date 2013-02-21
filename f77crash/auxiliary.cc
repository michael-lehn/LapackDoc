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
#include <cassert>
#include <climits>

static bool initialized = false;

static unsigned char hexToIntTab[1 << CHAR_BIT];
static unsigned char isAlpha_Tab[1 << CHAR_BIT];
static unsigned char letterTab[1 << CHAR_BIT];

void
initAuxiliary()
{
//
//  Init table for hexToInt
//
    const char    *hex = "0123456789abcdef";
    const char    *Hex = "ABCDEF";

    for (int i = 0; hex[i]; ++i) {
        hexToIntTab[(unsigned char)(hex[i])] = i;
    }
    for (int i=0, j=10; Hex[i]; ++i, ++j) {
        hexToIntTab[(unsigned char)(Hex[i])] = j;
    }

//
//  Init table for isAlpha_
//
    const char *alpha_ = "abcdefghijklmnopqrstuvwxyz"
                         "ABCDEFGHIJKLMNOPQRSTUVWXYZ_";
    const char *Alpha_ = "0123456789";

    while (unsigned char i = *alpha_++) {
        isAlpha_Tab[i] = 1;
    }

    while (unsigned char i = *Alpha_++) {
        isAlpha_Tab[i] = 2;
    }

//
//  Init table for letter
//
    const char    *letter = "abcdefghijklmnopqrstuvwxyz";

    for(int j=0, i=0; (i = *letter); ++j, ++letter) {
        letterTab[i] = letterTab[(unsigned char)(i+'A'-'a')] = j;
    }

    initialized = true;
}

int
hexToInt(char c)
{
    assert(initialized);

    return hexToIntTab[(unsigned char)(c)];
}

bool
isAlpha_(int c)
{
    assert(initialized);

    return isAlpha_Tab[(unsigned char)(c)] == 1;
}

bool
isAlphaNum_(int c)
{
    assert(initialized);

    return isAlpha_Tab[(unsigned char)(c)];
}

unsigned char
letter(char c)
{
    assert(initialized);
    return letterTab[(unsigned char)(c)];
}
