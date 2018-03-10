/**
 * "TestUtils" namespace definition file
 *
 * Lorenzo Catania
**/

#include "testutils.h"

using namespace std;

void debug::testSSOnMP(StringSet &stringSet) {
    MorrisPrattMatcher *mpm = NULL;
    SkipSearchMatcher *ssm = NULL;

    size_t t = 0;

    printf(ES_BRIGHTCYAN "-- TEST UTILS : SKIP SEARCH\n-- Launching %zu tests with patterns and texts of lengths m = (%zu, %zu) and n = (%zu, %zu), alphabet is [%c, %c]\n",
            stringSet.dim, stringSet.minM, stringSet.maxM, stringSet.minN, stringSet.maxN, stringSet.minChar, stringSet.maxChar);
    printf("-- Testing against MORRIS-PRATT\n" ES_RESET);

    for(t = 0; t < stringSet.dim; ++t) {
        mpm = new MorrisPrattMatcher(stringSet.getPattern(t), stringSet.getText(t));
        mpm->execute();
        
        ssm = new SkipSearchMatcher(stringSet.getPattern(t), stringSet.getText(t));
        ssm->execute();

        if(mpm->getOccurrences() != ssm->getOccurrences()) {
            printf(ES_RED "COMPARING FAILED!\n" ES_RESET);
            mpm->printOutput();
            ssm->printOutput();
            printf("\n");
            break;
        }

        delete mpm;
        delete ssm;
    }

    if(t < stringSet.dim)
        printf(ES_RED "[FAIL] ");
    else
        printf(ES_GREEN "[SUCCESS] ");

    printf("KMPss VS MP : %zu correct tests on %zu\n" ES_RESET, t, stringSet.dim);
}

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

void debug::testGammaSSOnMP(StringSet &stringSet) {
    MorrisPrattMatcher *mpm = NULL;
    GammaSkipSearchMatcher *gammassmp = NULL;

    size_t t = 0;

    printf(ES_BRIGHTCYAN "-- TEST UTILS : GAMMA SKIP SEARCH\n-- Launching %zu tests with patterns and texts of lengths m = (%zu, %zu) and n = (%zu, %zu), alphabet is [%c, %c]\n",
            stringSet.dim, stringSet.minM, stringSet.maxM, stringSet.minN, stringSet.maxN, stringSet.minChar, stringSet.maxChar);
    printf("-- Testing against MORRIS-PRATT\n" ES_RESET);

    for(t = 0; t < stringSet.dim; ++t) {
        mpm = new MorrisPrattMatcher(stringSet.getPattern(t), stringSet.getText(t));
        mpm->execute();

        gammassmp = new GammaSkipSearchMatcher(stringSet.getPattern(t), stringSet.getText(t), stringSet.minChar, stringSet.maxChar);
        gammassmp->execute();

        if(mpm->getOccurrences() != gammassmp->getOccurrences()) {
            printf(ES_RED "COMPARING FAILED!\n" ES_RESET);
            mpm->printOutput();
            gammassmp->printOutput();
            printf("\n");
            break;
        }

        delete mpm;
        delete gammassmp;
    }

    if(t < stringSet.dim)
        printf(ES_RED "[FAIL] ");
    else
        printf(ES_GREEN "[SUCCESS] ");

    printf("Gamma Skip search VS MP : %zu correct tests on %zu\n" ES_RESET, t, stringSet.dim);
}

