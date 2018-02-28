#include "alphatree.h"

AlphaTree::AlphaNode::AlphaNode() {
    father = rightSib = firstChild = NULL;
}

AlphaTree::AlphaTree(size_t _l) {
    l = _l;
    root = AlphaTree::AlphaNode();
}
