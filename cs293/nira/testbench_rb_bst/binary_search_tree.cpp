#include<iostream>
#include "binary_search_tree.h"
using namespace std;

node::node(int node_value){
    value=node_value;
    left=nullptr;
    right=nullptr;
}

void binary_search_tree::insert(node* nodie, int n){
    if (n<nodie->value && nodie->left!=nullptr){
        insert((nodie->left),n);
    }
    if (n>nodie->value && nodie->right!=nullptr){
        insert((nodie->right),n);
    }
    if (n<nodie->value && nodie->left==nullptr){
        nodie->left=new node(n);
    }
    if (n>nodie->value && nodie->right==nullptr){
        nodie->right=new node(n);
    }
}

bool binary_search_tree::search(node* nodie, int m){
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

node* binary_search_tree::go_to_lefts_max(node* nodie){
    nodie=nodie->left;
    while(nodie && (nodie->right)!=nullptr){
        nodie=nodie->right;
    }
    return nodie;
}

node* binary_search_tree::delete_node(node* nodie, int m){
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
            node* temp=nodie->right;
            delete nodie;
            return temp;
        } 
        else if(nodie->right==nullptr) {
            node* temp=nodie->left;
            delete nodie;
            return temp;
        }
        else{
            node* replacement=go_to_lefts_max(nodie);
            nodie->value=replacement->value;
            nodie->left=delete_node(nodie->left,replacement->value);
        }
    }
    return nodie;
}

binary_search_tree::binary_search_tree(){
    nodie=nullptr;
}
void binary_search_tree::insert(int value){
    if(nodie==nullptr){
        nodie=new node(value);
    }
    else{
    insert(nodie,value);
    }
}
bool binary_search_tree::search(int value){
    return search(nodie,value);
}
void binary_search_tree::delete_node(int value){
    nodie=delete_node(nodie,value);
}


