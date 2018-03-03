#ifndef TESTUTILS_H
#define TESTUTILS_H

#include <string>
#include <cstdlib>
#include <stdio.h>

#include "kmp_skipsearch/kmp_skipsearch.h"
#include "alpha_skipsearch/alpha_skipsearch.h"
#include "mp/mp.h"
#include "escape_sequences.h"

using namespace std;

namespace debug {
    inline char randchar(char, char);
    void debugKMPSSOnMP(int, int, char, char, int);
    void debugAlphaSSOnMP(int, int, char, char, int);
}

#endif