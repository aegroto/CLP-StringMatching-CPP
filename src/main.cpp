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
#include "alpha_skipsearch/alpha_skipsearch.h"

using namespace std;

int main() {
    srand(time(0));

    printf("\n");
    debug::debugKMPSSOnMP(15, 200, 'a', 'c', 10000);
    printf("\n");
    debug::debugAlphaSSOnMP(15, 200, 'a', 'c', 10000);
    printf("\n");

    /*string x = "aaab";
    string y = "bccbaaaaaaccaac";*/

    /*int m = x.length();
    int l = helpers::log2(m);

    AlphaTrie trie(l);
    
    printf("l is %i\n", l);*/

    /*printf("adding substring at index 0\n");
    trie.addSubstring(&x[0], 0);

    /*printf("adding substring at index 1\n");
    trie.addSubstring(&x[1], 1);

    /*printf("adding substring at index 2\n");
    trie.addSubstring(&x[2], 2);*/

    /*for(int i = 0; i < m - l + 1; ++i) {
        printf("adding substring at index %i\n", i);

        trie.addSubstring(&x[i], i); 
        trie.print();

        printf("\n");
    }*/

    /*AlphaSkipSearchMatcher alphassm(x, y);
    alphassm.execute();
    alphassm.printOutput();*/

    return 0;
}

