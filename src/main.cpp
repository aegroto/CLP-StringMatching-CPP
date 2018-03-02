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
#include "alphatrie.h"

using namespace std;

int main() {
    srand(time(0));

    // debug::debugKMPSSOnMP(4, 15, 'a', 'c', 1000000);

    string pattern ="abcabaa";
    size_t l = 3;

    AlphaTrie trie(l);
    trie.addSubstring(&pattern[0], 0);
    return 0;
}

