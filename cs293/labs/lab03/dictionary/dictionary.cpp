#include "dictionary.h"

//Implement dictionary here

Dictionary::Dictionary(){
    N = DICT_SIZE;
    A = new Entry[N];
    for (int i = 0; i < N; i++) {
        A[i].marker = '\0';
    }
};

Dictionary::~Dictionary(){
    delete[] A;
}

int Dictionary::hashValue(char key[]){
    int hashValue = 0;
    int i=0;
    int p = 31;
    double alpha = 0.6180339887;
    int currp = 1;
    while(key[i] != '\0') {
        hashValue += key[i]*currp;
        currp *= p;
        i++;
    }
    int ans = int(N*(hashValue*alpha))%N;
    return int(ans);
}

int Dictionary::findFreeIndex(char key[]){
    int i = hashValue(key);
    int j = i;
    int first_tomb = -1;
    do {
        if (A[i].marker == '\0') {
            return (first_tomb != -1) ? first_tomb : i;
        }
        if (A[i].marker == 'p') {
            if (strcmp(A[i].key, key) == 0) {
                return i;
            }
        } else {
            if (first_tomb == -1) first_tomb = i;
        }
        i = (i + 1) % N;
    } while (i != j);
    if (first_tomb != -1) return first_tomb;
    return -1;
}

struct Entry* Dictionary::get(char key[]){
    int i=hashValue(key); int j=i;
    if (A[i].marker=='\0') return NULL;
    do {
        if (A[i].marker=='p' && strcmp(A[i].key, key)==0) return A+i;
        i = (i+1)%N;
    } while (i!=j && A[i].marker!='\0');
    return NULL;
}

bool Dictionary::put(Entry e) {
    int i=findFreeIndex(e.key);
    if (i==-1) return false;
    delete[] A[i].key;
    A[i].key = new char[strlen(e.key)];
    strcpy(A[i].key,e.key);
    A[i].value = e.value;
    A[i].marker = 'p';
    return true;
}

bool Dictionary::remove(char key[]){
    int i=hashValue(key); int j=i;
    if (A[i].marker=='\0') return false;
    do {
        if (A[i].marker=='p' && strcmp(A[i].key, key)==0) {            
            A[i].value = 0;
            A[i].marker = 'b';
            return true;
        }
        i = (i+1)%N;
    } while (i!=j && A[i].marker!='\0');
    return false;
}