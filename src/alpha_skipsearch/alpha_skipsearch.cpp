/**
 * "AlphaSkipSearchMathcer" class definition file
 *
 * Lorenzo Catania
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

    preprocessed = searched = false;
}

AlphaSkipSearchMatcher::~AlphaSkipSearchMatcher() {
    delete trie;
}

void AlphaSkipSearchMatcher::preprocessing() {
    if(preprocessed) return;
    
    l = helpers::log(m, sigma);

    trie = new AlphaTrie(x, m, l);

    preprocessed = true;
}

bool AlphaSkipSearchMatcher::attempt(int start) {
    int c = -1;
    char *ty = (char*) (y + start);

    while(++c < m)
        if(x[c] != ty[c])
            break;

    return c == m;
}

void AlphaSkipSearchMatcher::search() {
    if(searched) return;

    int j, k, start;
    AlphaNode* node;
    
    j = m - l;
    
    const int limit = n - l + 1, 
              shift = m - l + 1;

    char* ty;
    while(j < limit) {
        node = trie->getRoot();
        ty = (char*) (y + j);

        for(k = 0; k < l && node != NULL; ++k) {
            node = node->get(ty[k]);
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

    searched = true;
}

void AlphaSkipSearchMatcher::report(int index) {
    ++occurrences;
}

void AlphaSkipSearchMatcher::execute() {
    if(preprocessed && searched) return;
    preprocessing();
    search();
}

void AlphaSkipSearchMatcher::printOutput() {
    printf("\n-- ALPHA SKIP SEARCH MATCHER --\nx: %s\ny: %s\nm: %zu, n: %zu", x, y, m, n);

    printf("\noccurrences: %i\n", occurrences);
}
