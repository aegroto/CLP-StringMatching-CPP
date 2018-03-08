/**
 * "AlphaTrie" class definition file
 *
 * Lorenzo Catania
**/

#include "alphatrie.h"

AlphaTrie::AlphaTrie(const char* str, size_t m, size_t _l) {
    l = _l;
    root = new AlphaNode();
    #ifdef DEBUG_TRIE
        root->character = 'R';
    #endif

    AlphaNode *node, *child;
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
            child = new AlphaNode();
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

AlphaTrie::~AlphaTrie() {
    delete root;
}

#ifdef DEBUG_TRIE
void AlphaTrie::print() {
    std::queue<AlphaNode*> Q;
    
    Q.push(root);

    while(!Q.empty()) {
        AlphaNode* current = Q.front();
        
        std::queue<AlphaNode*> Qcopy = Q;

        // PRINT THE QUEUE
        /*printf("Q : [ ");
        while(!Qcopy.empty()) {
            printf("%c ", Q.front()->character);
            Q.pop();
        }
        printf("]");*/

        printf("%c --> [ ", current->character);

        for(int i = 0; i < 256; ++i) {
            if(current->get(i) != NULL) {
                printf("%c (%i) ", current->get(i)->character, i);
                Q.push(current->get(i));
            }
        }
        
        printf("]");
        if(current->getFirstPos() != NULL) {
            printf(" { ");
            AlphaNode::Position* position = current->getFirstPos();
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
