/**
 * "BetaTrie" class header file
 *
 * Released under ZLib license: https://www.zlib.net/zlib_license.html
 *
 * Lorenzo Catania
**/

#include "betatrie.h"

BetaTrie::BetaPosition::BetaPosition(int _pos) : pos(_pos) {
    nextPos = NULL;
}

BetaTrie::BetaPosition::~BetaPosition() {
    if(nextPos != NULL)
        delete nextPos;
}

BetaTrie::BetaTrie(const char* str, size_t m, size_t _l) {
    l = _l;

    int i, k, j;
    BetaPosition *pos, *lastPos;

    arraySize = m - l + 1;
    subPos = new BetaPosition*[arraySize];

    for(i = 0; i < arraySize; ++i) {
        subPos[i] = NULL;
        pos = new BetaPosition(i);

        for(j = 0; j < i; ++j) {
            k = 0;

            while(k < l) {
                if(str[i + k] == str[j + k])
                    ++k;
                else break;
            }

            if(k == l) {
                break;
            }
        }

        if(k == l) {
            lastPos = subPos[j];
            while(lastPos->nextPos != NULL)
                lastPos = lastPos->nextPos;

            lastPos->nextPos = pos;
        } else 
            subPos[i] = pos;
    }
}

BetaTrie::~BetaTrie() {
    for(int i = 0; i < arraySize; ++i)
        delete subPos[i];

    delete[] subPos;
}

void BetaTrie::print(const char* str, size_t m) {
    for(size_t i = 0; i < arraySize; ++i) {
        BetaPosition* ppos = subPos[i];
        if(ppos != NULL) {
            printf("[");
            for(size_t k = 0; k < l; ++k)
                printf("%c", str[i + k]);
            printf("] --> { ");

            while(ppos != NULL) {
                printf("%i ", ppos->pos);
                ppos = ppos->nextPos;
            }
            printf("}\n");
        }
    }
}