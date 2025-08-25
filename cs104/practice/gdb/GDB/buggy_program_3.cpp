/*
AUTHOR: KAVYA GUPTA
*/

#include<iostream>
using namespace std;

/*
Welcome to the Weird Algorithm !
When n is even, divide by 2 and when odd, do 3n+1 !
Magically, it ALWAYS returns to 1 !
How !?
No one knows... yet.

This is a very simple looking program... but still the autograder deemed it wrong...
What could possibly go wrong in this !?
*/

int main()
{
    unsigned int n; cin>>n;
    cout<<n<<"\n";
    while(n!=1)
    {
        if(n&1) n = 3*n+1;
        else n = n>>1;
        cout<<n<<"\n";
    }
}