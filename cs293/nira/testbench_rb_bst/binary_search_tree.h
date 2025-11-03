class node{
public:
    int value;
    node*left;
    node*right;
    node(int node_value);
};

class binary_search_tree{
private:
    node*nodie;
    void insert(node* nodie, int n);
    bool search(node* nodie, int m);
    node* go_to_lefts_max(node* nodie);
    node* delete_node(node* nodie, int m);
public:
    binary_search_tree();
    ~binary_search_tree(){ clear(nodie); }
    static void clear(node* p){ if(!p) return; clear(p->left); clear(p->right); delete p; }
    void insert(int value);
    bool search(int value);
    void delete_node(int value);
};