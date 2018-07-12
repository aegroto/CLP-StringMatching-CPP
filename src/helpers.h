/**
 * "helpers" namespace header file
 *
 * Released under ZLib license: https://www.zlib.net/zlib_license.html
 *
 * Lorenzo Catania
**/

#ifndef HELPERS_H
#define HELPERS_H

#include <stdio.h>
#include <cstdlib>

namespace helpers {
    inline char randChar(char minChar, char maxChar) {
        return char((rand() % (maxChar - minChar + 1)) + minChar); 
    }

    inline int& max(int& a, int& b) { 
        return a > b ? a : b; 
    }

    int maxPeriod(const char*, int);
    int log(int, int);
};

#endif
