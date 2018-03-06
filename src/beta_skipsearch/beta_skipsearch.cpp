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

    preprocessed = searched = false;
}

BetaSkipSearchMatcher::~BetaSkipSearchMatcher() {
    if(preprocessed) delete trie;
}

void BetaSkipSearchMatcher::preprocessing() {
    if(preprocessed) return;
    l = helpers::log(m, sigma);
    
    trie = new BetaTrie(x, m, l);

    preprocessed = true;
}

bool BetaSkipSearchMatcher::attempt(int start) {
    int c = -1;
    char *ty = (char*) (y + start);

    while(++c < m)
        if(x[c] != ty[c])
            break;

    return c == m;
}

void BetaSkipSearchMatcher::search() {
    if(searched) return;

    int i, j, k, start, subIndex;

    j = m - l;
    
    const int limit = n - l + 1, 
              shift = m - l + 1;

    char *tx, *ty;

    while(j < limit) {
        subIndex = -1;

        for(i = 0; i < shift; ++i) {
            k = 0;
            tx = (char*) (x + i);
            ty = (char*) (y + j);

            while(k < l && tx[k] == ty[k]) {
                ++k;
            }

            if(k == l) {
                subIndex = i;
                break;
            }
        }


        if(subIndex >= 0) {
            BetaTrie::BetaPosition* position = trie->getSubPos(subIndex);

            while(position != NULL) {
                start = j - position->pos;

                if(attempt(start)) {
                    report(start);
                }

                position = position->nextPos;
            }
        }

        j += shift;
    }

    searched = true;
}

void BetaSkipSearchMatcher::report(int index) {
    ++occurrences;
}

void BetaSkipSearchMatcher::execute() {
    if(preprocessed && searched) return;
    preprocessing();
    search();
}

void BetaSkipSearchMatcher::printOutput() {
    printf("\n-- BETA SKIP SEARCH MATCHER --\nx: %s\ny: %s\nm: %zu, n: %zu, l: %zu\n", x, y, m, n, l);
#ifdef PRINTABLE_TRIE
    trie->print(x, m);
#endif
    printf("occurrences: %i\n", occurrences);
}