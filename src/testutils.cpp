#include "testutils.h"

using namespace std;

char inline debug::randchar(char minChar, char maxChar) { return char((rand() % (maxChar - minChar + 1)) + minChar); }

void debug::debugKMPSSOnMP(int m, int n, char minChar, char maxChar, int numTests) {
    string pattern, text;
    MorrisPrattMatcher *mpmatcher = NULL;
    KMPSkipSearchMatcher *kmpskipsearchmatcher = NULL;

    int positiveTests = 0;

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
            printf(ES_RED "COMPARING FAILED!\n" ES_CYAN);
            mpmatcher->printOutput();
            kmpskipsearchmatcher->printOutput();
            printf("\n");
            break;
        } else ++positiveTests;

        delete mpmatcher;
        delete kmpskipsearchmatcher;
    }

    if(positiveTests < numTests)
        printf(ES_RED "[FAIL] ");
    else
        printf(ES_GREEN "[SUCCESS] ");

    printf("KMPss VS MP : %i correct tests on %i\n" ES_RESET, positiveTests, numTests);
}
