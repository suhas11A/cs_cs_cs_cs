#include <iostream>
#include<vector>
#include <ctime>
#include <chrono>
#include <cstdlib>
#include "binary_search_tree.h"
#include "rb_tree.h"

using namespace std;
using namespace std::chrono;
int main() {
    srand(time(0)); 
    int n,m;
    cin>>n>>m;
    long double bin_time[m]={};
    long double rb_tree_time[m]={};
    for(int j=0;j<m;j++){
        vector<int> input(n);
        for(int i=0;i<n;i++){
            input[i]=rand()%n+1;
        }

        auto bst_start = high_resolution_clock::now();
        binary_search_tree b;
        for(int i=0;i<(n/2);i++){
            b.insert(input[i]);
        }
        for(int i=(n/2);i<n;i++){
            if(b.search(input[i])){
                b.delete_node(input[i]);
            }
        }
        auto bst_stop = high_resolution_clock::now();
        bin_time[j] = duration_cast<nanoseconds>(bst_stop - bst_start).count();

        auto rbt_start = high_resolution_clock::now();
        rb_tree r;
        for(int i=0;i<(n/2);i++){
            r.insert(input[i]);
        }
        for(int i=(n/2);i<n;i++){
            if(r.search_key(input[i])){
                r.delete_key(input[i]);
            }
        }
        auto rbt_stop = high_resolution_clock::now();
        rb_tree_time[j] = duration_cast<nanoseconds>(rbt_stop - rbt_start).count();

        
    }
    long double bin_total=0;
    long double skip_total=0;
    long double avl_total=0;
    long double rb_total=0;
    long double splay_total=0;
    for(int i=0;i<m;i++){
        bin_total+=bin_time[i];
        rb_total+=rb_tree_time[i];
    }
    cout<<"binary search tree "<<bin_total/m<<endl;
    cout<<"red-black tree "<<rb_total/m<<endl;
}
