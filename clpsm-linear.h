#include <string>

using namespace std;

class LinearStringMatcher {
    private:
        int *z;
        int *list;
        int *mpNext, *kmpNext;
        
        int m, n;
        int j;
        int k, start, wall;
        int skipStart, kmpStart;
        
        string &x, &y;
        
        void preprocessing();
        int attempt();
        void advanceSkip();
        void search();
        
    public:
        LinearStringMatcher(string&, string&);
        
        void execute();
        void debugOutput();
};