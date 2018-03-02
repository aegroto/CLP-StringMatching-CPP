#include <stdio.h>

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
                AlphaNode() { firstPos = NULL; }

                AlphaNode* get(char c) { return children[c]; } 
                Position* getFirstPos() { return firstPos; }

                void set(char c, AlphaNode *node) { children[c] = node; }  
                void addPos(int);   
        };

        AlphaNode *root;
        size_t l; 
    public:
        AlphaTrie(size_t);
        
        void addSubstring(char*, int);        
};
