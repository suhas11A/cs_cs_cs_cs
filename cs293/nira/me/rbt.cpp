#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <numeric>
#include <cassert>
using namespace std;


class node {
public:
	int data;
	int is_red;
	node* parent;
	node* right;
	node* left;
    node(int data): data(data), is_red(1), parent(nullptr), right(nullptr), left(nullptr) {}
};

class RedBlackTree {
public:
    node* root = nullptr;

    typedef node* ptr;

    RedBlackTree() {}

    ~RedBlackTree(){ clear(root); }
    static void clear(node* p){ if(!p) return; clear(p->left); clear(p->right); delete p; }

    const ptr getRoot() const { 
        return root; 
    }

    ptr insert(int data) {
        ptr newnodePtr = new node(data);
        if (!root) {
            root = newnodePtr;
            root->is_red = 0;
            return newnodePtr;
        }
        insert(root, newnodePtr);
        fixup(newnodePtr);
        return newnodePtr;
    }

    void insert(ptr start, ptr newnodePtr) {
        int n = newnodePtr->data;
        auto temp = start; ptr x = nullptr;
        while(temp) {
            x = temp;
            temp = (n>= temp->data)? temp->right : temp->left;
        }
        ((n>= x->data)? x->right : x->left) = newnodePtr;
        newnodePtr->parent = x;
    }

    void printRBT(ptr start, const std::string& prefix="", bool isLeftChild=false) const {
        if (!start) return;

        std::cout << prefix;
        std::cout << (isLeftChild ? "|--" : "|__" );
        std::cout << start->data << "(" << start->is_red << ")" << std::endl;
        printRBT(start->left, prefix + (isLeftChild ? "│   " : "    "), true);
        printRBT(start->right, prefix + (isLeftChild ? "│   " : "    "), false);
    }

    void rightrotate(ptr a) {
        if (!a) return;
        auto my_parent = a->parent;
        auto b = a->right;
        if (!b) return;
        a->right = b->left;
        if (a->right) a->right->parent = a;
        a->parent = b;
        b->left = a;
        b->parent = my_parent;
        if (!my_parent) {
            root = b; return;
        }
        (my_parent->right==a ? my_parent->right : my_parent->left) = b;
        return;
    }

    void leftrotate(ptr b) {
        if (!b) return;
        auto my_parent = b->parent;
        auto a = b->left;
        if (!a) return;
        b->left = a->right;
        if (b->left) b->left->parent=b;
        b->parent = a;
        a->right = b;
        a->parent = my_parent;
        if (!my_parent) {
            root = a; return;
        }
        (my_parent->right==b ? my_parent->right : my_parent->left) = a;
        return;
    }

    void fixup(ptr loc) {
        if (!loc) return;
        if (!loc->is_red) return;
        if (!loc->parent) {loc->is_red=0; return;}
        if (!loc->parent->parent) {loc->parent->is_red=0; return;}
        auto my_parent = loc->parent;
        if (!my_parent->is_red) return;
        auto my_gp = loc->parent->parent;
        auto my_unc = (my_gp->left==my_parent)? my_gp->right : my_gp->left;
        if (my_unc && my_unc->is_red) {
            my_parent->is_red = 0;
            my_unc->is_red = 0;
            my_gp->is_red = 1;
            fixup(my_gp);
            return;
        }
        bool me_is_left_child = (my_parent->left==loc);
        bool parent_is_left_child = (my_gp->left==my_parent);
        if (me_is_left_child!=parent_is_left_child) {
            if (me_is_left_child) leftrotate(my_parent);
            else rightrotate(my_parent);
            std::swap(loc, my_parent);
        }
        if (parent_is_left_child) leftrotate(my_gp);
        else rightrotate(my_gp);
        my_parent->is_red = 0;
        my_gp->is_red = 1;
        return;
    }

    void inorder(ptr start) const {
        if (!start)
            return;
        
        inorder(start->left);
        std::cout << start->data << " ";
        inorder(start->right);
    }

