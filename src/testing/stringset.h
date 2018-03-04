/**
 * "StringSet" class header file
**/

#ifndef STRINGSET_H
#define STRINGSET_H

#include <cstdlib>
#include <string>
#include "../helpers.h"

using namespace std;

class StringSet {
        string *patterns, *texts;

    public:
        const char minChar, maxChar;
        const size_t minM, maxM, minN, maxN, dim, alphabetSize;

        StringSet(size_t, size_t, size_t, size_t, char, char, size_t);
        ~StringSet();

        inline string& getPattern(int i) { return patterns[i]; }
        inline string& getText(int i) { return texts[i]; }
};

#endif