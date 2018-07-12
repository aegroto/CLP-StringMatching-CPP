/**
 * "GammaNode" class definition file
 *
 * Lorenzo Catania
**/

#include "gammanode.h"
#include <stdio.h>

GammaNode::GammaNode(char minChar, char maxChar) : arraySize(maxChar - minChar + 1), arrayOffset(minChar) {
    children = new GammaNode*[arraySize];
    children -= arrayOffset;
  
    const size_t limit = arrayOffset + arraySize;

    for(int i = arrayOffset; i < limit; ++i) {
        children[i] = NULL;
    }

    firstPos = NULL;
}

GammaNode::~GammaNode() {
    for(int i = arrayOffset; i < arraySize; ++i) {
        if(children[i] != NULL)
            delete children[i];
    }

    children += arrayOffset;
    delete[] children;
    delete firstPos;
}

GammaNode::Position::Position(int _pos) : pos(_pos) {
    nextPos = NULL;
}

GammaNode::Position::~Position() {
    if(nextPos != NULL)
        delete nextPos;
}

void GammaNode::addPos(int pos) {
    if(firstPos != NULL) {
        Position* lastPos = firstPos;
        while(lastPos->nextPos != NULL)
            lastPos = lastPos->nextPos;
        
        lastPos->nextPos = new Position(pos);
    } else {
        firstPos = new Position(pos);
    }
}
