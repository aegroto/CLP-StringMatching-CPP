#include <stdio.h>
#include <cstdlib>

class AlphaTree {
    private:
        class AlphaNode {
            private:
                AlphaNode *father,
                          *rightSib,
                          *firstChild;
                
                AlphaNode* getFather() { return father; }
                AlphaNode* getRightSib() { return rightSib; }
                AlphaNode* getFirstChild() { return firstChild; }
            public:
                AlphaNode();

                void setFather(AlphaNode* newFather) { father = newFather; }
                void setRightSib(AlphaNode* newRightSib) { rightSib = newRightSib; }
                void setFirstChild(AlphaNode* newFirstChild) { firstChild = newFirstChild; }
        };

        size_t l;
        AlphaNode root;
    public:
        AlphaTree(size_t);
};
