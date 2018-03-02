#include "alpha_skipsearch.h"

using namespace std;

AlphaSkipSearchMatcher::AlphaSkipSearchMatcher(string& sx, string& sy) {
    x = sx.c_str();
    y = sy.c_str();
    
    m = sx.length();
    n = sy.length();
    
    occurrences = 0;
}

void AlphaSkipSearchMatcher::preprocessing() {
    l = helpers::log2(m);
    trie = new AlphaTrie(l);    
}

void AlphaSkipSearchMatcher::search() {
}

void AlphaSkipSearchMatcher::execute() {
    preprocessing();
    search();
}

void AlphaSkipSearchMatcher::printOutput() {
    printf("\n-- ALPHA SKIP SEARCH MATCHER --\nx: %s\ny: %s\nm: %zu, n: %zu", x, y, m, n);

    printf("\noccurrences: %i\n", occurrences);
}
