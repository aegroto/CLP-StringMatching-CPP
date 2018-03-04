/**
 * "AlphaNode" class definition file
**/

#include "alphanode.h"
#include <stdio.h>

AlphaNode::AlphaNode() {
    children = new AlphaNode*[256];

    for(int i = 0; i < 256; ++i) {
        children[i] = NULL;
    }

    firstPos = NULL;
}

AlphaNode::~AlphaNode() {
    for(int i = 0; i < 256; ++i) {
        if(children[i] != NULL)
            delete children[i];
    }

    delete[] children;
    delete firstPos;
}

AlphaNode::Position::Position(int _pos) : pos(_pos) {
    nextPos = NULL;
}

AlphaNode::Position::~Position() {
    if(nextPos != NULL)
        delete nextPos;
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
