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
#include "testing/testutils.h"
#include "testing/stringset.h"

using namespace std;

int main() {
    srand(time(0));

    printf("Generating string set...\n");
    StringSet stringSet(10, 15, 100, 200, 'a', 'c', 1000000);

    /*printf("\n");
    debug::testKMPSSOnMP(stringSet);
    printf("\n");
    debug::testAlphaSSOnMP(stringSet);
    printf("\n");*/

    debug::fullCompare(stringSet);

    return 0;
}

