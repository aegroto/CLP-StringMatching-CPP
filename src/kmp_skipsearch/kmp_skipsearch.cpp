/**
 * "KMPSkipSearchMatcher" class definition file
**/

#include "kmp_skipsearch.h"

using namespace std;

KMPSkipSearchMatcher::KMPSkipSearchMatcher(string& sx, string& sy) {   
    z = new int[255];
    
    m = sx.length();
    n = sy.length();
    
    list = new int[m];
    mpNext = new int[m + 1];
    kmpNext = new int[m + 1];
    
    x = sx.c_str();
    y = sy.c_str();

    occurrences = 0;

    preprocessed = searched = false;
}

KMPSkipSearchMatcher::~KMPSkipSearchMatcher() {
    delete[] z;
    delete[] list;    
    delete[] mpNext;
    delete[] kmpNext;
}
        
void KMPSkipSearchMatcher::preprocessing() {
    if(preprocessed) return;
    mpPreprocessing();
    kmpPreprocessing();
    
    for(int s = 0; s < 255; ++s)
        z[s] = -1;
    
    list[0] = -1;
    z[x[0]] = 0;
    for(int i = 1; i < m; ++i) {
        list[i] = z[x[i]];
        z[x[i]] = i;
    }

    preprocessed = true;
}

void KMPSkipSearchMatcher::mpPreprocessing() {
    int i = 0, 
        j = mpNext[0] = -1;

    while (i < m) {
        while (j >= 0 && x[i] != x[j])
            j = mpNext[j];

        mpNext[++i] = ++j;
    }
}

void KMPSkipSearchMatcher::kmpPreprocessing() {
    int i = 0,
        j = kmpNext[0] = -1;

    while (i < m) {
        while (j >= 0 && x[i] != x[j])
            j = kmpNext[j];

        ++i; ++j;

        if (i<m && x[i] == x[j])
            kmpNext[i] = kmpNext[j];
        else
            kmpNext[i] = j;
    }
}

int KMPSkipSearchMatcher::attempt(int &wall, int &start) {
    int k = wall - start;
    while(k < m && x[k] == y[k + start])
        ++k;

    return k;
}

void KMPSkipSearchMatcher::advanceSkip(int &i, int &j) {
    do {    
        j += m;
    } while(j < n && z[y[j]] < 0);

    if(j < n) 
        i = z[y[j]];
}

void KMPSkipSearchMatcher::search() {
    if(searched) return;

    int wall, start, i, j, k, kmpStart, period, lastPIndex;

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
        }   
    }

    searched = true;
}

void KMPSkipSearchMatcher::report(int index) {
    ++occurrences;
}

void KMPSkipSearchMatcher::execute() {
    if(preprocessed && searched) return;
    preprocessing();
    search();
}

void KMPSkipSearchMatcher::printOutput() {
    printf("\n-- KMP SKIP SEARCH MATCHER --\nx: %s\ny: %s\nm: %zu, n: %zu", x, y, m, n);

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

