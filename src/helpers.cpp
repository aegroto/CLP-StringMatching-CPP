/**
 * "helpers" namespace definition file
 *
 * Lorenzo Catania
**/

#include "helpers.h"

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

int helpers::log(int a, int base) {
    int result = 1, tmp = a;

    while(tmp > base) {
        tmp /= base;
        ++result;    
    }

    return result;
}