/**
 * "MorrisPrattMatcher" class header file
 *
 * Lorenzo Catania
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

        bool preprocessed, searched;
        
        void report(int);

    public:
        MorrisPrattMatcher(string&, string&);
        ~MorrisPrattMatcher();

        void preprocessing();      
        void search();
          
        void execute();
        void printOutput();
        int getOccurrences() { return occurrences; }
};

#endif