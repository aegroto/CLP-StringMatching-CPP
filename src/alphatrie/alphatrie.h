/**
 * "AlphaTrie" class header file
 *
 * Lorenzo Catania
**/

#ifndef ALPHATRIE_H
#define ALPHATRIE_H

// #define DEBUG_TRIE

#include <stdio.h>
#include <queue>
#include "../helpers.h"
#include "alphanode.h"

class AlphaTrie {
    private:
        AlphaNode *root;
        size_t l;

    public:
        AlphaTrie(const char*, size_t, size_t);
        ~AlphaTrie();
        
        AlphaNode* getRoot() { return root; }
        void print();        
};

#endif