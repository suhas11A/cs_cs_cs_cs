#include <bits/stdc++.h>
using namespace std;

// ---------------- Minimal BST used for timing ----------------
struct BSTNode {
    int value; BSTNode *left=nullptr,*right=nullptr,*parent=nullptr;
    BSTNode(int x):value(x) {}
};
struct BST {
    BSTNode* root=nullptr;
    void insert(int n) {
        auto temp = root; BSTNode* x = nullptr;
        while(temp) {
            x = temp;
            temp = (n>= temp->value)? temp->right : temp->left;
        }
        if (!x) {root = new BSTNode(n); return;}
        BSTNode* tempo = new BSTNode(n);
        ((n>= x->value)? x->right : x->left) = tempo;
        tempo->parent = x;
    }
    ~BST(){ clear(root); }
    static void clear(BSTNode* p){ if(!p) return; clear(p->left); clear(p->right); delete p; }

};

// ---------------- Simple Red-Black Tree (compatible API) -----
struct node {
    int data; int is_red=1;
    node *parent=nullptr,*left=nullptr,*right=nullptr;
    node(int x):data(x){}
};
struct RBT {
    using ptr=node*;
    ptr root=nullptr;

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

    ptr search(int m) {
        auto temp = root;
        while(temp) {
            if (temp->data==m) return temp;
            temp = (m>= temp->data)? temp->right : temp->left;
        }
        return nullptr;
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

    void leftrotate(ptr b)  {
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
    ~RBT(){ clear(root); }
    static void clear(node* p){ if(!p) return; clear(p->left); clear(p->right); delete p; }
};

// ---------------- Benchmark harness ---------------------------
static inline uint64_t now_ns(){
    return chrono::duration_cast<chrono::nanoseconds>(
        chrono::steady_clock::now().time_since_epoch()).count();
}

template<class Tree>
double time_inserts(const vector<int>& vals){
    Tree t;
    uint64_t t0=now_ns();
    for(int x: vals) t.insert(x);
    uint64_t t1=now_ns();
    // drop tree by going out of scope (we don't free nodes individually)
    return (t1 - t0) / 1e6; // ms
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<size_t> Ns = {10,100,1000,10000,100000,1000000,10000000};
    // 10,000,000 will use a lot of RAM/time; enable only if your machine can handle it.

    std::mt19937_64 rng(42);

    cout << "n,BST_ms,RBT_ms,Winner\n";
    for(size_t n: Ns){
        vector<int> vals(n);
        iota(vals.begin(), vals.end(), 1);
        shuffle(vals.begin(), vals.end(), rng);

        // Use the same shuffled order for both trees
        double bst_ms = time_inserts<BST>(vals);
        double rbt_ms = time_inserts<RBT>(vals);

        string win = (bst_ms < rbt_ms ? "BST" : "RBT");
        cout << n << "," << fixed << setprecision(2)
             << bst_ms << "," << rbt_ms << "," << win << "\n";
    }
    return 0;
}
