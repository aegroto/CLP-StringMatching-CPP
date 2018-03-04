/**
 * "AlphaSkipSearchMathcer" class definition file
**/

#include "alpha_skipsearch.h"

using namespace std;

AlphaSkipSearchMatcher::AlphaSkipSearchMatcher(string& sx, string& sy, size_t _sigma) {
    x = sx.c_str();
    y = sy.c_str();
    
    m = sx.length();
    n = sy.length();
    
    sigma = _sigma;

    occurrences = 0;

    executed = false;
}

AlphaSkipSearchMatcher::~AlphaSkipSearchMatcher() {
    delete trie;
}

void AlphaSkipSearchMatcher::preprocessing() {
    l = helpers::log(m, sigma);

    trie = new AlphaTrie(l);  
    for(int i = 0; i < m - l + 1; ++i) {
        trie->addSubstring(&x[i], i);
    }
}

bool AlphaSkipSearchMatcher::attempt(int start) {
    int c;
    for(c = 0; c < m; ++c) 
        if(x[c] != y[start + c])
            break;

    return c == m;
}

void AlphaSkipSearchMatcher::search() {
    int i, j, k, start;
    AlphaNode* node;
    
    j = m - l;
    
    const int limit = n - l, 
              shift = m - l + 1;

    while(j < limit) {
        node = trie->getRoot();

        for(k = 0; k < l && node != NULL; ++k) {
            node = node->get(y[j+k]);
        }

        if(node != NULL) {
            AlphaNode::Position* position = node->getFirstPos();

            while(position != NULL) {
                start =  j - position->pos;

                if(attempt(start)) {
                    report(start);
                }

                position = position->nextPos;
            }
        } 

        j += shift;
    }
}

void AlphaSkipSearchMatcher::report(int index) {
    ++occurrences;
}

void AlphaSkipSearchMatcher::execute() {
    if(executed) return;
    preprocessing();
    search();
    executed = true;
}

void AlphaSkipSearchMatcher::printOutput() {
    printf("\n-- ALPHA SKIP SEARCH MATCHER --\nx: %s\ny: %s\nm: %zu, n: %zu", x, y, m, n);

    printf("\noccurrences: %i\n", occurrences);
}
