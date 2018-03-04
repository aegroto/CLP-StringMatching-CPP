/**
 * "MorrisPrattMatcher" class definition file
**/

#include <string>
#include <stdio.h>
#include "mp.h"

using namespace std;

MorrisPrattMatcher::MorrisPrattMatcher(string& sx, string& sy) {
    x = sx.c_str();
    y = sy.c_str();
    
    m = sx.length();
    n = sy.length();

    mpNext = new int[m + 1];   

    occurrences = 0; 

    executed = false;
}

MorrisPrattMatcher::~MorrisPrattMatcher() {
    delete[] mpNext;
}

void MorrisPrattMatcher::preprocessing() {
    int i, j;
    i = 0;
    j = mpNext[0] = -1;

    while (i < m) {
        while (j >= 0 && x[i] != x[j])
            j = mpNext[j];
        mpNext[++i] = ++j;
    }
}

void MorrisPrattMatcher::search() {
   int i, j;

   i = j = occurrences = 0;

    while (j < n) {
        while (i >= 0 && x[i] != y[j])
            i = mpNext[i];

        ++i; ++j;

        if (i >= m) {
            report(j - i);
            i = mpNext[i];
        }
    }
}

void MorrisPrattMatcher::report(int index) {
    ++occurrences;
}

void MorrisPrattMatcher::execute() {
    if(executed) return;
    preprocessing();
    search();
    executed = true;
}

void MorrisPrattMatcher::printOutput() {
    printf("\n-- MORRIS PRATT MATCHER --\nx: %s\ny: %s", x, y);

    printf("\nmpNext: ");
    for(int i = 0; i <= m; ++i) {
        if(mpNext[i] != -1) {
            printf("[%i] = %i ", i, mpNext[i]);
        }
    }

    printf("\noccurrences: %i\n", occurrences);
}
