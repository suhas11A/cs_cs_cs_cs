#include<iostream>
using namespace std;

class node{
public:
    node* next=nullptr;
    int value;
    node(int e){
        value=e;
    }
};

class queue{
public:
    node* tail;

    queue(){
        tail=new node(-1); // do i need this?? U do
        tail->next=tail;
    }
    void enqueue(int e){
        if(tail->value==-1){
            tail->value=e;
        }
        else{
            node* added_node=new node(e);
            added_node->next=tail->next;
            tail->next=added_node;
            tail=added_node;
        }
    }
    void dequeue(){
        if(tail->next==tail){
            if(tail->value!=-1){
                tail->value=-1;
                return;
            }
            else if(tail->value==-1){
                return;
            }
        }
        node* second=tail->next->next;
        free(tail->next);
        tail->next=second;
    }
    int front(){
        if(tail->next->value==-1){
            cout<<"queue empty"<<endl;
        }
        return tail->next->value;
    }
};

int main(){
    queue q;
    cout<<q.front()<<endl;
    q.enqueue(4);
    cout<<q.front()<<endl;
    q.enqueue(8);
    cout<<q.front()<<endl;
    q.enqueue(7);
    cout<<q.front()<<endl;
    q.enqueue(6);
    cout<<q.front()<<endl;
    cout<<q.tail->value<<endl;
    q.dequeue();
    cout<<q.front()<<endl;
    q.dequeue();
    cout<<q.front()<<endl;
    q.dequeue();
    cout<<q.front()<<endl;
    q.dequeue();
    cout<<q.front()<<endl;
    q.enqueue(6);
    cout<<q.front()<<endl;

}