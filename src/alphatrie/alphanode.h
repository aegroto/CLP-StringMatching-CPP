#ifndef ALPHANODE_H
#define ALPHANODE_H

#include <cstddef>

class AlphaNode {
    public:
        class Position {
            public:
                int pos;
                Position* nextPos;

                Position(int _pos) { nextPos = NULL; pos = _pos; }
        };
        
    private:     
        AlphaNode **children;
        Position *firstPos;

    public:
#ifdef DEBUG_TRIE
        char character;
#endif
        AlphaNode();

        inline AlphaNode* get(int c) { return children[c]; } 
        Position* getFirstPos() { return firstPos; }

        inline void set(char c, AlphaNode *node) { children[c] = node; }  
        void addPos(int);  
};

#endif