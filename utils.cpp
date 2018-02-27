#include <stdio.h>
#include "utils.h"

inline int& utils::max(int& a, int& b) { 
    return a > b ? a : b; 
}

int utils::maxPeriod(const char* x, int m) {
    int p = m-1;
    bool flag = true;

    while(p > 0) {
        flag = true;
        printf("\np = %i\n", p);

        for(int i = 0; i < m - p; ++i) {
            char c0 = x[p + i],
                 c1 = x[i];

            printf("%c - %c\n", c0, c1);

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
