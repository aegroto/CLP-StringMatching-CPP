/**
 * "TestUtils" namespace definition file
**/

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

        alphassm = new AlphaSkipSearchMatcher(stringSet.getPattern(t), stringSet.getText(t), stringSet.alphabetSize);
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

void debug::testBetaSSOnMP(StringSet &stringSet) {
    MorrisPrattMatcher *mpm = NULL;
    BetaSkipSearchMatcher *betassmp = NULL;

    size_t t = 0;

    printf(ES_BRIGHTCYAN "-- TEST UTILS : BETA SKIP SEARCH\n-- Launching %zu tests with patterns and texts of lengths m = (%zu, %zu) and n = (%zu, %zu), alphabet is [%c, %c]\n",
            stringSet.dim, stringSet.minM, stringSet.maxM, stringSet.minN, stringSet.maxN, stringSet.minChar, stringSet.maxChar);
    printf("-- Testing against MORRIS-PRATT\n" ES_RESET);

    for(t = 0; t < stringSet.dim; ++t) {
        mpm = new MorrisPrattMatcher(stringSet.getPattern(t), stringSet.getText(t));
        mpm->execute();

        betassmp = new BetaSkipSearchMatcher(stringSet.getPattern(t), stringSet.getText(t), stringSet.alphabetSize);
        betassmp->execute();

        if(mpm->getOccurrences() != betassmp->getOccurrences()) {
            printf(ES_RED "COMPARING FAILED!\n" ES_RESET);
            mpm->printOutput();
            betassmp->printOutput();
            printf("\n");
            break;
        }

        delete mpm;
        delete betassmp;
    }

    if(t < stringSet.dim)
        printf(ES_RED "[FAIL] ");
    else
        printf(ES_GREEN "[SUCCESS] ");

    printf("Beta Skip search VS MP : %zu correct tests on %zu\n" ES_RESET, t, stringSet.dim);
}

void debug::preprocessingCompare(StringSet& stringSet) {
    clock_t currentTime = 0, mpmTime = 0, kmpssTime = 0, alphassTime = 0, betassTime = 0;  
    size_t t = 0;

    printf(ES_BRIGHTCYAN "-- TEST UTILS : PREPROCESSING COMPARE\n");
    printf("-- Launching a performance test on all preprocessings of algorithms implemented in this application.\n");
    printf("-- String set has " ES_BRIGHTMAGENTA "%zu" ES_BRIGHTCYAN " strings, ", stringSet.dim);
    printf("with patterns and texts of lengths " ES_BRIGHTMAGENTA "m = (%zu, %zu) " ES_CYAN, stringSet.minM, stringSet.maxM);
    printf("and " ES_BRIGHTMAGENTA "n = (%zu, %zu)" ES_CYAN ", alphabet is" ES_BRIGHTMAGENTA " [%c, %c]" ES_CYAN ".\n\n",
            stringSet.minN, stringSet.maxN, stringSet.minChar, stringSet.maxChar);

    printf("-- Measuring preprocessing performances of MORRIS-PRATT\n");
    MorrisPrattMatcher *mpm = NULL;
    currentTime = clock();
    for(t = 0; t < stringSet.dim; ++t) {
        mpm = new MorrisPrattMatcher(stringSet.getPattern(t), stringSet.getText(t));
        mpm->preprocessing();
        delete mpm;
    }
    mpmTime = clock() - currentTime;
    printf("-- " ES_BRIGHTMAGENTA "Morris-Pratt " ES_BRIGHTCYAN "carried out the challenge in " ES_BRIGHTMAGENTA "%fs\n\n" ES_BRIGHTCYAN, double(mpmTime) / CLOCKS_PER_SEC);
    
    printf("-- Measuring preprocessing performances of KMP SKIP SEARCH\n");
    KMPSkipSearchMatcher *kmpssm = NULL;
    currentTime = clock();
    for(t = 0; t < stringSet.dim; ++t) {
        kmpssm = new KMPSkipSearchMatcher(stringSet.getPattern(t), stringSet.getText(t));
        kmpssm->preprocessing();
        delete kmpssm;
    }
    kmpssTime = clock() - currentTime;
    printf("-- " ES_BRIGHTMAGENTA "KMP Skip Search " ES_BRIGHTCYAN "carried out the challenge in " ES_BRIGHTMAGENTA "%fs\n\n" ES_BRIGHTCYAN, double(kmpssTime) / CLOCKS_PER_SEC);

    printf("-- Measuring preprocessing performances of ALPHA SKIP SEARCH\n");
    AlphaSkipSearchMatcher *alphassm = NULL;
    currentTime = clock();
    for(t = 0; t < stringSet.dim; ++t) {
        alphassm = new AlphaSkipSearchMatcher(stringSet.getPattern(t), stringSet.getText(t), stringSet.alphabetSize);
        alphassm->preprocessing();
        delete alphassm;
    }
    alphassTime = clock() - currentTime;
    printf("-- " ES_BRIGHTMAGENTA "Alpha Skip Search " ES_BRIGHTCYAN "carried out the challenge in " ES_BRIGHTMAGENTA "%fs\n\n" ES_BRIGHTCYAN, double(alphassTime) / CLOCKS_PER_SEC);

    printf("-- Measuring preprocessing performances of BETA SKIP SEARCH\n");
    BetaSkipSearchMatcher *betassm = NULL;
    currentTime = clock();
    for(t = 0; t < stringSet.dim; ++t) {
        betassm = new BetaSkipSearchMatcher(stringSet.getPattern(t), stringSet.getText(t), stringSet.alphabetSize);
        betassm->preprocessing();
        delete betassm;
    }
    betassTime = clock() - currentTime;
    printf("-- " ES_BRIGHTMAGENTA "Beta Skip Search " ES_BRIGHTCYAN "carried out the challenge in " ES_BRIGHTMAGENTA "%fs\n\n" ES_BRIGHTCYAN, double(betassTime) / CLOCKS_PER_SEC);
}


