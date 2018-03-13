/**
 * "SkipSearchMatcher" class definition file
 *
 * Released under ZLib license: https://www.zlib.net/zlib_license.html
 *
 * Valentino Merlino
**/

#include "skipsearch.h"

using namespace std;

SkipSearchMatcher::SkipSearchMatcher(string& sx,string& sy) {
	m = sx.length();
	n = sy.length();
	x = sx.c_str();
    y = sy.c_str();
    occurrences = 0;
    z=new int*[256];
    for(int i = 0; i < 256; ++i){
    	z[i]=new int[m];
    	for(int j = 0; j < m; ++j){
    		z[i][j]=-1;
    	}
    }
}

SkipSearchMatcher::~SkipSearchMatcher() {
	for(int i=0 ; i< 256 ; i++)
			delete[] z[i];
	delete[] z;
}

void SkipSearchMatcher::preprocessing(){
	for(int i = 0; i < m; ++i){
			int j=0;
			while(z[x[i]][j]!=(-1))
				++j;
			z[x[i]][j]=i;
	}
}

void SkipSearchMatcher::search(){
	int index=-1;

	for(int j=m-1;j<n;j+=m) {
		for(int i=0; i<m /*&& z[y[j]][i]!=-1*/;i++) {
			index=z[y[j]][i];

			if(index != -1) {
				int k = 0;
				while(k < m && y[j - index + k] == x[k]) 
					++k;

				if(k == m)
					report();
			}
		}
	}
}

void SkipSearchMatcher::execute(){
	preprocessing();
	search();
}

void SkipSearchMatcher::printOutput() {
	printf("\n-- SKIP SEARCH MATCHER --\nx: %s\ny: %s\nm: %zu, n: %zu\n", x, y, m, n);

    printf("occurrences: %i\n", occurrences);
}