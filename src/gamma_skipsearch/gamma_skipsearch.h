/**
 * "GammaSkipSearchMatcher" class header file
 *
 * Lorenzo Catania
**/

#ifndef GAMMA_SKIPSEARCH_H
#define GAMMA_SKIPSEARCH_H

#include <string>
#include <stdio.h>
#include <cstring>
#include "../helpers.h"
#include "../gammatrie/gammatrie.h"

using namespace std;

class GammaSkipSearchMatcher {
    private:
        const char *x, *y;
        size_t m, n, sigma;
        char minChar, maxChar;
        int l, occurrences;

        bool preprocessed, searched;

        GammaTrie *trie;

        bool attempt(int);

        void report(int);
    public:
        GammaSkipSearchMatcher(string&, string&, char, char);
        ~GammaSkipSearchMatcher();
        
        void preprocessing();
        void search();
        
        void execute();
        void printOutput();

        int getOccurrences() { return occurrences; }
};

#endif