/**
 * A very fast string matching algorithm for small alphabets and long patterns
 * Paper and Algorithm by Charras, Lecroq, Pehoushek.
 * C++ implementation by Lorenzo Catania and Valentino Merlino
**/

#include <stdio.h>
#include <string>
#include <ctime>
#include <cstdlib>

#include "helpers.h"
#include "testutils.h"
#include "alphatree.h"      

using namespace std;

int main() {
    srand(time(0));

    // debug::debugKMPSSOnMP(4, 15, 'a', 'c', 1000000);

    string pattern ="abcabaa";
    size_t l = 3;

    AlphaTree alphatree(l);
    for(int i = 0; i < pattern.length() - l + 1; i++) {
        alphatree.addSubstring(&pattern[i]);
        alphatree.print();
        printf("\n\n");
    }
    return 0;
}

