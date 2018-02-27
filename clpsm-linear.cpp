#include <string>
#include <stdio.h>
#include "clpsm-linear.h"
#include "utils.h"

using namespace std;

LinearStringMatcher::LinearStringMatcher(string sx, string sy) {    
    z = new int[255];
    
    m = sx.length();
    n = sy.length();
    
    list = new int[m];
    mpNext = new int[m + 1];
    kmpNext = new int[m + 1];
    
    x = sx.c_str();
    y = sy.c_str();

    occurrences = 0;
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

void LinearStringMatcher::mpPreprocessing() {
    int i = 0, 
        j = mpNext[0] = -1;

    while (i < m) {
        while (j >= 0 && x[i] != x[j])
            j = mpNext[j];

        mpNext[++i] = ++j;
    }
}

void LinearStringMatcher::kmpPreprocessing() {
   int i = 0,
       j = kmpNext[0] = -1;

   while (i < m) {
      while (j >= 0 && x[i] != x[j])
         j = kmpNext[j];

      ++i; 
      ++j;

      if (i<m && x[i] == x[j])
         kmpNext[i] = kmpNext[j];
      else
         kmpNext[i] = j;
   }
}

int LinearStringMatcher::attempt(int &wall, int &start) {
    int k = wall - start;
    while(k < m && x[k] == y[wall + k])
        ++k;

    return k;
}

void LinearStringMatcher::advanceSkip(int &i, int &j) {
    do {    
        j += m;
    } while(j < n || z[y[j]] < 0);

    if(j < n) 
        i = z[y[j]];
}

void LinearStringMatcher::search() {
    int wall, start, i, j, k, skipStart, kmpStart, lastPIndex;

    wall = 0;
    i = j = -1;
    advanceSkip(i, j);
    start = j - i;
    lastPIndex = n - m;

    while(start <= lastPIndex) {
        wall = max(wall, start);
        k = attempt(wall, start);
        wall = start + k;

        if(k == m) { 
            report(start);
            i = i - utils::maxPeriod(x, m);
        } else i = list[i];

        if(i < 0)
            advanceSkip(i, j);

        skipStart = j - i;
        kmpStart = start + k - kmpNext[k];
        k = kmpNext[k];

        while(skipStart != kmpStart || !(kmpStart < wall && wall < skipStart)) {
            if(skipStart < kmpStart) {
                i = list[i];
                if(i < 0)
                    advanceSkip(i, j);
                skipStart = j - i;            
            } else {    
                kmpStart += k - mpNext[k];
                k = mpNext[k];
            }
        }

        start = skipStart;
    }
}

void LinearStringMatcher::report(int index) {
    ++occurrences;
}

void LinearStringMatcher::execute() {
    preprocessing();
    mpPreprocessing();
    kmpPreprocessing();
}

void LinearStringMatcher::debugOutput() {
    printf("x: %s\ny: %s", x, y);

    printf("\nz: ");
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

    printf("\nmpNext: ");
    for(int i = 0; i <= m; ++i) {
        if(mpNext[i] != -1) {
            printf("[%i] = %i ", i, mpNext[i]);
        }
    }

    printf("\nkmpNext: ");
    for(int i = 0; i <= m; ++i) {
        if(kmpNext[i] != -1) {
            printf("[%i] = %i ", i, kmpNext[i]);
        }
    }

    printf("\noccurences: %i", occurrences);
    
    printf("\n");
}

