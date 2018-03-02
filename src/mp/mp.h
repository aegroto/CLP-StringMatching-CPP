#include <string>

using namespace std;

class MorrisPrattMatcher {
    private:
        const char *x, *y;
        int m, n, occurrences;
        int *mpNext;

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
