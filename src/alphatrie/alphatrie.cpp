#include "alphatrie.h"

AlphaTrie::AlphaNode::AlphaNode() {
    firstPos = NULL;
    for(int i = 0; i < 255; ++i)
        children[i] = NULL;
}

void AlphaTrie::AlphaNode::addPos(int pos) {
    if(firstPos != NULL) {
        Position* lastPos = firstPos;
        while(lastPos->nextPos != NULL)
            lastPos = lastPos->nextPos;
        
        lastPos->nextPos = new Position(pos);
    } else {
        firstPos = new Position(pos);
    }
}

AlphaTrie::AlphaTrie(size_t _l) {
    l = _l;
    root = new AlphaNode();
}

void AlphaTrie::addSubstring(char* sub, int start) {
    AlphaNode *node = root,
              *child = NULL;

    size_t foundChars = 0;
    child = node->get(sub[foundChars]);
    
    while(foundChars < l && child != NULL) {
        node = child;        
        child = node->get(sub[foundChars]);
        ++foundChars;
    }
    
    while(foundChars < l) {
        child = new AlphaNode();
        node->set(sub[foundChars], child);
        node = child;
        ++foundChars;
    }
    
    child->addPos(start);
}

/* void AlphaTrie::print() {
    std::queue<AlphaNode*> Q;
    
    Q.push(root);

    while(!Q.empty()) {
        AlphaNode* current = Q.front();
        
        std::queue<AlphaNode*> Qcopy = Q;


        printf("%c --> [ ", current->character);

        for(int i = 0; i < 255; ++i) {
            if(current->get(i) != NULL) {
                printf("%c ", current->get(i)->character);
                Q.push(current->get(i));
            }
        }
        
        printf("]\n");
        Q.pop();
    }
} */
