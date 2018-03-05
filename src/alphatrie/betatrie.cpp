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

    int k, j;

    arraySize = m - l + 1;
    subPos = new BetaPosition*[arraySize];

    for(int i = 0; i < arraySize; ++i) {
        BetaPosition* pos = new BetaPosition(i);

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

        if(k == l && subPos[j] != NULL) {
            subPos[j]->nextPos = pos;
        } else 
            subPos[i] = pos;
    }
}

BetaTrie::~BetaTrie() {
    for(int i = 0; i < arraySize; ++i)
        delete subPos[i];

    delete[] subPos;
}

#ifdef DEBUG

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
#endif