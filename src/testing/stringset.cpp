#include "stringset.h"
#include <iostream>

using namespace std;

StringSet::StringSet(size_t _minM, size_t _maxM, size_t _minN, size_t _maxN, char _minChar, char _maxChar, size_t _dim) :
    minM(_minM),
    maxM(_maxM),
    minN(_minN),
    maxN(_maxN),
    dim(_dim),

    minChar(_minChar),
    maxChar(_maxChar),
    alphabetSize(maxChar - minChar + 1) {
        int m, n;
        char *tmpPattern = new char[maxM], 
             *tmpText = new char[maxN];

        patterns = new string[dim];
        texts = new string[dim];

        for(size_t i = 0; i < dim; ++i) {
            m = (rand() % (maxM - minM + 1)) + minM;
            n = (rand() % (maxN - minN + 1)) + minN;

            for(int c = 0; c < m; ++c) 
                tmpPattern[c] = helpers::randChar(minChar, maxChar);
                //patterns[i] += helpers::randChar(minChar, maxChar);

            for(int c = 0; c < n; ++c)
                tmpText[c] = helpers::randChar(minChar, maxChar);
                //texts[i] += helpers::randChar(minChar, maxChar);

            patterns[i] = string(tmpPattern, m);
            texts[i] = string(tmpText, n);
        }

        delete[] tmpPattern, tmpText;
}

StringSet::~StringSet() {
    delete[] patterns, texts;
}