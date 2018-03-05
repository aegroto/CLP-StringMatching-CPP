/**
 * "AlphaNode" class header file
**/

#ifndef ALPHANODE_H
#define ALPHANODE_H

#define DEBUG

#include <cstddef>

class AlphaNode {
    public:
        class Position {
            public:
                const int pos;
                Position* nextPos;

                Position(int);
                ~Position();
        };
        
    private:     
        AlphaNode **children;
        Position *firstPos;

    public:
#ifdef DEBUG
        char character;
#endif
        AlphaNode();
        ~AlphaNode();

        inline AlphaNode* get(int c) { return children[c]; } 
        Position* getFirstPos() { return firstPos; }

        inline void set(char c, AlphaNode *node) { children[c] = node; }  
        void addPos(int);  
};

#endif