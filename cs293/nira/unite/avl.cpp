#include<iostream>
#include "avl.h"
using namespace std;


node3::node3(int node_value){
    value=node_value;
    left=nullptr;
    right=nullptr;
    height=1;
}


int avl::balance(node3* n){
    return n ? (((n->left)?n->left->height:0)-((n->right)?n->right->height:0)):0;
}
int avl::height(node3*x){
    return x? x->height:0;
}
node3* avl::rotate_right(node3* z){
    node3* y=z->left;
    node3* t3=y->right;
    y->right=z;
    z->left=t3;
    z->height=max(height(z->left),height(z->right))+1;
    y->height=max(height(y->left),height(y->right))+1;
    
    return y;
}
node3* avl::rotate_left(node3* z){
    node3* y=z->right;
    node3* t3=y->left;
    y->left=z;
    z->right=t3;
    z->height=max(height(z->left),height(z->right))+1;
    y->height=max(height(y->left),height(y->right))+1;
    
    return y;
}

node3* avl::rotate_stuff(node3* x){
    if (!x) return x;  
    x->height = max(height(x->left), height(x->right)) + 1;

    int bf = balance(x);
    if(bf>1 && balance(x->left)>=0){
        return rotate_right(x);
    }
    if(bf>1 && balance(x->left)<0){
        x->left=rotate_left(x->left);
        return rotate_right(x);
    }
    if(bf<-1 && balance(x->right)<=0){
        return rotate_left(x);
    }
    if(bf<-1 && balance(x->right)>0){
        x->right=rotate_right(x->right);
        return rotate_left(x);
    }
    return x;
}

node3* avl::insert(node3* nodie,int n){
    if(nodie==nullptr){
        return new node3(n);
    }
    if (n<nodie->value){
        nodie->left=insert(nodie->left,n);
    } 
    else if(n>nodie->value){
        nodie->right=insert(nodie->right,n);
    } 
    else{
        return nodie;
    }
    return rotate_stuff(nodie);
}


bool avl::search(node3* nodie, int m){
    if(nodie->value==m){
        return true;
    }
    else if(nodie->value>m && nodie->left!=nullptr){
        return search(nodie->left,m);
    }
    else if(nodie->value<m && nodie->right!=nullptr){
        return search(nodie->right,m);
    }
    else{
        return false;
    }
}

node3* avl::go_to_lefts_max(node3* nodie){
    nodie=nodie->left;
    while(nodie && (nodie->right)!=nullptr){
        nodie=nodie->right;
    }
    return nodie;
}

node3* avl::delete_node(node3* nodie, int m){
    if(nodie==nullptr){
        return nullptr;
    }
    if(m<nodie->value){
        nodie->left=delete_node(nodie->left,m);
    }
    else if(m>nodie->value){
        nodie->right=delete_node(nodie->right,m);
    }
    else{
        if(nodie->left==nullptr){
            node3* temp=nodie->right;
            delete nodie;
            return temp;
        } 
        else if(nodie->right==nullptr) {
            node3* temp=nodie->left;
            delete nodie;
            return temp;
        }
        else{
            node3* replacement=go_to_lefts_max(nodie);
            nodie->value=replacement->value;
            nodie->left=delete_node(nodie->left,replacement->value);
        }
    }
    if(nodie==nullptr){
        return nodie;
    }
    nodie->height=max(height(nodie->left),height(nodie->right))+1;
    int n=balance(nodie);
    if(n>1 && balance(nodie->left)>=0){
        return rotate_right(nodie);
    }
    if(n>1 && balance(nodie->left)<0){
        nodie->left=rotate_left(nodie->left);
        return rotate_right(nodie);
    }
    if(n<-1 && balance(nodie->right)<0){
        return rotate_left(nodie);
    }
    if(n<-1 && balance(nodie->right)>=0){
        nodie->right=rotate_right(nodie->right);
        return rotate_left(nodie);
    }
    return nodie;
}

avl::avl(){
    nodie=nullptr;
}
void avl::insert(int value){
    if(nodie==nullptr){
        nodie=new node3(value);
    }
    else{
    nodie=insert(nodie,value);
    }
}
node3* avl::left(){
    return nodie;
}
bool avl::search(int value){
    return search(nodie,value);
}
void avl::delete_node(int value){
    nodie=delete_node(nodie,value);
}

