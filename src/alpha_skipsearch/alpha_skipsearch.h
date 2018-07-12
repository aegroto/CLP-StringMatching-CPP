/**
 * "AlphaSkipSearchMatcher" class header file
 *
 * Released under ZLib license: https://www.zlib.net/zlib_license.html
 *
 * Lorenzo Catania
**/

#ifndef ALPHA_SKIPSEARCH_H
#define ALPHA_SKIPSEARCH_H

#include <string>
#include <stdio.h>
#include <cstring>
#include "../helpers.h"
#include "../alphatrie/alphatrie.h"

using namespace std;

class AlphaSkipSearchMatcher {
    private:
        const char *x, *y;
        size_t m, n, sigma;
        int l, occurrences;

        bool preprocessed, searched;

        AlphaTrie *trie;

        bool attempt(int);

        void report(int);
    public:
        AlphaSkipSearchMatcher(string&, string&, size_t);
        ~AlphaSkipSearchMatcher();
        
        void preprocessing();
        void search();
        
        void execute();
        void printOutput();

        int getOccurrences() { return occurrences; }
};

#endif