#include <string>
#include <cstdlib>
#include <stdio.h>

#include "kmp-skipsearch.h"
#include "mp.h"
#include "testutils.h"

using namespace std;

char inline debug::randchar(char minChar, char maxChar) { return char((rand() % (maxChar - minChar + 1)) + minChar); }

void debug::debugKMPSSOnMP(int m, int n, char minChar, char maxChar, int numTests) {
    string pattern, text;
    MorrisPrattMatcher *mpmatcher = NULL;
    KMPSkipSearchMatcher *kmpskipsearchmatcher = NULL;

    for(int t = 0; t < numTests; ++t) {
        pattern.clear();
        text.clear();
        
        for(int c = 0; c < m; ++c)
            pattern += randchar(minChar, maxChar);

        for(int c = 0; c < n; ++c)
            text += randchar(minChar, maxChar);
        mpmatcher = new MorrisPrattMatcher(pattern, text);
        mpmatcher->execute();
        
        kmpskipsearchmatcher = new KMPSkipSearchMatcher(pattern, text);
        kmpskipsearchmatcher->execute();

        if(mpmatcher->getOccurrences() != kmpskipsearchmatcher->getOccurrences()) {
            printf("COMPARING FAILED!\n");
            mpmatcher->debugOutput();
            kmpskipsearchmatcher->debugOutput();
            
            break;
        }

        delete mpmatcher;
        delete kmpskipsearchmatcher;
    }
}
