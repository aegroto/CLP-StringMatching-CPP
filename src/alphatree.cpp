#include "alphatree.h"

AlphaTree::AlphaNode::AlphaNode() {
    parent = rightSib = firstChild = NULL;
    height = 0;
}

void AlphaTree::AlphaNode::addPos(int index) {
    Position* pos = firstPos;
    while(pos != NULL)
        pos = pos->nextPos;

    pos = new Position();
    pos->index = index;
    pos->nextPos = NULL;
}

AlphaTree::AlphaTree(size_t _l) {
    l = _l;
    root = AlphaTree::AlphaNode();
    root.setCharacter(0);
    root.addPos(-1);
}

void AlphaTree::addSubstring(char* sub) {
    AlphaNode *parentNode = &root,
              *leftNode = NULL,
              *node = NULL;

    for(size_t i = 0; i < l; ++i) {
        AlphaNode *node = parentNode->getFirstChild();

        while(node != NULL) {
            if(node->getCharacter() == sub[i]) {
                leftNode = node->getFirstChild();
            } else {
                leftNode = node;
                node = node->getRightSib();
            }
            printf("%c ", leftNode->getCharacter());
        }

        node = new AlphaNode();
        if(leftNode != NULL)
            leftNode->setRightSib(node);

        parentNode->setFirstChild(node);
        node->setParent(parentNode);
        node->setCharacter(sub[i]);     
        parentNode = node;   
    }
}

void AlphaTree::print() {
    AlphaNode *node, *rightmostNode;
    node = rightmostNode = root.getFirstChild();
    printf("ROOT: %c\n", root.getCharacter());

    while(rightmostNode != NULL) {
        printf("%c [%c] -->", node->getCharacter(), node->getParent()->getCharacter());
        node = node->getRightSib();

        if(node == NULL) {
            rightmostNode = node = rightmostNode->getFirstChild();
            printf("\n");
        }
    }
}

