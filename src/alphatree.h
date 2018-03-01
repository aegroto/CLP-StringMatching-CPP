#include <stdio.h>
#include <cstdlib>

class AlphaTree {
    private:
        class AlphaNode {
            private:
                class Position {
                    public:
                        size_t index;
                        Position* nextPos;
                };

                AlphaNode *parent,
                          *rightSib,
                          *firstChild;

                char character;
                int height;
                Position* firstPos;

            public:
                AlphaNode();
                
                AlphaNode* getParent() { return parent; }
                AlphaNode* getRightSib() { return rightSib; }
                AlphaNode* getFirstChild() { return firstChild; }

                void setParent(AlphaNode* newParent) { 
                    parent = newParent; 
                    height = parent->getHeight() + 1; 
                }

                void setRightSib(AlphaNode* newRightSib) { rightSib = newRightSib; }
                void setFirstChild(AlphaNode* newFirstChild) { firstChild = newFirstChild; }

                char getCharacter() { return character; }
                Position* getFirstPos() { return firstPos; }
                char getHeight() { return height; }

                void setCharacter(char newCharacter) { character = newCharacter; }

                void addPos(int);
        };

        size_t l;
        AlphaNode root;

    public:
        AlphaTree(size_t);
        void addSubstring(char*);
        void print();
};
