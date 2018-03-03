#include <string>
#include <cstdlib>
#include <stdio.h>

#include "kmp_skipsearch/kmp_skipsearch.h"
#include "mp/mp.h"
#include "escape_sequences.h"

using namespace std;

namespace debug {
    inline char randchar(char, char);
    void debugKMPSSOnMP(int, int, char, char, int);
}
