/**
 * "BetaSkipSearchMatcher" class definition file
**/

#include "beta_skipsearch.h"

BetaSkipSearchMatcher::BetaSkipSearchMatcher(string& sx, string& sy, size_t _sigma) {
    x = sx.c_str();
    y = sy.c_str();
    
    m = sx.length();
    n = sy.length();
    
    sigma = _sigma;

    occurrences = 0;

    executed = false;
}

BetaSkipSearchMatcher::~BetaSkipSearchMatcher() {
    if(executed) delete trie;
}

void BetaSkipSearchMatcher::preprocessing() {
    l = helpers::log(m, sigma);
    
    trie = new BetaTrie(x, m, l);
}

bool BetaSkipSearchMatcher::attempt(int start) {
    int c;
    for(c = 0; c < m; ++c) 
        if(x[c] != y[start + c])
            break;

    return c == m;
}

void BetaSkipSearchMatcher::search() {
    int i, j, k, start;

    j = m - l;
    
    const int limit = n - l + 1, 
              shift = m - l + 1;

    while(j < limit) {
        int subIndex = -1;

        //printf("j is %i\n", j);
        for(i = 0; i < shift; ++i) {
            k = 0;
            while(k < l && x[i + k] == y[j + k]) {
                ++k;
            }

            if(k == l) {
                subIndex = i;
                break;
            }
        }

        //printf("\nsubindex is %i\n", subIndex);

        if(subIndex >= 0) {
            BetaTrie::BetaPosition* position = trie->getSubPos(subIndex);

            while(position != NULL) {
                start = j - position->pos;

                //printf("attempt at %i\n", start);
                if(attempt(start)) {
                    report(start);
                }

                position = position->nextPos;
            }
        }

        j += shift;
    }
}

void BetaSkipSearchMatcher::report(int index) {
    ++occurrences;
}

void BetaSkipSearchMatcher::execute() {
    if(executed) return;
    preprocessing();
    search();
    executed = true;
}

void BetaSkipSearchMatcher::printOutput() {
    printf("\n-- BETA SKIP SEARCH MATCHER --\nx: %s\ny: %s\nm: %zu, n: %zu, l: %zu\n", x, y, m, n, l);
    trie->print(x, m);
    printf("occurrences: %i\n", occurrences);
}