/**
 * Skip Search - A very fast string matching algorithm for small alphabets and long patterns
 * Original Algorithm by C. Charras, T. Lecroq, J. D. Pehoushek.
 * C++ implementation by Lorenzo Catania and Valentino Merlino
**/

#include <stdio.h>
#include <string>
#include <ctime>
#include <cstdlib>

#include "helpers.h"
#include "testing/testutils.h"
#include "testing/stringset.h"

#include "alphatrie/betatrie.h"

#include "alpha_skipsearch/beta_skipsearch.h"

using namespace std;

int main() {
    srand(time(0));

    printf("Generating string set...\n");
    StringSet stringSet(3, 5, 10, 15, 'a', 'b', 10);

    /*printf("\n");
    debug::testKMPSSOnMP(stringSet);
    printf("\n");*/
    /*debug::testAlphaSSOnMP(stringSet);
    printf("\n");*/
    /*debug::testBetaSSOnMP(stringSet);
    printf("\n");*/

    string pattern = "abbb";
    string text = "aabbbabaaaaabba";
    BetaSkipSearchMatcher betassm(pattern, text, 3);
    betassm.execute();
    betassm.printOutput();

    // debug::fullCompare(stringSet);

    /*string pattern = "abcabaabca";
    BetaTrie betaTrie(pattern.c_str(), pattern.length(), 3);
    betaTrie.print(pattern.c_str(), pattern.length());*/

    return 0;
}

