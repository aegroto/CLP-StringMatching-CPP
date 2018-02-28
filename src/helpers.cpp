#include <stdio.h>
#include "helpers.h"

inline int& helpers::max(int& a, int& b) { 
    return a > b ? a : b; 
}

int helpers::maxPeriod(const char* x, int m) {
    int p = m-1;
    bool flag = true;

    while(p > 0) {
        flag = true;

        for(int i = 0; i < m - p; ++i) {
            char c0 = x[p + i],
                 c1 = x[i];

            if(c0 != c1) {
                flag = false;
                break;
            }
        }
    
        if(flag)
            return p;
        else
            --p;
    }

    return 0;
}
