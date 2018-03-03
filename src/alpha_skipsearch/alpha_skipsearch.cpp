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
    for(int i = 0; i < m - l + 1; ++i) {
        trie->addSubstring(&x[i], i); 
        //trie->print();
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
    int i, j, k, limit;
    AlphaNode* node;
    
    j = m - l;
    limit = n - l;

    //printf("search initialized\n");
    while(j < limit) {
        node = trie->getRoot();

        // printf("j is %i, node is %c \n", j, node->character);

        for(k = 0; k < l && node != NULL; ++k) {
            //printf("searching for %c \n", y[j+k]);
            node = node->get(y[j+k]);
        }

        if(node != NULL) {
            AlphaNode::Position* position = node->getFirstPos();

            // printf("position is %i\n", position);
            while(position != NULL) {
                i = position->pos;

                // printf("checking position %i\n", i);
                if(attempt(j - i)) {
                    report(j - i);
                }

                position = position->nextPos;
            }
        } 

        j = j + m - l + 1;
    }
}

void AlphaSkipSearchMatcher::report(int index) {
    ++occurrences;
}

void AlphaSkipSearchMatcher::execute() {
    preprocessing();
    search();
}

void AlphaSkipSearchMatcher::printOutput() {
    printf("\n-- ALPHA SKIP SEARCH MATCHER --\nx: %s\ny: %s\nm: %zu, n: %zu", x, y, m, n);

    printf("\noccurrences: %i\n", occurrences);
}
