#include "alphatree.h"
#include <queue>

using namespace std;

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
    root.setCharacter('R');
    root.addPos(-1);
}

void AlphaTree::addSubstring(char* sub) {
    AlphaNode *parentNode = &root,
              *leftNode = NULL,
              *node = parentNode->getFirstChild(),
              *anchorNode = NULL;

    size_t foundChars = 0;

    while(node != NULL) {
        if(node->getCharacter() == sub[foundChars]) {
            parentNode = node;
            leftNode = NULL;
            node = parentNode->getFirstChild();
        } else {
            leftNode = node;
            node = node->getRightSib();
        }
    }

    anchorNode = new AlphaNode();
    anchorNode->setCharacter(sub[foundChars]);
    anchorNode->setParent(parentNode);

    if(leftNode != NULL) {
        // printf("anchor node is %c, left node is %c
        leftNode->setRightSib(anchorNode);
    } else {        
        parentNode->setFirstChild(anchorNode);
    }

    ++foundChars;
    
    while(foundChars < l) {
        node = new AlphaNode();    
        node->setCharacter(sub[foundChars]);
        node->setParent(anchorNode);
        anchorNode->setFirstChild(node);
            
        anchorNode = node;
        ++foundChars;
    }   

    print();
}

void AlphaTree::print() {
    printf("test");

    queue<AlphaNode*> Q;
    Q.push(&root);

    /*while(!Q.empty()) {
        AlphaNode *front = Q.front(), *tmp = front->getFirstChild();    
        printf("front is %c", front->getCharacter()); 

        while(tmp->getRightSib() != NULL) {
            Q.push(tmp);
            tmp = tmp->getRightSib();
        }

        printf("%c -->", front->getCharacter());
        Q.pop();
    }*/
}