void debug::fileSearchCompare(string pattern, string filePath, char minAlphabetChar, char maxAlphabetChar) {
    clock_t currentTime = 0, sTime = 0;

    printf(ES_BRIGHTCYAN "-- TEST UTILS : FILE SEARCH COMPARE\n-- Launching a performance test on all algorithms implemented in this application\n");
    printf("-- Searching for pattern " ES_BRIGHTMAGENTA "\"%s\" " ES_BRIGHTCYAN "in file "ES_BRIGHTMAGENTA "\"%s\"\n\n", pattern.c_str(), filePath.c_str());

    ifstream file(filePath.c_str());
    string text((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());

    MorrisPrattMatcher *mpm = NULL;
    currentTime = clock();
    mpm = new MorrisPrattMatcher(pattern, text);
    mpm->execute();
    delete mpm;
    sTime = clock() - currentTime;
    printf(ES_BRIGHTCYAN "-- " ES_BRIGHTMAGENTA "Morris-Pratt " ES_BRIGHTCYAN "carried out the challenge in...\t\t" ES_BRIGHTMAGENTA "%fs\n" ES_BRIGHTCYAN, double(sTime) / CLOCKS_PER_SEC);
    
    SkipSearchMatcher *ssm = NULL;
    currentTime = clock();
    ssm = new SkipSearchMatcher(pattern, text);
    ssm->execute();
    delete ssm;
    sTime = clock() - currentTime;
    printf(ES_BRIGHTCYAN "-- " ES_BRIGHTMAGENTA "Skip Search " ES_BRIGHTCYAN "carried out the challenge in...\t\t" ES_BRIGHTMAGENTA "%fs\n" ES_BRIGHTCYAN, double(sTime) / CLOCKS_PER_SEC);
    
    KMPSkipSearchMatcher *kmpssm = NULL;
    currentTime = clock();
    kmpssm = new KMPSkipSearchMatcher(pattern, text);
    kmpssm->execute();
    delete kmpssm;
    sTime = clock() - currentTime;
    printf(ES_BRIGHTCYAN "-- " ES_BRIGHTMAGENTA "KMP Skip Search " ES_BRIGHTCYAN "carried out the challenge in...\t" ES_BRIGHTMAGENTA "%fs\n" ES_BRIGHTCYAN, double(sTime) / CLOCKS_PER_SEC);

    AlphaSkipSearchMatcher *alphassm = NULL;
    currentTime = clock();
    alphassm = new AlphaSkipSearchMatcher(pattern, text, int(maxAlphabetChar - minAlphabetChar + 1));
    alphassm->execute();
    delete alphassm;
    sTime = clock() - currentTime;
    printf(ES_BRIGHTCYAN "-- " ES_BRIGHTMAGENTA "Alpha Skip Search " ES_BRIGHTCYAN "carried out the challenge in...\t" ES_BRIGHTMAGENTA "%fs\n" ES_BRIGHTCYAN, double(sTime) / CLOCKS_PER_SEC);
       
    BetaSkipSearchMatcher *betassm = NULL;
    currentTime = clock();
    betassm = new BetaSkipSearchMatcher(pattern, text, int(maxAlphabetChar - minAlphabetChar + 1));
    betassm->execute();
    delete betassm;
    sTime = clock() - currentTime;
    printf(ES_BRIGHTCYAN "-- " ES_BRIGHTMAGENTA "Beta Skip Search " ES_BRIGHTCYAN "carried out the challenge in...\t" ES_BRIGHTMAGENTA "%fs\n" ES_BRIGHTCYAN, double(sTime) / CLOCKS_PER_SEC);
    
    GammaSkipSearchMatcher *gammassm = NULL;
    currentTime = clock();
    gammassm = new GammaSkipSearchMatcher(pattern, text, minAlphabetChar, maxAlphabetChar);
    gammassm->execute();
    delete gammassm;
    sTime = clock() - currentTime;
    printf(ES_BRIGHTCYAN "-- " ES_BRIGHTMAGENTA "Gamma Skip Search " ES_BRIGHTCYAN "carried out the challenge in...\t" ES_BRIGHTMAGENTA "%fs\n" ES_BRIGHTCYAN, double(sTime) / CLOCKS_PER_SEC);
}

void debug::fullCompare(StringSet& stringSet) {
    clock_t currentTime = 0, 
            sTime = 0;  
    size_t t = 0;

    printf(ES_BRIGHTCYAN "-- TEST UTILS : FULL COMPARE\n");
    printf("-- Launching a performance test on all algorithms implemented in this application.\n");
    printf("-- String set has " ES_BRIGHTMAGENTA "%zu" ES_BRIGHTCYAN " strings, ", stringSet.dim);
    printf("with patterns and texts of lengths " ES_BRIGHTMAGENTA "m = (%zu, %zu) " ES_BRIGHTCYAN, stringSet.minM, stringSet.maxM);
    printf("and " ES_BRIGHTMAGENTA "n = (%zu, %zu)" ES_BRIGHTCYAN ", alphabet is" ES_BRIGHTMAGENTA " [%c, %c]" ES_BRIGHTCYAN ".\n\n",
            stringSet.minN, stringSet.maxN, stringSet.minChar, stringSet.maxChar);

    
    MorrisPrattMatcher *mpm = NULL;
    currentTime = clock();
    for(t = 0; t < stringSet.dim; ++t) {
        mpm = new MorrisPrattMatcher(stringSet.getPattern(t), stringSet.getText(t));
        mpm->execute();
        delete mpm;
    }
    sTime = clock() - currentTime;
    printf("-- " ES_BRIGHTMAGENTA "Morris-Pratt " ES_BRIGHTCYAN "carried out the challenge in...\t\t" ES_BRIGHTMAGENTA "%fs\n" ES_BRIGHTCYAN, double(sTime) / CLOCKS_PER_SEC);
    
    SkipSearchMatcher *ssm = NULL;
    currentTime = clock();
    for(t = 0; t < stringSet.dim; ++t) {
        ssm = new SkipSearchMatcher(stringSet.getPattern(t), stringSet.getText(t));
        ssm->execute();
        delete ssm;
    }
    sTime = clock() - currentTime;
    printf("-- " ES_BRIGHTMAGENTA "Skip Search " ES_BRIGHTCYAN "carried out the challenge in...\t\t" ES_BRIGHTMAGENTA "%fs\n" ES_BRIGHTCYAN, double(sTime) / CLOCKS_PER_SEC);
    
    KMPSkipSearchMatcher *kmpssm = NULL;
    currentTime = clock();
    for(t = 0; t < stringSet.dim; ++t) {
        kmpssm = new KMPSkipSearchMatcher(stringSet.getPattern(t), stringSet.getText(t));
        kmpssm->execute();
        delete kmpssm;
    }
    sTime = clock() - currentTime;
    printf("-- " ES_BRIGHTMAGENTA "KMP Skip Search " ES_BRIGHTCYAN "carried out the challenge in...\t" ES_BRIGHTMAGENTA "%fs\n" ES_BRIGHTCYAN, double(sTime) / CLOCKS_PER_SEC);
    
    
    AlphaSkipSearchMatcher *alphassm = NULL;
    currentTime = clock();

    for(t = 0; t < stringSet.dim; ++t) {
        alphassm = new AlphaSkipSearchMatcher(stringSet.getPattern(t), stringSet.getText(t), stringSet.alphabetSize);
        alphassm->execute();
        delete alphassm;
    }
    sTime = clock() - currentTime;
    printf("-- " ES_BRIGHTMAGENTA "Alpha Skip Search " ES_BRIGHTCYAN "carried out the challenge in...\t" ES_BRIGHTMAGENTA "%fs\n" ES_BRIGHTCYAN, double(sTime) / CLOCKS_PER_SEC);

    BetaSkipSearchMatcher *betassm = NULL;
    currentTime = clock();
    for(t = 0; t < stringSet.dim; ++t) {
        betassm = new BetaSkipSearchMatcher(stringSet.getPattern(t), stringSet.getText(t), stringSet.alphabetSize);
        betassm->execute();
        delete betassm;
    }
    sTime = clock() - currentTime;
    printf("-- " ES_BRIGHTMAGENTA "Beta Skip Search " ES_BRIGHTCYAN "carried out the challenge in...\t" ES_BRIGHTMAGENTA "%fs\n" ES_BRIGHTCYAN, double(sTime) / CLOCKS_PER_SEC);
    
    GammaSkipSearchMatcher *gammassm = NULL;
    currentTime = clock();
    for(t = 0; t < stringSet.dim; ++t) {
        gammassm = new GammaSkipSearchMatcher(stringSet.getPattern(t), stringSet.getText(t), stringSet.minChar, stringSet.maxChar);
        gammassm->execute();
        delete gammassm;
    }
    sTime = clock() - currentTime;
    printf("-- " ES_BRIGHTMAGENTA "Gamma Skip Search " ES_BRIGHTCYAN "carried out the challenge in...\t" ES_BRIGHTMAGENTA "%fs\n" ES_BRIGHTCYAN, double(sTime) / CLOCKS_PER_SEC);
    
    printf("\n");
}

void debug::separatedFullCompare(StringSet& stringSet) {
    clock_t currentTime = 0, 
            cTime, pTime, sTime, dTime;

    double cTimeSec, pTimeSec, sTimeSec, dTimeSec;  

    size_t t;

    printf(ES_BRIGHTCYAN "-- TEST UTILS : SEPARATED FULL COMPARE\n");
    printf("-- Launching a performance test on all algorithms implemented in this application, separating construction/destruction, preprocessing and searching.\n");
    printf("-- String set has " ES_BRIGHTMAGENTA "%zu" ES_BRIGHTCYAN " strings, ", stringSet.dim);
    printf("with patterns and texts of lengths " ES_BRIGHTMAGENTA "m = (%zu, %zu) " ES_BRIGHTCYAN, stringSet.minM, stringSet.maxM);
    printf("and " ES_BRIGHTMAGENTA "n = (%zu, %zu)" ES_BRIGHTCYAN ", alphabet is" ES_BRIGHTMAGENTA " [%c, %c]" ES_BRIGHTCYAN ".\n\n",
            stringSet.minN, stringSet.maxN, stringSet.minChar, stringSet.maxChar);

    MorrisPrattMatcher *mpm = NULL;
    cTime = pTime = sTime = dTime = 0;
    for(t = 0; t < stringSet.dim; ++t) {
        currentTime = clock();
        mpm = new MorrisPrattMatcher(stringSet.getPattern(t), stringSet.getText(t));
        cTime += clock() - currentTime;

        currentTime = clock();
        mpm->preprocessing();
        pTime += clock() - currentTime;

        currentTime = clock();
        mpm->search();
        sTime += clock() - currentTime;

        currentTime = clock();
        delete mpm;
        dTime += clock() - currentTime;
    }
    cTimeSec = double(cTime) / CLOCKS_PER_SEC;
    pTimeSec = double(pTime) / CLOCKS_PER_SEC;
    sTimeSec = double(sTime) / CLOCKS_PER_SEC;
    dTimeSec = double(dTime) / CLOCKS_PER_SEC;

    printf(ES_BRIGHTCYAN "-- " ES_BRIGHTMAGENTA "Morris-Pratt " ES_BRIGHTCYAN "carried out the challenge in...\t\t");
    printf("C: " ES_BRIGHTMAGENTA "%fs" ES_BRIGHTCYAN ", ", cTimeSec);
    printf("P: " ES_BRIGHTMAGENTA "%fs" ES_BRIGHTCYAN ", ", pTimeSec);
    printf("S: " ES_BRIGHTMAGENTA "%fs" ES_BRIGHTCYAN ", ", sTimeSec);
    printf("D: " ES_BRIGHTMAGENTA "%fs" ES_BRIGHTCYAN ", ", dTimeSec);
    printf("T: " ES_BRIGHTMAGENTA "%fs\n" ES_RESET, cTimeSec + pTimeSec + sTimeSec + dTimeSec);

    SkipSearchMatcher *ssm = NULL;
    cTime = pTime = sTime = dTime = 0;
    for(t = 0; t < stringSet.dim; ++t) {
        currentTime = clock();
        ssm = new SkipSearchMatcher(stringSet.getPattern(t), stringSet.getText(t));
        cTime += clock() - currentTime;

        currentTime = clock();
        ssm->preprocessing();
        pTime += clock() - currentTime;

        currentTime = clock();
        ssm->search();
        sTime += clock() - currentTime;

        currentTime = clock();
        delete ssm;
        dTime += clock() - currentTime;
    }
    cTimeSec = double(cTime) / CLOCKS_PER_SEC;
    pTimeSec = double(pTime) / CLOCKS_PER_SEC;
    sTimeSec = double(sTime) / CLOCKS_PER_SEC;
    dTimeSec = double(dTime) / CLOCKS_PER_SEC;

    printf(ES_BRIGHTCYAN "-- " ES_BRIGHTMAGENTA "Skip Search " ES_BRIGHTCYAN "carried out the challenge in...\t\t");
    printf("C: " ES_BRIGHTMAGENTA "%fs" ES_BRIGHTCYAN ", ", cTimeSec);
    printf("P: " ES_BRIGHTMAGENTA "%fs" ES_BRIGHTCYAN ", ", pTimeSec);
    printf("S: " ES_BRIGHTMAGENTA "%fs" ES_BRIGHTCYAN ", ", sTimeSec);
    printf("D: " ES_BRIGHTMAGENTA "%fs" ES_BRIGHTCYAN ", ", dTimeSec);
    printf("T: " ES_BRIGHTMAGENTA "%fs\n" ES_RESET, cTimeSec + pTimeSec + sTimeSec + dTimeSec);

    KMPSkipSearchMatcher *kmpssm = NULL;
    cTime = pTime = sTime = dTime = 0;
    for(t = 0; t < stringSet.dim; ++t) {
        currentTime = clock();
        kmpssm = new KMPSkipSearchMatcher(stringSet.getPattern(t), stringSet.getText(t));
        cTime += clock() - currentTime;

        currentTime = clock();
        kmpssm->preprocessing();
        pTime += clock() - currentTime;

        currentTime = clock();
        kmpssm->search();
        sTime += clock() - currentTime;

        currentTime = clock();
        delete kmpssm;
        dTime += clock() - currentTime;
    }
    cTimeSec = double(cTime) / CLOCKS_PER_SEC;
    pTimeSec = double(pTime) / CLOCKS_PER_SEC;
    sTimeSec = double(sTime) / CLOCKS_PER_SEC;
    dTimeSec = double(dTime) / CLOCKS_PER_SEC;

    printf(ES_BRIGHTCYAN "-- " ES_BRIGHTMAGENTA "KMP Skip Search " ES_BRIGHTCYAN "carried out the challenge in...\t");
    printf("C: " ES_BRIGHTMAGENTA "%fs" ES_BRIGHTCYAN ", ", cTimeSec);
    printf("P: " ES_BRIGHTMAGENTA "%fs" ES_BRIGHTCYAN ", ", pTimeSec);
    printf("S: " ES_BRIGHTMAGENTA "%fs" ES_BRIGHTCYAN ", ", sTimeSec);
    printf("D: " ES_BRIGHTMAGENTA "%fs" ES_BRIGHTCYAN ", ", dTimeSec);
    printf("T: " ES_BRIGHTMAGENTA "%fs\n" ES_RESET, cTimeSec + pTimeSec + sTimeSec + dTimeSec);

    AlphaSkipSearchMatcher *alphassm = NULL;
    cTime = pTime = sTime = dTime = 0;
    for(t = 0; t < stringSet.dim; ++t) {
        currentTime = clock();
        alphassm = new AlphaSkipSearchMatcher(stringSet.getPattern(t), stringSet.getText(t), stringSet.alphabetSize);
        cTime += clock() - currentTime;

        currentTime = clock();
        alphassm->preprocessing();
        pTime += clock() - currentTime;

        currentTime = clock();
        alphassm->search();
        sTime += clock() - currentTime;

        currentTime = clock();
        delete alphassm;
        dTime += clock() - currentTime;
    }
    cTimeSec = double(cTime) / CLOCKS_PER_SEC;
    pTimeSec = double(pTime) / CLOCKS_PER_SEC;
    sTimeSec = double(sTime) / CLOCKS_PER_SEC;
    dTimeSec = double(dTime) / CLOCKS_PER_SEC;

    printf(ES_BRIGHTCYAN "-- " ES_BRIGHTMAGENTA "Alpha Skip Search " ES_BRIGHTCYAN "carried out the challenge in...\t");
    printf("C: " ES_BRIGHTMAGENTA "%fs" ES_BRIGHTCYAN ", ", cTimeSec);
    printf("P: " ES_BRIGHTMAGENTA "%fs" ES_BRIGHTCYAN ", ", pTimeSec);
    printf("S: " ES_BRIGHTMAGENTA "%fs" ES_BRIGHTCYAN ", ", sTimeSec);
    printf("D: " ES_BRIGHTMAGENTA "%fs" ES_BRIGHTCYAN ", ", dTimeSec);
    printf("T: " ES_BRIGHTMAGENTA "%fs\n" ES_RESET, cTimeSec + pTimeSec + sTimeSec + dTimeSec);

    BetaSkipSearchMatcher *betassm = NULL;
    cTime = pTime = sTime = dTime = 0;
    for(t = 0; t < stringSet.dim; ++t) {
        currentTime = clock();
        betassm = new BetaSkipSearchMatcher(stringSet.getPattern(t), stringSet.getText(t), stringSet.alphabetSize);
        cTime += clock() - currentTime;

        currentTime = clock();
        betassm->preprocessing();
        pTime += clock() - currentTime;

        currentTime = clock();
        betassm->search();
        sTime += clock() - currentTime;

        currentTime = clock();
        delete betassm;
        dTime += clock() - currentTime;
    }
    cTimeSec = double(cTime) / CLOCKS_PER_SEC;
    pTimeSec = double(pTime) / CLOCKS_PER_SEC;
    sTimeSec = double(sTime) / CLOCKS_PER_SEC;
    dTimeSec = double(dTime) / CLOCKS_PER_SEC;

    printf(ES_BRIGHTCYAN "-- " ES_BRIGHTMAGENTA "Beta Skip Search " ES_BRIGHTCYAN "carried out the challenge in...\t");
    printf("C: " ES_BRIGHTMAGENTA "%fs" ES_BRIGHTCYAN ", ", cTimeSec);
    printf("P: " ES_BRIGHTMAGENTA "%fs" ES_BRIGHTCYAN ", ", pTimeSec);
    printf("S: " ES_BRIGHTMAGENTA "%fs" ES_BRIGHTCYAN ", ", sTimeSec);
    printf("D: " ES_BRIGHTMAGENTA "%fs" ES_BRIGHTCYAN ", ", dTimeSec);
    printf("T: " ES_BRIGHTMAGENTA "%fs\n" ES_RESET, cTimeSec + pTimeSec + sTimeSec + dTimeSec);

    GammaSkipSearchMatcher *gammassm = NULL;
    cTime = pTime = sTime = dTime = 0;
    for(t = 0; t < stringSet.dim; ++t) {
        currentTime = clock();
        gammassm = new GammaSkipSearchMatcher(stringSet.getPattern(t), stringSet.getText(t), stringSet.minChar, stringSet.maxChar);
        cTime += clock() - currentTime;

        currentTime = clock();
        gammassm->preprocessing();
        pTime += clock() - currentTime;

        currentTime = clock();
        gammassm->search();
        sTime += clock() - currentTime;

        currentTime = clock();
        delete gammassm;
        dTime += clock() - currentTime;
    }
    cTimeSec = double(cTime) / CLOCKS_PER_SEC;
    pTimeSec = double(pTime) / CLOCKS_PER_SEC;
    sTimeSec = double(sTime) / CLOCKS_PER_SEC;
    dTimeSec = double(dTime) / CLOCKS_PER_SEC;

    printf(ES_BRIGHTCYAN "-- " ES_BRIGHTMAGENTA "Gamma Skip Search " ES_BRIGHTCYAN "carried out the challenge in...\t");
    printf("C: " ES_BRIGHTMAGENTA "%fs" ES_BRIGHTCYAN ", ", cTimeSec);
    printf("P: " ES_BRIGHTMAGENTA "%fs" ES_BRIGHTCYAN ", ", pTimeSec);
    printf("S: " ES_BRIGHTMAGENTA "%fs" ES_BRIGHTCYAN ", ", sTimeSec);
    printf("D: " ES_BRIGHTMAGENTA "%fs" ES_BRIGHTCYAN ", ", dTimeSec);
    printf("T: " ES_BRIGHTMAGENTA "%fs\n" ES_RESET, cTimeSec + pTimeSec + sTimeSec + dTimeSec);
}