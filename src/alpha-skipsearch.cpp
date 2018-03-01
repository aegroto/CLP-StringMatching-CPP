#include <string>
#include <stdio.h>

AlphaSkipSearchMatcher::AlphaSkipSearchMatcher(string& sx, string& sy) {
    tree = AlphaTree();
    
    x = sx.c_str();
    y = sy.c_str();
    
    m = sx.length();
    n = sy.length();
}

AlphaSkipSearchMatcher::preprocessing() {
    tree = AlphaTree(8 * m);
    
}

AlphaSkipSearchMatcher::search() {
}

AlphaSkipSearchMatcher::execute() {
}

AlphaSkipSearchMatcher::debugOutput() {
}
