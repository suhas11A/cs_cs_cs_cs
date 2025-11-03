#include "two_three_four.h"
// Fill in the missing functions

// -----------------------------
// BigNode constructor
// -----------------------------
BigNode::BigNode()
{
    A = -1;
    B = -1;
    C = -1;
    L = M1 = M2 = R = nullptr;
}
RedBlackTree::RedBlackTree()
{
    root = nullptr;
}

struct node *RedBlackTree::getRoot()
{
    return root;
};

void RedBlackTree::setRoot(node *newroot)
{
    root = newroot;
}

// function to perform RBT insertion of a node
node *RedBlackTree::insert(node *trav,
                           node *temp)
{
    // If the tree is empty,
    // return a new node

    // Otherwise recur down the tree

    // Return the (unchanged) node pointer
    return trav;
}

// Helper for pretty printing (internal; not in header)
// Credits to Adrian Schneider
static void printRBTHelper(node *n, const std::string &prefix, bool isLeft)
{
    if (!n)
        return;
    std::cout << prefix;
    std::cout << (isLeft ? "|--" : "|__");
    std::cout << n->d << "(" << (n->c == 0 ? "B" : "R") << ")" << std::endl;
    printRBTHelper(n->l, prefix + (isLeft ? "│   " : "    "), true);
    printRBTHelper(n->r, prefix + (isLeft ? "│   " : "    "), false);
}

void RedBlackTree::printRBT(const std::string &prefix, bool isLeft)
{
    // public wrapper prints from root; ignore args and use root for consistency
    (void)prefix;
    (void)isLeft;
    printRBTHelper(root, "", true);
}

void RedBlackTree::rightrotate(node *temp)
{ // Function performing right rotation of the passed node
}

void RedBlackTree::leftrotate(node *temp)
{
    // Function performing left rotation of the passed node
}

void RedBlackTree::fixup(node *pt)
{
    // This function fixes violations
    // caused by RBT insertion
}

void RedBlackTree::inorder(node *trav)
{ // Function to print inorder traversal of the fixated tree, no changes needed here keep it as it is
    if (!trav)
        return;
    inorder(trav->l);
    std::cout << trav->d << " ";
    inorder(trav->r);
}

TwoThreeFourTree::TwoThreeFourTree()
{ // no change needed here
    tree = new RedBlackTree();
}

void TwoThreeFourTree::insert(int key)
{
    // create new node here then insert and then fix
}

// just a forward declaration
static BigNode *Convert(node *root);

BigNode *TwoThreeFourTree::convert()
{
    return Convert(tree->getRoot());
}

static BigNode *Convert(node *root)
{ // Convert RB to 2-3-4 BigNode structure
}

void TTF(BigNode *root)
{
    if (!root)
        return;
    if (root->L)
        TTF(root->L);
    if (root->A != -1)
        std::cout << root->A << " ";
    if (root->M1)
        TTF(root->M1);
    if (root->B != -1)
        std::cout << root->B << " ";
    if (root->M2)
        TTF(root->M2);
    if (root->C != -1)
        std::cout << root->C << " ";
    if (root->R)
        TTF(root->R);

}