void debug::fullCompare(StringSet& stringSet) {
    clock_t currentTime = 0, mpmTime = 0, kmpssTime = 0, alphassTime = 0, betassTime = 0;  
    size_t t = 0;

    printf(ES_BRIGHTCYAN "-- TEST UTILS : FULL COMPARE\n");
    printf("-- Launching a performance test on all algorithms implemented in this application.\n");
    printf("-- String set has " ES_BRIGHTMAGENTA "%zu" ES_BRIGHTCYAN " strings, ", stringSet.dim);
    printf("with patterns and texts of lengths " ES_BRIGHTMAGENTA "m = (%zu, %zu) " ES_CYAN, stringSet.minM, stringSet.maxM);
    printf("and " ES_BRIGHTMAGENTA "n = (%zu, %zu)" ES_CYAN ", alphabet is" ES_BRIGHTMAGENTA " [%c, %c]" ES_CYAN ".\n\n",
            stringSet.minN, stringSet.maxN, stringSet.minChar, stringSet.maxChar);

    // printf("-- Measuring performances of MORRIS-PRATT\n");
    MorrisPrattMatcher *mpm = NULL;
    currentTime = clock();
    for(t = 0; t < stringSet.dim; ++t) {
        mpm = new MorrisPrattMatcher(stringSet.getPattern(t), stringSet.getText(t));
        mpm->execute();
        delete mpm;
    }
    mpmTime = clock() - currentTime;
    printf("-- " ES_BRIGHTMAGENTA "Morris-Pratt " ES_BRIGHTCYAN "carried out the challenge in...\t\t" ES_BRIGHTMAGENTA "%fs\n" ES_BRIGHTCYAN, double(mpmTime) / CLOCKS_PER_SEC);
    
    // printf("-- Measuring performances of KMP SKIP SEARCH\n");
    KMPSkipSearchMatcher *kmpssm = NULL;
    currentTime = clock();
    for(t = 0; t < stringSet.dim; ++t) {
        kmpssm = new KMPSkipSearchMatcher(stringSet.getPattern(t), stringSet.getText(t));
        kmpssm->execute();
        delete kmpssm;
    }
    kmpssTime = clock() - currentTime;
    printf("-- " ES_BRIGHTMAGENTA "KMP Skip Search " ES_BRIGHTCYAN "carried out the challenge in...\t" ES_BRIGHTMAGENTA "%fs\n" ES_BRIGHTCYAN, double(kmpssTime) / CLOCKS_PER_SEC);
    
    // printf("-- Measuring performances of ALPHA SKIP SEARCH\n");
    AlphaSkipSearchMatcher *alphassm = NULL;
    currentTime = clock();

    for(t = 0; t < stringSet.dim; ++t) {
        alphassm = new AlphaSkipSearchMatcher(stringSet.getPattern(t), stringSet.getText(t), stringSet.alphabetSize);
        alphassm->execute();
        delete alphassm;
    }
    alphassTime = clock() - currentTime;
    printf("-- " ES_BRIGHTMAGENTA "Alpha Skip Search " ES_BRIGHTCYAN "carried out the challenge in...\t" ES_BRIGHTMAGENTA "%fs\n" ES_BRIGHTCYAN, double(alphassTime) / CLOCKS_PER_SEC);

    // printf("-- Measuring performances of BETA SKIP SEARCH\n");
    BetaSkipSearchMatcher *betassm = NULL;
    currentTime = clock();
    for(t = 0; t < stringSet.dim; ++t) {
        betassm = new BetaSkipSearchMatcher(stringSet.getPattern(t), stringSet.getText(t), stringSet.alphabetSize);
        betassm->execute();
        delete betassm;
    }
    betassTime = clock() - currentTime;
    printf("-- " ES_BRIGHTMAGENTA "Beta Skip Search " ES_BRIGHTCYAN "carried out the challenge in...\t" ES_BRIGHTMAGENTA "%fs\n" ES_BRIGHTCYAN, double(betassTime) / CLOCKS_PER_SEC);
    printf("\n");
}

