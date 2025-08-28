#include<iostream>
#include<cstdlib>
#include<vector>
#include "skip_list.h"
using namespace std;

int node0::random_no_of_levels(float prob,int max_no_of_levels){
    int levels=1;
    while((float)rand()/RAND_MAX<prob && levels<max_no_of_levels){
        levels++;
    }
    return levels;
}

node0::node0(int key, int max_levels,bool inter){
    this->key=key;
    this->max_levels=max_levels;
    this->inter=inter;
    if(inter==true){
        this->no_levels=random_no_of_levels(p,max_levels);
    }
    else{
        this->no_levels=max_levels;
    }
    level_tower.resize(max_levels, nullptr);
}

skip_list::skip_list(int max_lev){
    this->max_lev=max_lev;
    NIL=new node0(2000000,max_lev,false);
    header=new node0(-1,max_lev,false);
    for (int i=0;i<max_lev;i++){
        header->level_tower[i]=NIL;
    }
}

void skip_list::insert(int key){
    node0* new_node=new node0(key,max_lev,true);
    vector<node0*> update;
    update.resize(max_lev,nullptr);
    node0* now_in=header;
    for(int i=max_lev-1;i>-1;i--){
        while(now_in->level_tower[i] && now_in->level_tower[i]->key<key){
            now_in=now_in->level_tower[i];
        }
        update[i]=now_in;
    }
    for (int i=0;i<new_node->no_levels;i++){
        new_node->level_tower[i]=update[i]->level_tower[i];
        update[i]->level_tower[i]=new_node;
    }
}

void skip_list::delete_key(int key){
    vector<node0*> update;
    update.resize(max_lev,nullptr);
    node0* now_in=header;
    for(int i=max_lev-1;i>-1;i--){
        while(now_in->level_tower[i] && now_in->level_tower[i]->key<key){
            now_in=now_in->level_tower[i];
        }
        update[i]=now_in;
    }
    node0* target=now_in->level_tower[0];
    if (target && target!=NIL && target->key==key){
        for(int i=0;i<target->no_levels;i++){
            if(update[i]->level_tower[i]==target){
                update[i]->level_tower[i]=target->level_tower[i];
            }
        }
        // cout<<"deleted"<<endl;
    }
    else{
        // cout<<"nope"<<endl;
    }
}

bool skip_list::search(int val){
    int i=max_lev-1;
    node0* now_in=header;
    while (i>-1)
    {
        while (now_in->level_tower[i]->key<val){
            now_in=now_in->level_tower[i];
        }
        if(now_in->level_tower[i]->key==val){
            return true;
        }
        i=i-1;
    }
    return false;  
}
// void skip_list::print_list() {
//     for (int i = max_lev - 1; i >= 0; i--) {
//         cout << "Level " << i + 1 << ": ";
//         node0* curr = header->level_tower[i];
//         while (curr != NIL) {
//             cout << curr->key << " -> ";
//             curr = curr->level_tower[i];
//         }
//         cout << "NIL" << endl;
//     }
// }



