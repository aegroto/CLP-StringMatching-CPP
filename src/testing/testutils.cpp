#include "testutils.h"

using namespace std;

void debug::testKMPSSOnMP(StringSet &stringSet) {
    MorrisPrattMatcher *mpm = NULL;
    KMPSkipSearchMatcher *kmpssm = NULL;

    size_t t = 0;

    printf(ES_BRIGHTCYAN "-- TEST UTILS : KMP SKIP SEARCH\n-- Launching %zu tests with patterns and texts of lengths m = (%zu, %zu) and n = (%zu, %zu), alphabet is [%c, %c]\n",
            stringSet.dim, stringSet.minM, stringSet.maxM, stringSet.minN, stringSet.maxN, stringSet.minChar, stringSet.maxChar);
    printf("-- Testing against MORRIS-PRATT\n" ES_RESET);

    for(t = 0; t < stringSet.dim; ++t) {
        mpm = new MorrisPrattMatcher(stringSet.getPattern(t), stringSet.getText(t));
        mpm->execute();
        
        kmpssm = new KMPSkipSearchMatcher(stringSet.getPattern(t), stringSet.getText(t));
        kmpssm->execute();

        if(mpm->getOccurrences() != kmpssm->getOccurrences()) {
            printf(ES_RED "COMPARING FAILED!\n" ES_RESET);
            mpm->printOutput();
            kmpssm->printOutput();
            printf("\n");
            break;
        }

        delete mpm;
        delete kmpssm;
    }

    if(t < stringSet.dim)
        printf(ES_RED "[FAIL] ");
    else
        printf(ES_GREEN "[SUCCESS] ");

    printf("KMPss VS MP : %zu correct tests on %zu\n" ES_RESET, t, stringSet.dim);
}

void debug::testAlphaSSOnMP(StringSet &stringSet) {
    MorrisPrattMatcher *mpm = NULL;
    AlphaSkipSearchMatcher *alphassm = NULL;

    size_t t = 0;

    printf(ES_BRIGHTCYAN "-- TEST UTILS : ALPHA SKIP SEARCH\n-- Launching %zu tests with patterns and texts of lengths m = (%zu, %zu) and n = (%zu, %zu), alphabet is [%c, %c]\n",
            stringSet.dim, stringSet.minM, stringSet.maxM, stringSet.minN, stringSet.maxN, stringSet.minChar, stringSet.maxChar);
    printf("-- Testing against MORRIS-PRATT\n" ES_RESET);

    for(t = 0; t < stringSet.dim; ++t) {
        mpm = new MorrisPrattMatcher(stringSet.getPattern(t), stringSet.getText(t));
        mpm->execute();

        alphassm = new AlphaSkipSearchMatcher(stringSet.getPattern(t), stringSet.getText(t));
        alphassm->execute();

        if(mpm->getOccurrences() != alphassm->getOccurrences()) {
            printf(ES_RED "COMPARING FAILED!\n" ES_RESET);
            mpm->printOutput();
            alphassm->printOutput();
            printf("\n");
            break;
        }

        delete mpm;
        delete alphassm;
    }

    if(t < stringSet.dim)
        printf(ES_RED "[FAIL] ");
    else
        printf(ES_GREEN "[SUCCESS] ");

    printf("Alpha Skip search VS MP : %zu correct tests on %zu\n" ES_RESET, t, stringSet.dim);
}

void debug::fullCompare(StringSet& stringSet) {
    clock_t currentTime = 0, mpmTime = 0, kmpssTime = 0, alphassTime = 0;    
    size_t t = 0;

    printf(ES_BRIGHTCYAN "-- TEST UTILS : FULL COMPARE\n");
    printf("-- Launching a performance test on all algorithms implemented in this application.\n");
    printf("-- String set has " ES_BRIGHTMAGENTA "%zu" ES_BRIGHTCYAN " strings, ", stringSet.dim);
    printf("with patterns and texts of lengths " ES_BRIGHTMAGENTA "m = (%zu, %zu) " ES_CYAN, stringSet.minM, stringSet.maxM);
    printf("and " ES_BRIGHTMAGENTA "n = (%zu, %zu)" ES_CYAN ", alphabet is" ES_BRIGHTMAGENTA " [%c, %c]" ES_CYAN ".\n\n",
            stringSet.minN, stringSet.maxN, stringSet.minChar, stringSet.maxChar);

    printf("-- Measuring performances of MORRIS-PRATT\n");
    MorrisPrattMatcher *mpm = NULL;
    currentTime = clock();
    for(t = 0; t < stringSet.dim; ++t) {
        mpm = new MorrisPrattMatcher(stringSet.getPattern(t), stringSet.getText(t));
        mpm->execute();
        delete mpm;
    }
    mpmTime = clock() - currentTime;
    printf("-- " ES_BRIGHTMAGENTA "Morris-Pratt " ES_BRIGHTCYAN "made up the challenge in " ES_BRIGHTMAGENTA "%fs\n\n" ES_BRIGHTCYAN, double(mpmTime) / CLOCKS_PER_SEC);
    
    printf("-- Measuring performances of KMP SKIP SEARCH\n");
    KMPSkipSearchMatcher *kmpssm = NULL;
    currentTime = clock();
    for(t = 0; t < stringSet.dim; ++t) {
        kmpssm = new KMPSkipSearchMatcher(stringSet.getPattern(t), stringSet.getText(t));
        kmpssm->execute();
        delete kmpssm;
    }
    kmpssTime = clock() - currentTime;
    printf("-- " ES_BRIGHTMAGENTA "KMP Skip Search " ES_BRIGHTCYAN "made up the challenge in " ES_BRIGHTMAGENTA "%fs\n\n" ES_BRIGHTCYAN, double(kmpssTime) / CLOCKS_PER_SEC);

    printf("-- Measuring performances of ALPHA SKIP SEARCH\n");
    AlphaSkipSearchMatcher *alphassm = NULL;
    currentTime = clock();
    for(t = 0; t < stringSet.dim; ++t) {
        alphassm = new AlphaSkipSearchMatcher(stringSet.getPattern(t), stringSet.getText(t));
        alphassm->execute();
        delete alphassm;
    }
    alphassTime = clock() - currentTime;
    printf("-- " ES_BRIGHTMAGENTA "Alpha Skip Search " ES_BRIGHTCYAN "made up the challenge in " ES_BRIGHTMAGENTA "%fs\n\n" ES_BRIGHTCYAN, double(alphassTime) / CLOCKS_PER_SEC);
}