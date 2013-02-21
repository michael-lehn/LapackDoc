//#define DEBUG

#include <f77crash/crossrefs.h>
#include <f77crash/fortran.h>
#include <f77crash/lex.h>
#include <iostream>
#include <limits>
#include <climits>
#include <map>

int
main(int argc, char **argv)
{
    initLex();

    if (argc==2) {

        doInputFile(argv[1]);

#       ifdef DEBUG
        yydebug = 1;
#       endif

        int k = yyparse();

        if (k) {
            std::cerr << "Bad parse, return code " << k << std::endl;
        }

        CrossRefs::dump(argv[1]);
    }

}
