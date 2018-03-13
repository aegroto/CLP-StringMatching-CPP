/**
 * "GammaTrie" class definition file
 *
 * Released under ZLib license: https://www.zlib.net/zlib_license.html
 *
 * Lorenzo Catania
**/

#include "gammatrie.h"

GammaTrie::GammaTrie(const char* str, size_t m, size_t _l, char _minChar, char _maxChar) {
    l = _l;
    minChar = _minChar;
    maxChar = _maxChar;

    root = new GammaNode(minChar, maxChar);

    #ifdef DEBUG_TRIE
        root->character = 'R';
    #endif

    GammaNode *node, *child;
    size_t foundChars;
    const size_t limit = m - l + 1;
    char* sub;

    for(size_t k = 0; k < limit; ++k) {
        node = root;
        child = NULL;
        foundChars = 0;
        sub = (char*) (str + k);

        child = node->get(sub[foundChars]);

        while(foundChars < l && child != NULL) {
            ++foundChars;
            
            
            node = child;        
            child = node->get(sub[foundChars]);        
        }

        while(foundChars < l) {
            child = new GammaNode(minChar, maxChar);
#ifdef DEBUG_TRIE
            child->character = sub[foundChars];
#endif
            node->set(sub[foundChars], child);
            node = child;

            ++foundChars;
        }

        if(child == NULL)
            node->addPos(k);
        else
            child->addPos(k);
    }
}

GammaTrie::~GammaTrie() {
    delete root;
}

#ifdef DEBUG_TRIE
void GammaTrie::print() {
    std::queue<GammaNode*> Q;
    
    Q.push(root);

    const size_t limit = maxChar + 1;

    while(!Q.empty()) {
        GammaNode* current = Q.front();
        
        std::queue<GammaNode*> Qcopy = Q;

        // PRINT THE QUEUE
        /*printf("Q : [ ");
        while(!Qcopy.empty()) {
            printf("%c ", Q.front()->character);
            Q.pop();
        }
        printf("]");*/

        printf("%c --> [ ", current->character);

        for(int i = minChar; i < limit; ++i) {
            if(current->get(i) != NULL) {
                printf("%c (%i) ", current->get(i)->character, i);
                Q.push(current->get(i));
            }
        }
        
        printf("]");
        if(current->getFirstPos() != NULL) {
            printf(" { ");
            GammaNode::Position* position = current->getFirstPos();
            while(position != NULL) {
                printf("%i ", position->pos);
                position = position->nextPos;
            }
            printf("}");
        }

        printf("\n");
        Q.pop();
    }
}
#endif
