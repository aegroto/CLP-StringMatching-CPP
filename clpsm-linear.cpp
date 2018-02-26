#include <string>
#include <stdio.h>
#include "clpsm-linear.h"

using namespace std;

LinearStringMatcher::LinearStringMatcher(string sx, string sy) {    
    z = new int[255];
    
    m = sx.length();
    n = sy.length();
    
    list = new int[m];
    mpNext = new int[m];
    kmpNext = new int[m];
    
    x = sx.c_str();
    y = sy.c_str();
}
        
void LinearStringMatcher::preprocessing() {
    for(int s = 0; s < 255; ++s)
        z[s] = -1;
    
    list[0] = -1;
    z[x[0]] = -1;
    for(int i = 1; i < m; ++i) {
        list[i] = z[x[i]];
        z[x[i]] = i;
    }
}

int LinearStringMatcher::attempt() {
}

void LinearStringMatcher::advanceSkip() {
}

void LinearStringMatcher::search() {
}

void LinearStringMatcher::execute() {
    preprocessing();
}

void LinearStringMatcher::debugOutput() {
    printf("z: ");
    for(int s = 0; s < 255; ++s) {
        if(z[s] != -1) {
            printf("[%c] = %i ", s, z[s]);
        }
    }
    
    printf("\nlist: ");
    for(int i = 0; i < m; ++i) {
        if(list[i] != -1) {
            printf("[%c] = %i ", x[i], list[i]);
        }
    }
    
    printf("\n");
}

