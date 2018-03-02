#include "alphatrie.h"

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

    int foundChars = 0;
    child = node->get(sub[foundChars]);
    
    while(foundChars < l && child != NULL) {
        node = child;        
        child = node->get(sub[foundChars]);
        printf("%i", foundChars);
        ++foundChars;
    }
    
    if(foundChars < l) {
        child = new AlphaNode();
        node->set(sub[foundChars], child);
        ++foundChars;
    }
    
    child->addPos(start);
}
