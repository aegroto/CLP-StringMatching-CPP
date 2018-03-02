#include <stdio.h>
#include <queue>
#include "../helpers.h"

class AlphaTrie {
    private:
        class AlphaNode {
            private:     
                class Position {
                    public:
                        int pos;
                        Position* nextPos;

                        Position(int _pos) { nextPos = NULL; pos = _pos; }
                };
       
                AlphaNode *children[255];
                Position *firstPos;
            public:
                AlphaNode();

                AlphaNode* get(int c) { return children[c]; } 
                Position* getFirstPos() { return firstPos; }

                void set(char c, AlphaNode *node) { children[c] = node; }  
                void addPos(int);   
        };

        AlphaNode *root;
        size_t l;

    public:
        AlphaTrie(size_t);
        
        void addSubstring(char*, int);
        //void print();        
};
