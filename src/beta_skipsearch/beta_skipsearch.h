/**
 * "BetaSkipSearchMatcher" class header file
 *
 * Released under ZLib license: https://www.zlib.net/zlib_license.html
 *
 * Lorenzo Catania
**/

#ifndef BETA_SKIPSEARCH_H
#define BETA_SKIPSEARCH_H

#define PRINTABLE_TRIE

#include <string>
#include <stdio.h>
#include "../helpers.h"
#include "../betatrie/betatrie.h"

class BetaSkipSearchMatcher {
    private:
        const char *x, *y;
        size_t m, n, l, sigma;
        int occurrences;

        bool preprocessed, searched;

        BetaTrie *trie;

        bool attempt(int);

        void report(int);
    public:
        BetaSkipSearchMatcher(string&, string&, size_t);
        ~BetaSkipSearchMatcher();
        
        void preprocessing();
        void search();
        
        void execute();
        void printOutput();

        int getOccurrences() { return occurrences; }
};

#endif