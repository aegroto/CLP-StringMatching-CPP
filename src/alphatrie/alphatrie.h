/**
 * "AlphaTrie" class header file
**/

#ifndef ALPHATRIE_H
#define ALPHATRIE_H

#define DEBUG

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
        ~AlphaTrie();
        
        void addSubstring(const char*, int);
        AlphaNode* getRoot() { return root; }
#ifdef DEBUG
        void print();        
#endif
};

#endif