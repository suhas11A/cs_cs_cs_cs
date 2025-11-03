#include "tree.h"

// Function which returns lca node of given nodes 'a' and 'b'
TreeNode* TREE::findlca(TreeNode* a, TreeNode* b) {
    if (!a || !b) return nullptr;
    if (!a->parent) return a;
    if (!b->parent) return b;
    auto ai = a;
    auto bi = b;
    int ha = 0;
    int hb = 0;
    while (ai) {
      ai = ai->parent;
      ha++;
    }
    while (bi) {
      bi = bi->parent;
      hb++;
    }
    ai = a;
    bi = b;
    if (ha>hb) {
      int diff = ha-hb;
      while(diff--) {
        ai = ai->parent;
      }
    }
    if (ha<hb) {
      int diff = hb-ha;
      while(diff--) {
        bi = bi->parent;
      }
    }
    while(ai!=bi) {
      ai = ai->parent;
      bi = bi->parent;
    }
    return ai;
}