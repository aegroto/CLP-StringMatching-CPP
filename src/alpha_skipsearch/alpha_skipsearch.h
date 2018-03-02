#include <string>
#include <stdio.h>
#include "../helpers.h"
#include "../alphatrie/alphatrie.h"

using namespace std;

class AlphaSkipSearchMatcher {
    private:
        const char *x, *y;
        size_t m, n;
        int l, occurrences;

        AlphaTrie *trie;

        void preprocessing();
        void search();

    public:
        AlphaSkipSearchMatcher(string&, string&);

        void execute();
        void printOutput();

        int getOccurrences() { return occurrences; }
};
