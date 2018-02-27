#include <string>

using namespace std;

class LinearStringMatcher {
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
        LinearStringMatcher(string, string);
        
        void execute();
        void debugOutput();
};
