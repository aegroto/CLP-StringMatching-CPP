#include "alphanode.h"
#include <stdio.h>

AlphaNode::AlphaNode() {
    children = new AlphaNode*[256];

    for(int i = 0; i < 256; ++i) {
        children[i] = NULL;
    }

    firstPos = NULL;
}

void AlphaNode::addPos(int pos) {
    if(firstPos != NULL) {
        Position* lastPos = firstPos;
        while(lastPos->nextPos != NULL)
            lastPos = lastPos->nextPos;
        
        lastPos->nextPos = new Position(pos);
    } else {
        firstPos = new Position(pos);
    }
}
