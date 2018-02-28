#include <string>
#include <stdio.h>

#include "clp-linear.h"
#include "helpers.h"

using namespace std;

LinearCLPMatcher::LinearCLPMatcher(string& sx, string& sy) {   
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
        
void LinearCLPMatcher::preprocessing() {
    for(int s = 0; s < 255; ++s)
        z[s] = -1;
    
    list[0] = -1;
    z[x[0]] = 0;
    for(int i = 1; i < m; ++i) {
        list[i] = z[x[i]];
        z[x[i]] = i;
    }
}

void LinearCLPMatcher::mpPreprocessing() {
    int i = 0, 
        j = mpNext[0] = -1;

    while (i < m) {
        while (j >= 0 && x[i] != x[j])
            j = mpNext[j];

        mpNext[++i] = ++j;
    }
}

void LinearCLPMatcher::kmpPreprocessing() {
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

int LinearCLPMatcher::attempt(int &wall, int &start) {
    int k = wall - start;
    while(k < m && x[k] == y[k + start])
        ++k;

    return k;
}

void LinearCLPMatcher::advanceSkip(int &i, int &j) {
    do {    
        j += m;
    } while(j < n && z[y[j]] < 0);

    if(j < n) 
        i = z[y[j]];
}

void LinearCLPMatcher::search() {
    int wall, start, i, j, k, /*skipStart,*/ kmpStart, period, lastPIndex;

    occurrences = wall = 0;
    i = j = -1;

    period = m - kmpNext[m];

    advanceSkip(i, j);

    start = j - i;

    lastPIndex = n - m;

    while(start <= lastPIndex) {
        wall = max(wall, start);
        k = attempt(wall, start);
        wall = start + k;

        // printf("search on %i,%i\n", start, wall);

        if(k == m) { 
            report(start);
            i -= period;
        } else i = list[i];

        if(i < 0)
            advanceSkip(i, j);

        kmpStart = start + k - kmpNext[k];
        k = kmpNext[k];
        start = j - i;

        while(start < kmpStart || (kmpStart < start && start < wall)) {
            if(start < kmpStart) {
                i = list[i];
                if(i < 0)
                    advanceSkip(i, j);

                start = j - i;            
            } else {    
                kmpStart += k - mpNext[k];
                k = mpNext[k];
            }

            // printf("searching start on skipStart: %i, kmpStart: %i, wall: %i, i: %i, j: %i\n", skipStart, kmpStart, wall, i, j);
        }   
    }
}

void LinearCLPMatcher::report(int index) {
    ++occurrences;
}

void LinearCLPMatcher::execute() {
    mpPreprocessing();
    kmpPreprocessing();
    preprocessing();
    search();
}

void LinearCLPMatcher::debugOutput() {
    printf("\n-- CLP LINEAR MATCHER --\nx: %s\ny: %s\nm: %i, n: %i", x, y, m, n);

    printf("\nz: ");
    for(int s = 0; s < 255; ++s) {
        if(z[s] != -1) {
            printf("[%c] = %i ", s, z[s]);
        }
    }
    
    printf("\nlist: ");
    for(int i = 0; i < m; ++i) {
        printf("[%i] = %i ", i, list[i]);
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

    printf("\noccurrences: %i\n", occurrences);
}

