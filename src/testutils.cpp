#include "testutils.h"
#include <iostream>

using namespace std;

char inline debug::randchar(char minChar, char maxChar) { 
    // printf("maxchar %i minChar %i\n", maxChar, minChar);
    return char((rand() % (maxChar - minChar + 1)) + minChar); 
}

void debug::debugKMPSSOnMP(int m, int n, char minChar, char maxChar, int numTests) {
    string pattern, text;
    MorrisPrattMatcher *mpmatcher = NULL;
    KMPSkipSearchMatcher *kmpskipsearchmatcher = NULL;

    int positiveTests = 0;

    printf("-- TEST UTILS : KMP SKIP SEARCH -- Launching %i tests with patterns and texts of lengths m = %i and n = %i, alphabet is [%c, %c]\n",
            numTests, m, n, minChar, maxChar);

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
            printf(ES_RED "COMPARING FAILED!\n" ES_RESET);
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

void debug::debugAlphaSSOnMP(int m, int n, char minChar, char maxChar, int numTests) {
    string pattern, text;
    MorrisPrattMatcher *mpm = NULL;
    AlphaSkipSearchMatcher *alphassm = NULL;

    int positiveTests = 0;

    printf("-- TEST UTILS : ALPHA SKIP SEARCH -- Launching %i tests with patterns and texts of lengths m = %i and n = %i, alphabet is [%c, %c]\n",
            numTests, m, n, minChar, maxChar);

    for(int t = 0; t < numTests; ++t) {
        pattern.clear();
        text.clear();

        for(int c = 0; c < m; ++c)
            pattern += randchar(minChar, maxChar);

        for(int c = 0; c < n; ++c)
            text += randchar(minChar, maxChar);

        // printf("testing on x = %s, y = %s\n", pattern.c_str(), text.c_str());

        mpm = new MorrisPrattMatcher(pattern, text);
        mpm->execute();

        alphassm = new AlphaSkipSearchMatcher(pattern, text);
        alphassm->execute();

        if(mpm->getOccurrences() != alphassm->getOccurrences()) {
            printf(ES_RED "COMPARING FAILED!\n" ES_RESET);
            mpm->printOutput();
            alphassm->printOutput();
            printf("\n");
            break;
        } else ++positiveTests;

        delete mpm;
        delete alphassm;
    }

    if(positiveTests < numTests)
        printf(ES_RED "[FAIL] ");
    else
        printf(ES_GREEN "[SUCCESS] ");

    printf("Alpha Skip search VS MP : %i correct tests on %i\n" ES_RESET, positiveTests, numTests);
}