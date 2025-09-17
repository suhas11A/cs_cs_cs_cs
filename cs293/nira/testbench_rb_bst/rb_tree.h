class node2{
public:
    int key;
    node2* left;
    node2* right;
    node2* p;
    char color;
    node2(int value,char color);
};
class rb_tree{
private:
    node2* nil;
    node2* root;
    void left_rotate(node2* x);
    void right_rotate(node2* x);
    void rb_insert_fixup(node2*z);
    void insert(node2* z);
    node2* minimum(node2* x);
    void rb_transplant(node2* u, node2* v);
    void rb_delete_fixup(node2* x);
    void delete_node(int key);
    bool search(node2* z,int key);
public:
    rb_tree();
    ~rb_tree(){ clear_subtree(root); delete nil;}
    void clear_subtree(node2* x){
        if (x == nil) return;
        clear_subtree(x->left);
        clear_subtree(x->right);
        delete x;
    }
    void insert(int value);
    void truth();
    void delete_key(int key);
    bool search_key(int key);
};