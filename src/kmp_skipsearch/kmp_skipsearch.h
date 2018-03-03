#ifndef KMP_SKIPSEARCH_H
#define KMP_SKIPSEARCH_H

#include <string>
#include <stdio.h>
#include "../helpers.h"

using namespace std;

class KMPSkipSearchMatcher {
    private:
        int *z, *list,
            *mpNext, *kmpNext,            
            occurrences;
        
        size_t m, n;
        
        const char *x, *y;
        
        void preprocessing();
        void mpPreprocessing();
        void kmpPreprocessing();

        int attempt(int&, int&);
        void advanceSkip(int&, int&);
        void search();
        
        void report(int);

    public:
        KMPSkipSearchMatcher(string&, string&);
        ~KMPSkipSearchMatcher();

        void execute();
        void printOutput();

        int getOccurrences() { return occurrences; }
};

#endif