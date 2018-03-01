class AlphaSkipSearchMatcher {
    private:
        char *x, *y;
        int m, n;
        AlphaTree tree;

        void preprocessing();
        void search();
    public:
        AlphaSkipSearchMatcher(string&, string&);

        void execute();
        void debugOutput();
};
