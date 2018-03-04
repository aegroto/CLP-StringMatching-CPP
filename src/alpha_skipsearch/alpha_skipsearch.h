#ifndef ALPHA_SKIPSEARCH_H
#define ALPHA_SKIPSEARCH_H

#include <string>
#include <stdio.h>
#include "../helpers.h"
#include "../alphatrie/alphatrie.h"

using namespace std;

class AlphaSkipSearchMatcher {
    private:
        const char *x, *y;
        size_t m, n, sigma;
        int l, occurrences;

        bool executed;

        AlphaTrie *trie;

        void preprocessing();
        bool attempt(int);
        void search();

        void report(int);
    public:
        AlphaSkipSearchMatcher(string&, string&, size_t);
        ~AlphaSkipSearchMatcher();
        
        void execute();
        void printOutput();

        int getOccurrences() { return occurrences; }
};

#endif