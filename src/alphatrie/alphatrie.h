#ifndef ALPHATRIE_H
#define ALPHATRIE_H

#define DEBUG_TRIE

#include <stdio.h>
#include <queue>
#include "../helpers.h"
#include "alphanode.h"

class AlphaTrie {
    private:
        AlphaNode *root;
        size_t l;

    public:
        AlphaTrie(size_t);
        
        void addSubstring(const char*, int);
        AlphaNode* getRoot() { return root; }
        void print();        
};

#endif