    void delete_node(int m) {
        ptr my_node = search(m);
        if (!my_node) return;
        ptr to_del = (!my_node->right || !my_node->left)? my_node : successor(my_node);
        if (to_del!=my_node) my_node->data = to_del->data;
        ptr child = (!to_del->left)? to_del->right : to_del->left;
        if (child) child->parent = to_del->parent;
        if (!to_del->parent) {root = child; if (root) root->is_red = 0; delete to_del; return;}
        ((to_del->parent->left==to_del)? to_del->parent->left : to_del->parent->right) = child;
        int me_is_red = to_del->is_red; //
        ptr my_parent = to_del->parent; //
        if (!me_is_red) { //
            if (child && child->is_red) child->is_red = 0; //
            else fix_delete(child, my_parent); //
        } //
        delete to_del; return;
    }

    ptr successor(ptr nodie) {
        if (nodie->right) {
            nodie = nodie->right;
            while(nodie->left)  {
                nodie = nodie->left;
            }
            return nodie;
        }
        while(nodie->parent && (nodie->parent)->right==nodie) {
            nodie = nodie -> parent;
        }
        return nodie->parent;
    }

    ptr search(int m) {
        auto temp = root;
        while(temp) {
            if (temp->data==m) return temp;
            temp = (m>= temp->data)? temp->right : temp->left;
        }
        return nullptr;
    }
    void fix_delete(ptr x, ptr parent) {
        while (x != root && (!x || x->is_red == 0)) {
            if (x == (parent ? parent->left : nullptr)) {
                ptr w = parent ? parent->right : nullptr;
                if (w && w->is_red) {
                    w->is_red = 0;
                    parent->is_red = 1;
                    rightrotate(parent);              // your "rightrotate" = standard left-rotate
                    w = parent ? parent->right : nullptr;
                }
                bool wlr = w && w->left  && w->left->is_red;
                bool wrr = w && w->right && w->right->is_red;
                if (!w || (!wlr && !wrr)) {
                    if (w) w->is_red = 1;
                    x = parent;
                    parent = x ? x->parent : nullptr;
                } else {
                    if (!wrr) {
                        if (w->left) w->left->is_red = 0;
                        w->is_red = 1;
                        leftrotate(w);                 // your "leftrotate" = standard right-rotate
                        w = parent ? parent->right : nullptr;
                    }
                    if (w) w->is_red = parent ? parent->is_red : 0;
                    parent->is_red = 0;
                    if (w && w->right) w->right->is_red = 0;
                    rightrotate(parent);               // standard left-rotate
                    x = root;
                }
            } else {
                ptr w = parent ? parent->left : nullptr;
                if (w && w->is_red) {
                    w->is_red = 0;
                    parent->is_red = 1;
                    leftrotate(parent);               // standard right-rotate
                    w = parent ? parent->left : nullptr;
                }
                bool wlr = w && w->left  && w->left->is_red;
                bool wrr = w && w->right && w->right->is_red;
                if (!w || (!wlr && !wrr)) {
                    if (w) w->is_red = 1;
                    x = parent;
                    parent = x ? x->parent : nullptr;
                } else {
                    if (!wlr) {
                        if (w->right) w->right->is_red = 0;
                        w->is_red = 1;
                        rightrotate(w);                // standard left-rotate
                        w = parent ? parent->left : nullptr;
                    }
                    if (w) w->is_red = parent ? parent->is_red : 0;
                    parent->is_red = 0;
                    if (w && w->left) w->left->is_red = 0;
                    leftrotate(parent);                // standard right-rotate
                    x = root;
                }
            }
        }
        if (x) x->is_red = 0;
        if (root) root->is_red = 0;
    }
};


int main() {
    int n;
    if (!(std::cin >> n)) return 0;
    std::vector<int> vals(n);
    std::iota(vals.begin(), vals.end(), 1);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(vals.begin(), vals.end(), gen);

    RedBlackTree s;
    for (int x : vals) s.insert(x);

    s.inorder(s.root);
    return 0;
}
