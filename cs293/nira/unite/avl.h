class node3{
public:
    int value;
    node3*left;
    node3*right;
    int height;
    node3(int node_value);
};

class avl{
private:
    node3* nodie;
    int balance(node3* n);
    int height(node3*x);
    node3* rotate_right(node3* z);
    node3* rotate_left(node3* z);
    node3* rotate_stuff(node3*x);
    node3* insert(node3* nodie, int n);
    bool search(node3* nodie, int m);
    node3* go_to_lefts_max(node3* nodie);
    node3* delete_node(node3* nodie, int m);
public:
    avl();
    void insert(int value);
    node3* left();
    bool search(int value);
    void delete_node(int value);
};