void debug::separatedFullCompare(StringSet& stringSet) {
    clock_t currentTime = 0, 
            mpCDTime = 0, kmpssCDTime = 0, alphassCDTime = 0, betassCDTime = 0,
            mpPTime = 0, kmpssPTime = 0, alphassPTime = 0, betassPTime = 0,
            mpSTime = 0, kmpssSTime = 0, alphassSTime = 0, betassSTime = 0;

    double cdTimeSec = 0, pTimeSec = 0, sTimeSec = 0;  

    size_t t = 0;

    printf(ES_BRIGHTCYAN "-- TEST UTILS : SEPARATED FULL COMPARE\n");
    printf("-- Launching a performance test on all algorithms implemented in this application, separating construction/destruction, preprocessing and searching.\n");
    printf("-- String set has " ES_BRIGHTMAGENTA "%zu" ES_BRIGHTCYAN " strings, ", stringSet.dim);
    printf("with patterns and texts of lengths " ES_BRIGHTMAGENTA "m = (%zu, %zu) " ES_CYAN, stringSet.minM, stringSet.maxM);
    printf("and " ES_BRIGHTMAGENTA "n = (%zu, %zu)" ES_CYAN ", alphabet is" ES_BRIGHTMAGENTA " [%c, %c]" ES_CYAN ".\n\n",
            stringSet.minN, stringSet.maxN, stringSet.minChar, stringSet.maxChar);

    MorrisPrattMatcher *mpm = NULL;
    for(t = 0; t < stringSet.dim; ++t) {
        currentTime = clock();
        mpm = new MorrisPrattMatcher(stringSet.getPattern(t), stringSet.getText(t));
        mpCDTime += clock() - currentTime;

        currentTime = clock();
        mpm->preprocessing();
        mpPTime += clock() - currentTime;

        currentTime = clock();
        mpm->search();
        mpSTime += clock() - currentTime;

        currentTime = clock();
        delete mpm;
        mpCDTime += clock() - currentTime;
    }
    cdTimeSec = double(mpCDTime) / CLOCKS_PER_SEC;
    pTimeSec = double(mpPTime) / CLOCKS_PER_SEC;
    sTimeSec = double(mpSTime) / CLOCKS_PER_SEC;

    printf(ES_BRIGHTCYAN "-- " ES_BRIGHTMAGENTA "Morris-Pratt " ES_BRIGHTCYAN "carried out the challenge in...\t\t");
    printf("CD: " ES_BRIGHTMAGENTA "%fs" ES_BRIGHTCYAN ", ", cdTimeSec);
    printf("P: " ES_BRIGHTMAGENTA "%fs" ES_BRIGHTCYAN ", ", pTimeSec);
    printf("S: " ES_BRIGHTMAGENTA "%fs" ES_BRIGHTCYAN ", ", sTimeSec);
    printf("T: " ES_BRIGHTMAGENTA "%fs\n", cdTimeSec + pTimeSec + sTimeSec);

    KMPSkipSearchMatcher *kmpssm = NULL;
    for(t = 0; t < stringSet.dim; ++t) {
        currentTime = clock();
        kmpssm = new KMPSkipSearchMatcher(stringSet.getPattern(t), stringSet.getText(t));
        kmpssCDTime += clock() - currentTime;

        currentTime = clock();
        kmpssm->preprocessing();
        kmpssPTime += clock() - currentTime;

        currentTime = clock();
        kmpssm->search();
        kmpssSTime += clock() - currentTime;

        currentTime = clock();
        delete kmpssm;
        kmpssCDTime += clock() - currentTime;
    }
    cdTimeSec = double(kmpssCDTime) / CLOCKS_PER_SEC;
    pTimeSec = double(kmpssPTime) / CLOCKS_PER_SEC;
    sTimeSec = double(kmpssSTime) / CLOCKS_PER_SEC;

    printf(ES_BRIGHTCYAN "-- " ES_BRIGHTMAGENTA "KMP Skip Search " ES_BRIGHTCYAN "carried out the challenge in...\t");
    printf("CD: " ES_BRIGHTMAGENTA "%fs" ES_BRIGHTCYAN ", ", cdTimeSec);
    printf("P: " ES_BRIGHTMAGENTA "%fs" ES_BRIGHTCYAN ", ", pTimeSec);
    printf("S: " ES_BRIGHTMAGENTA "%fs" ES_BRIGHTCYAN ", ", sTimeSec);
    printf("T: " ES_BRIGHTMAGENTA "%fs\n", cdTimeSec + pTimeSec + sTimeSec);

    AlphaSkipSearchMatcher *alphassm = NULL;
    for(t = 0; t < stringSet.dim; ++t) {
        currentTime = clock();
        alphassm = new AlphaSkipSearchMatcher(stringSet.getPattern(t), stringSet.getText(t), stringSet.alphabetSize);
        alphassCDTime += clock() - currentTime;

        currentTime = clock();
        alphassm->preprocessing();
        alphassPTime += clock() - currentTime;

        currentTime = clock();
        alphassm->search();
        alphassSTime += clock() - currentTime;

        currentTime = clock();
        delete alphassm;
        alphassCDTime += clock() - currentTime;
    }
    cdTimeSec = double(alphassCDTime) / CLOCKS_PER_SEC;
    pTimeSec = double(alphassPTime) / CLOCKS_PER_SEC;
    sTimeSec = double(alphassSTime) / CLOCKS_PER_SEC;

    printf(ES_BRIGHTCYAN "-- " ES_BRIGHTMAGENTA "Alpha Skip Search " ES_BRIGHTCYAN "carried out the challenge in...\t");
    printf("CD: " ES_BRIGHTMAGENTA "%fs" ES_BRIGHTCYAN ", ", cdTimeSec);
    printf("P: " ES_BRIGHTMAGENTA "%fs" ES_BRIGHTCYAN ", ", pTimeSec);
    printf("S: " ES_BRIGHTMAGENTA "%fs" ES_BRIGHTCYAN ", ", sTimeSec);
    printf("T: " ES_BRIGHTMAGENTA "%fs\n", cdTimeSec + pTimeSec + sTimeSec);

    BetaSkipSearchMatcher *betassm = NULL;
    for(t = 0; t < stringSet.dim; ++t) {
        currentTime = clock();
        betassm = new BetaSkipSearchMatcher(stringSet.getPattern(t), stringSet.getText(t), stringSet.alphabetSize);
        betassCDTime += clock() - currentTime;

        currentTime = clock();
        betassm->preprocessing();
        betassPTime += clock() - currentTime;

        currentTime = clock();
        betassm->search();
        betassSTime += clock() - currentTime;

        currentTime = clock();
        delete betassm;
        betassCDTime += clock() - currentTime;
    }
    cdTimeSec = double(betassCDTime) / CLOCKS_PER_SEC;
    pTimeSec = double(betassPTime) / CLOCKS_PER_SEC;
    sTimeSec = double(betassSTime) / CLOCKS_PER_SEC;

    printf(ES_BRIGHTCYAN "-- " ES_BRIGHTMAGENTA "Beta Skip Search " ES_BRIGHTCYAN "carried out the challenge in...\t");
    printf("CD: " ES_BRIGHTMAGENTA "%fs" ES_BRIGHTCYAN ", ", cdTimeSec);
    printf("P: " ES_BRIGHTMAGENTA "%fs" ES_BRIGHTCYAN ", ", pTimeSec);
    printf("S: " ES_BRIGHTMAGENTA "%fs" ES_BRIGHTCYAN ", ", sTimeSec);
    printf("T: " ES_BRIGHTMAGENTA "%fs\n", cdTimeSec + pTimeSec + sTimeSec);
}