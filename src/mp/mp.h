/**
 * "MorrisPrattMatcher" class header file
**/

#ifndef MP_H
#define MP_H

#include <string>

using namespace std;

class MorrisPrattMatcher {
    private:
        const char *x, *y;
        int m, n, occurrences;
        int *mpNext;

        bool executed;

        void preprocessing();
        void search();
        void report(int);

    public:
        MorrisPrattMatcher(string&, string&);
        ~MorrisPrattMatcher();
        
        void execute();
        void printOutput();
        int getOccurrences() { return occurrences; }
};

#endif