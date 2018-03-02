/**
 * A very fast string matching algorithm for small alphabets and long patterns
 * Paper and Algorithm by Charras, Lecroq, Pehoushek.
 * C++ implementation by Lorenzo Catania and Valentino Merlino
**/

#include <stdio.h>
#include <string>
#include <ctime>
#include <cstdlib>

#include "helpers.h"
#include "testutils.h"
#include "alphatree.h"    

#define AlphaNode AlphaTree::AlphaNode 

using namespace std;

AlphaNode* createTestNode(char c) {
    AlphaNode* node = new AlphaNode();
    node->setCharacter(c);
    return node;
}

int main() {
    srand(time(0));

    // debug::debugKMPSSOnMP(4, 15, 'a', 'c', 1000000);

    string pattern ="abcabaa";
    size_t l = 3;

    AlphaTree alphatree(l);
    /*for(int i = 0; i < pattern.length() - l + 1; i++) {
        alphatree.addSubstring(&pattern[i]);
        printf("\n\n");
    }*/
    // alphatree.addSubstring(&pattern[0]);
    // alphatree.addSubstring(&pattern[1]);
    
    AlphaNode *a1 = createTestNode('a');
    AlphaNode *b1 = createTestNode('b');
    AlphaNode *c1 = createTestNode('c');
    
    alphatree.getRoot().setFirstChild(a1);
    a1->setRightSib(b1);
    b1->setRightSib(c1);
    
    alphatree.print();
    return 0;
}

