#include "alphatrie.h"

AlphaTrie::AlphaTrie(size_t _l) {
    l = _l;
    root = new AlphaNode();
#ifdef DEBUG_TRIE
    root->character = 'R';
#endif
}

void AlphaTrie::addSubstring(const char* sub, int start) {
    AlphaNode *node = root,
              *child = NULL;

    size_t foundChars = 0;

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
        node->addPos(start);
    else
        child->addPos(start);
    // printf("Added position %i at character %c \n", child->getFirstPos()->pos, child->character);

    //print();
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