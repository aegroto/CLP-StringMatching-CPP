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

using namespace std;

int main() {
    /*string pattern = "abcab";
    string text = "ababcabb";

    MorrisPrattMatcher mpmatcher(pattern, text);
    mpmatcher.execute();
    mpmatcher.debugOutput();

    LinearCLPMatcher linearclpmatcher(pattern, text);
    linearclpmatcher.execute();
    linearclpmatcher.debugOutput();*/

    srand(time(0));

    debug::debugOnMP(4, 15, 'a', 'c', 1000000);

    return 0;
}

