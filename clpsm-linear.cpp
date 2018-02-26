#include <string>
#include <stdio.h>
#include "clpsm-linear.h"

using namespace std;

LinearStringMatcher::LinearStringMatcher(string &_x, string &_y) : x(_x), y(_y) {    
    z = new int[255];
    
    m = x.length();
    n = y.length();
    
    list = new int[m];
    mpNext = new int[m];
    kmpNext = new int[m];
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

