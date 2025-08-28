class node4 {
public:
    int key;
    node4 *left, *right;
    node4(int k);
};
class splay_tree{
public:
    node4* root = nullptr;
    node4* rightRotate(node4* x);
    node4* leftRotate(node4* x);
    node4* splay(node4* root, int key);
    void insert(int key);
    bool search(int key);
    void deleteKey(int key);
    void inorder(node4* node);
    void display();
};