/**
 * "SkipSearchMatcher" class header file
 *
 * Released under ZLib license: https://www.zlib.net/zlib_license.html
 *
 * Valentino Merlino
**/

#ifndef SKIPSEARCHMATCHER_H_
#define SKIPSEARCHMATCHER_H_

#include <stdio.h>
#include <string>

using namespace std;

class SkipSearchMatcher {
private:
	const char* x;
	const char* y;
	size_t m,n;
	int occurrences;
	int** z;
	void report(){++occurrences;}
public:
	SkipSearchMatcher(string& sx,string& sy);
	virtual ~SkipSearchMatcher();
	
	void preprocessing();
	void search();

	void execute();
	int getOccurrences() {return occurrences;}
	void printOutput();
};

#endif /* SKIPSEARCHMATCHER_H_ */
