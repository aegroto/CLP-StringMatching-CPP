/**
 * Skip Search - A very fast string matching algorithm for small alphabets and long patterns
 * Original Algorithm by C. Charras, T. Lecroq, J. D. Pehoushek.
 * C++ implementation by Lorenzo Catania and Valentino Merlino
 *
 * Lorenzo Catania
**/

#include <stdio.h>
#include <string>
#include <ctime>
#include <cstdlib>

#include "helpers.h"
#include "testing/testutils.h"
#include "testing/stringset.h"

#include "beta_skipsearch/beta_skipsearch.h"

using namespace std;

int main() {
    srand(time(0));

    printf("Generating string set...\n");
    StringSet stringSet(30,
                        50,
                        4000,
                        5000,
                        'a', 'c',
                        10000);

    /*debug::testSSOnMP(stringSet);
    printf("\n");*/
    /*debug::testKMPSSOnMP(stringSet);
    printf("\n");
    debug::testBetaSSOnMP(stringSet);
    printf("\n");*/
    /*debug::testAlphaSSOnMP(stringSet);
    printf("\n");*/

    // debug::fullCompare(stringSet);

    debug::separatedFullCompare(stringSet);

    /*string pattern = "ccc";
    string text = "aababacacabaacaccccb";
    BetaSkipSearchMatcher betassm(pattern, text, 3);
    betassm.execute();
    betassm.printOutput();*/

    return 0;
}

