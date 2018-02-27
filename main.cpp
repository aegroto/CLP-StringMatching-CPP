/**
 * A very fast string matching algorithm for small alphabets and long patterns
 * Paper and Algorithm by Charras, Lecroq, Pehoushek.
 * C++ implementation by Lorenzo Catania and Valentino Merlino
**/

#include <stdio.h>
#include <string>
#include "clpsm-linear.h"
#include "utils.h"

using namespace std;

int main() {
    string pattern = "abc";
    string text = "ababcabb";
   
    /*const char* c = pattern.c_str();
    printf("%i\n", utils::maxPeriod(c, pattern.length()));*/

    LinearStringMatcher matcher(pattern, text);
    matcher.execute();
    matcher.debugOutput();
    
    return 0;
}

