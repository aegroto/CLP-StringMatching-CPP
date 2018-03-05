/**
 * "BetaSkipSearchMatcher" class header file
**/

#ifndef BETA_SKIPSEARCH_H
#define BETA_SKIPSEARCH_H

#include <string>
#include <stdio.h>
#include "../helpers.h"
#include "../betatrie/betatrie.h"

class BetaSkipSearchMatcher {
    private:
        const char *x, *y;
        size_t m, n, l, sigma;
        int occurrences;

        bool executed;

        BetaTrie *trie;

        void preprocessing();
        bool attempt(int);
        void search();

        void report(int);
    public:
        BetaSkipSearchMatcher(string&, string&, size_t);
        ~BetaSkipSearchMatcher();
        
        void execute();
        void printOutput();

        int getOccurrences() { return occurrences; }
};

#endif