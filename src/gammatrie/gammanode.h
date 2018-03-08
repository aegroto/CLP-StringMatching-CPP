/**
 * "GammaNode" class header file
 *
 * Lorenzo Catania
**/

#ifndef GAMMANODE_H
#define GAMMANODE_H

#include <cstddef>

class GammaNode {
    public:
        class Position {
            public:
                const int pos;
                Position* nextPos;

                Position(int);
                ~Position();
        };
        
    private:     
        GammaNode **children;
        Position *firstPos;

        const size_t arraySize, arrayOffset;
    public:
#ifdef DEBUG_TRIE
        char character;
#endif
        GammaNode(char, char);
        ~GammaNode();

        inline GammaNode* get(int c) { if(c >= arrayOffset) return children[c]; return NULL; } 
        Position* getFirstPos() { return firstPos; }

        inline void set(char c, GammaNode *node) { children[c] = node; }  
        void addPos(int);  
};

#endif