/**
 * "BetaTrie" class header file
 *
 * Released under ZLib license: https://www.zlib.net/zlib_license.html
 *
 * Lorenzo Catania
**/

#ifndef BETATRIE_H
#define BETATRIE_H

#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

class BetaTrie {
    public:
        class BetaPosition {
            public:
                const int pos;
                BetaPosition* nextPos;

                BetaPosition(int);
                ~BetaPosition();
        };

    private:
        size_t l, arraySize;

        BetaPosition **subPos;
    public:
        BetaTrie(const char*, size_t, size_t);
        ~BetaTrie();

        size_t getArraySize() { return arraySize; }
        BetaPosition* getSubPos(int i) { return subPos[i]; }
        
        void print(const char*, size_t);
};

#endif