/**
 * A very fast string matching algorithm for small alphabets and long patterns
 * Paper and Algorithm by Charras, Lecroq, Pehoushek.
 * C++ implementation by Lorenzo Catania and Valentino Merlino
**/

#include <stdio.h>
#include <string>
#include "clpsm-linear.h"

using namespace std;

int main() {
    string pattern = "abcab";
    string text = "ababcabb";
    
    LinearStringMatcher matcher(pattern, text);
    matcher.execute();
    matcher.debugOutput();
    
    return 0;
}

