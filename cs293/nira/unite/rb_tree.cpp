#include<iostream>
#include "rb_tree.h"
using namespace std;

node2::node2(int value,char color){
    key=value;
    this->color=color;
    left=nullptr;
    right=nullptr;
    p=nullptr;
}


void rb_tree::left_rotate(node2* x){
    node2* y=x->right;
    x->right=y->left;
    if(y->left!=nil){
        y->left->p=x;
    }
    y->p=x->p;
    if(x->p==nil){
        root=y;
    }
    else if(x==x->p->left){
        x->p->left=y;
    }
    else{
        x->p->right=y;
    }
    y->left=x;
    x->p=y;
}

void rb_tree::right_rotate(node2* x){
    node2* y=x->left;
    x->left=y->right;
    if(y->right!=nil){
        y->right->p=x;
    }
    y->p=x->p;
    if(x->p==nil){
        root=y;
    }
    else if(x==x->p->right){
        x->p->right=y;
    }
    else{
        x->p->left=y;
    }
    y->right=x;
    x->p=y;
}

void rb_tree::rb_insert_fixup(node2*z){
    while (z->p->color=='r'){
        if(z->p==z->p->p->left){
            node2* y=z->p->p->right;
            if(y->color=='r'){
                z->p->color='b';
                y->color='b';
                z->p->p->color='r';
                z=z->p->p;
            }
            else{
                if(z==z->p->right){
                    z=z->p;
                    left_rotate(z);
                }
                z->p->color='b';
                z->p->p->color='r';
                right_rotate(z->p->p);
            }
        }
        else{
            node2* y=z->p->p->left;
            if(y->color=='r'){
                z->p->color='b';
                y->color='b';
                z->p->p->color='r';
                z=z->p->p;
            }
            else{
                if(z==z->p->left){
                    z=z->p;
                    right_rotate(z);
                }
                z->p->color='b';
                z->p->p->color='r';
                left_rotate(z->p->p);
            }
        }
    }
    root->color='b';
}

void rb_tree::insert(node2* z){
    node2* x=root;
    node2* y=nil;
    while(x!=nil){
        y=x;
        if(z->key<x->key){
            x=x->left;
        }
        else{
            x=x->right;
        }
    }
    z->p=y;
    if(y==nil){
        root=z;
    }
    else if(z->key<y->key){
        y->left=z;
    }
    else{
        y->right=z;
    }
    z->left=nil;
    z->right=nil;
    z->color='r';
    rb_insert_fixup(z);
}

bool rb_tree::search(node2* z,int key){
    if(z==nil){
        return false;
    }
    if(z->key==key){
        return true;
    }
    else if(z->key>key){
        return search(z->left,key);
    }

    else if(z->key<key){
        return search(z->right,key);
    }
    else{
        return false;
    }
}

bool rb_tree::search_key(int key){
    return search(root,key);
}

node2* rb_tree::minimum(node2* x) {
    while (x->left != nil) {
        x = x->left;
    }
    return x;
}

void rb_tree::rb_transplant(node2* u, node2* v) {
    if (u->p == nil)
        root = v;
    else if (u == u->p->left)
        u->p->left = v;
    else
        u->p->right = v;
    v->p = u->p;
}

void rb_tree::rb_delete_fixup(node2* x) {
    while (x != root && x->color == 'B') {
        if (x == x->p->left) {
            node2* w = x->p->right;
            if (w->color == 'R') {
                w->color = 'B';
                x->p->color = 'R';
                left_rotate(x->p);
                w = x->p->right;
            }
            if (w->left->color == 'B' && w->right->color == 'B') {
                w->color = 'R';
                x = x->p;
            } else {
                if (w->right->color == 'B') {
                    w->left->color = 'B';
                    w->color = 'R';
                    right_rotate(w);
                    w = x->p->right;
                }
                w->color = x->p->color;
                x->p->color = 'B';
                w->right->color = 'B';
                left_rotate(x->p);
                x = root;
            }
        } else {
            node2* w = x->p->left;
            if (w->color == 'R') {
                w->color = 'B';
                x->p->color = 'R';
                right_rotate(x->p);
                w = x->p->left;
            }
            if (w->right->color == 'B' && w->left->color == 'B') {
                w->color = 'R';
                x = x->p;
            } else {
                if (w->left->color == 'B') {
                    w->right->color = 'B';
                    w->color = 'R';
                    left_rotate(w);
                    w = x->p->left;
                }
                w->color = x->p->color;
                x->p->color = 'B';
                w->left->color = 'B';
                right_rotate(x->p);
                x = root;
            }
        }
    }
    x->color = 'B';
}

void rb_tree::delete_node(int key) {
    node2* z = root;
    while (z != nil) {
        if (z->key == key)
            break;
        else if (key < z->key)
            z = z->left;
        else
            z = z->right;
    }

    if (z == nil) {
        cout << "Key " << key << " not found in tree.\n";
        return;
    }

    node2* y = z;
    char y_original_color = y->color;
    node2* x;

    if (z->left == nil) {
        x = z->right;
        rb_transplant(z, z->right);
    }
    else if (z->right == nil) {
        x = z->left;
        rb_transplant(z, z->left);
    }
    else {
        y = minimum(z->right);
        y_original_color = y->color;
        x = y->right;
        if (y->p == z)
            x->p = y;
        else {
            rb_transplant(y, y->right);
            y->right = z->right;
            y->right->p = y;
        }
        rb_transplant(z, y);
        y->left = z->left;
        y->left->p = y;
        y->color = z->color;
    }

    delete z;

    if (y_original_color == 'B')
        rb_delete_fixup(x);
}

rb_tree::rb_tree(){
    nil=new node2(0,'b');
    nil->left = nil->right = nil->p = nil;
    root = nil;
}
void rb_tree::insert(int value){
    node2*z=new node2(value,'r');
    insert(z);
}
void rb_tree::truth(){
    cout<<root->color<<endl;
    cout<<root->right->color<<endl;
    cout<<root->right->key<<endl;
    cout<<root->right->right->left->key<<endl;
    cout<<root->right->right->left->color<<endl;
}
void rb_tree::delete_key(int key) {
    delete_node(key);
}


