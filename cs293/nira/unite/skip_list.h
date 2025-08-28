#include<vector>
class node0{
private:
    float p=0.5;
    int random_no_of_levels(float prob,int max_no_of_levels);
public:
    int key;
    int max_levels;
    bool inter;
    int no_levels;
    std::vector<node0*> level_tower;
    node0(int key, int max_levels,bool inter);
};
class skip_list{
public:
    int max_lev;
    node0* NIL;
    node0* header;
    skip_list(int max_lev);
    void insert(int key);
    void delete_key(int key);
    bool search(int val);
    // void print_list();
};

