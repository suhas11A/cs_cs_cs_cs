#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <numeric>
#include <cassert>
using namespace std;

class node{
public:
    int value;
    node* left;
    node* right;
    node* parent;
    node(int val) {
        value = val;
        left =nullptr;
        right = nullptr;
        parent = nullptr;
    }
};

bool is_null(node* hehe) {
    if (hehe) return false;
    return true;
}

class binary_search_tree{
public:
    node* root;
    binary_search_tree() {
        root = nullptr;
    }
    void insert(int n) {
        auto temp = root; node* x = nullptr;
        while(!is_null(temp)) {
            x = temp;
            temp = (n>= temp->value)? temp->right : temp->left;
        }
        if (!x) {root = new node(n); return;}
        node* tempo = new node(n);
        ((n>= x->value)? x->right : x->left) = tempo;
        tempo->parent = x;
    }
    node* search(int m) {
        auto temp = root;
        while(!is_null(temp)) {
            if (temp->value==m) return temp;
            temp =  (m>= temp->value)? temp->right : temp->left;
        }
        return nullptr;
    }
    node* successor(node* nodie) {
        if (!is_null(nodie->right)) {
            nodie = nodie->right;
            while(!is_null(nodie->left))  {
                nodie = nodie->left;
            }
            return nodie;
        }
        while(nodie->parent && (nodie->parent)->right==nodie) {
            nodie = nodie -> parent;
        }
        return nodie->parent;
    }
    void delete_node(int m) {
        node* my_node = search(m);
        if (is_null(my_node)) return;
        node* to_del = (is_null(my_node->right) || is_null(my_node->left))? my_node : successor(my_node);
        if (to_del!=my_node) my_node->value = to_del->value;
        node* child = (is_null(to_del->left))? to_del->right : to_del->left;
        if (!is_null(child)) child->parent = to_del->parent;
        if (is_null(to_del->parent)) {root = child; delete to_del; return;}
        ((to_del->parent->left==to_del)? to_del->parent->left : to_del->parent->right) = child;
        delete to_del; return;
    }
    void inorder(node* nodie) {
        inorder_help(nodie);
        cout << '\n';
    }

    void inorder_help(node* nodie){
        if (is_null(nodie)) return;
        inorder_help(nodie->left);
        cout << nodie->value << " ";
        inorder_help(nodie->right);
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

    binary_search_tree s;
    for (int x : vals) s.insert(x);

    // s.inorder(s.root);
    return 0;
}