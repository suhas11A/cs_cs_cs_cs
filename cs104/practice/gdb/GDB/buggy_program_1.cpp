/*
AUTHOR: KAVYA GUPTA
*/

#include<iostream>
#include<cmath>
#define ll long long
using namespace std;

/*
Purpose of the program is to print "Gray Code". What's that ? Google it!
This code is giving segmentation fault :(
Whyyyhhh ... please help T-T !

Input is a integer n, this program is supposed to print ALL n-characters gray code set.
bit_strings() function returns n-length gray code in arr[] string array.
Of course, there will be 2^n gray codes.
inverse() function simply inverts the array.

Hint : Program has 1 logical error, and may/may not have more errors :)
*/

void inverse(string arr[], int n)
{
    string* b = new string[n];
    for(ll int i=n-1; i>=0; i++)
        b[i]=arr[n-1-i];
    for(ll int i=0; i<n; i++)
        arr[i]=b[i];
    delete[] b;
}
void bit_strings(string arr[], int n)
{
    if(n==1) {arr[0]="0"; arr[1]="1"; return;}
    ll int num = pow(2, n-1);
    string* b = new string[num];
    bit_strings(b, n-1);
    for(ll int i=0; i<num; i++)
        arr[i]="0"+b[i];
    inverse(b, num);
    for(ll int i=0; i<num; i++)
        arr[i+num]="1"+b[i];
    delete[] b;
}
int main()
{
    int n; cin>>n;
    ll int num = pow(2, n);
    string* arr = new string[num];
    bit_strings(arr, n-1);
    for(ll int i=0; i<num; i++)
        cout<<arr[i]<<"\n";
    delete[] arr;
}
