#include <string>

using namespace std;

class LinearCLPMatcher {
    private:
        int *z, *list,
            *mpNext, *kmpNext;
        
        int m, n,
            occurrences;
        
        const char *x, *y;
        
        void preprocessing();
        void mpPreprocessing();
        void kmpPreprocessing();

        int attempt(int&, int&);
        void advanceSkip(int&, int&);
        void search();
        
        void report(int);

    public:
        LinearCLPMatcher(string&, string&);
        
        void execute();
        void debugOutput();

        int getOccurrences() { return occurrences; }
};
