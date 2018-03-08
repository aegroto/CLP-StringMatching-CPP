/**
 * "GammaSkipSearchMathcer" class definition file
 *
 * Lorenzo Catania
**/

#include "gamma_skipsearch.h"

using namespace std;

GammaSkipSearchMatcher::GammaSkipSearchMatcher(string& sx, string& sy, char _minChar, char _maxChar) {
    x = sx.c_str();
    y = sy.c_str();
    
    m = sx.length();
    n = sy.length();
    
    minChar = _minChar;
    maxChar = _maxChar;

    sigma = maxChar - minChar + 1;

    occurrences = 0;

    preprocessed = searched = false;
}

GammaSkipSearchMatcher::~GammaSkipSearchMatcher() {
    delete trie;
}

void GammaSkipSearchMatcher::preprocessing() {
    if(preprocessed) return;
    
    l = helpers::log(m, sigma);

    trie = new GammaTrie(x, m, l, minChar, maxChar);

    preprocessed = true;
}

bool GammaSkipSearchMatcher::attempt(int start) {
    int c = -1;
    char *ty = (char*) (y + start);

    while(++c < m)
        if(x[c] != ty[c])
            break;

    return c == m;
}

void GammaSkipSearchMatcher::search() {
    if(searched) return;

    int j, k, start;
    GammaNode* node;
    
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
            GammaNode::Position* position = node->getFirstPos();

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

void GammaSkipSearchMatcher::report(int index) {
    ++occurrences;
}

void GammaSkipSearchMatcher::execute() {
    if(preprocessed && searched) return;
    preprocessing();
    search();
}

void GammaSkipSearchMatcher::printOutput() {
    printf("\n-- GAMMA SKIP SEARCH MATCHER --\nx: %s\ny: %s\nm: %zu, n: %zu\n", x, y, m, n);
#ifdef DEBUG_TRIE
    trie->print();
#endif
    printf("\noccurrences: %i\n", occurrences);
}
