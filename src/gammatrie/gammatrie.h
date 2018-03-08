/**
 * "GammaTrie" class header file
 *
 * Lorenzo Catania
**/

#ifndef GAMMATRIE_H
#define GAMMATRIE_H

#define DEBUG_TRIE

#include <stdio.h>
#include <queue>
#include "../helpers.h"
#include "gammanode.h"

class GammaTrie {
    private:
        GammaNode *root;
        size_t l;
        char minChar, maxChar;

    public:
        // GammaTrie(size_t);
        GammaTrie(const char*, size_t, size_t, char, char);
        ~GammaTrie();
        
        GammaNode* getRoot() { return root; }
#ifdef DEBUG_TRIE
        void print();
#endif
};

#endif