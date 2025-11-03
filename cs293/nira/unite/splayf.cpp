#include<iostream>
#include "splayf.h"
using namespace std;

node4::node4(int k) : key(k), left(nullptr), right(nullptr) {}


node4* splay_tree::rightRotate(node4* x) {
    node4* y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

// Left rotation
node4* splay_tree::leftRotate(node4* x) {
    node4* y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

// Splay operation
node4* splay_tree::splay(node4* root, int key) {
    if (!root || root->key == key) return root;

    // Key in left subtree
    if (key < root->key) {
        if (!root->left) return root;

        if (key < root->left->key) {
            root->left->left = splay(root->left->left, key);
            root = rightRotate(root);
        } else if (key > root->left->key) {
            root->left->right = splay(root->left->right, key);
            if (root->left->right)
                root->left = leftRotate(root->left);
        }

        return (root->left) ? rightRotate(root) : root;
    } 
    // Key in right subtree
    else {
        if (!root->right) return root;

        if (key > root->right->key) {
            root->right->right = splay(root->right->right, key);
            root = leftRotate(root);
        } else if (key < root->right->key) {
            root->right->left = splay(root->right->left, key);
            if (root->right->left)
                root->right = rightRotate(root->right);
        }

        return (root->right) ? leftRotate(root) : root;
    }
}

// Insert operation
void splay_tree::insert(int key) {
    if (!root) {
        root = new node4(key);
        return;
    }

    root = splay(root, key);

    if (root->key == key) return; // already exists

    node4* newNode = new node4(key);
    if (key < root->key) {
        newNode->right = root;
        newNode->left = root->left;
        root->left = nullptr;
    } else {
        newNode->left = root;
        newNode->right = root->right;
        root->right = nullptr;
    }
    root = newNode;
}

// Search operation
bool splay_tree::search(int key) {
    root = splay(root, key);
    if (root && root->key == key)
        return true;
    else
        return false;
}

// Delete operation
void splay_tree::deleteKey(int key) {
    if (!root) return;

    root = splay(root, key);

    if (root->key != key) {
        cout << "Key " << key << " not found\n";
        return;
    }

    node4* temp;
    if (!root->left) {
        temp = root;
        root = root->right;
    } else {
        temp = root;
        root = splay(root->left, key); // max of left
        root->right = temp->right;
    }
    delete temp;
}

// In-order traversal
void splay_tree::inorder(node4* node) {
    if (!node) return;
    inorder(node->left);
    cout << node->key << " ";
    inorder(node->right);
}

void splay_tree::display() {
    cout << "Tree (In-order): ";
    inorder(root);
    cout << endl;
}


