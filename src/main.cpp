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

#include "gamma_skipsearch/gamma_skipsearch.h"

using namespace std;

int main() {
    srand(time(0));

    printf("Generating string set...\n");
    StringSet stringSet(300,
                        500,
                        10000,
                        20000,
                        'a', 'c',
                        10000);

    // debug::testSSOnMP(stringSet); printf("\n");
    // debug::testKMPSSOnMP(stringSet); printf("\n");
    // debug::testAlphaSSOnMP(stringSet); printf("\n");
    // debug::testBetaSSOnMP(stringSet); printf("\n");
    // debug::testGammaSSOnMP(stringSet); printf("\n");

    // debug::fullCompare(stringSet);

    // debug::separatedFullCompare(stringSet);

    /*string pattern = "cba";
    string text = "abbccbcbab";
    GammaSkipSearchMatcher gammassm(pattern, text, 'a', 'c');
    gammassm.execute();
    gammassm.printOutput();*/

    return 0;
}

