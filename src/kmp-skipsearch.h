#include <string>

using namespace std;

class KMPSkipSearchMatcher {
    private:
        int *z, *list,
            *mpNext, *kmpNext,            
            occurrences;
        
        size_t m, n;
        
        const char *x, *y;
        
        void preprocessing();
        void mpPreprocessing();
        void kmpPreprocessing();

        int attempt(int&, int&);
        void advanceSkip(int&, int&);
        void search();
        
        void report(int);

    public:
        KMPSkipSearchMatcher(string&, string&);
        
        void execute();
        void debugOutput();

        int getOccurrences() { return occurrences; }
};