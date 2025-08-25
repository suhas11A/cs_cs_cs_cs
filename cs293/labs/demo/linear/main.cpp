#include<iostream>
#include<fstream>
#include "common.h"
#include "linear.h"

// ************************************************************
// DO NOT CHANGE ANYTHING IN THIS FILE
// ************************************************************

int main(int argc, char *argv[]) {
  if (argc > 1) {
    freopen(argv[1], "r", stdin); // Redirect the standard input to a file
  }
  int element;
  std::cin >> element;
  unsigned size;
  std::cin >> size;
  int* S = new int[size];
  for( unsigned i=0; i < size; i++ ) {
    std::cin >> S[i];
  }
  int position = linear_search(S, size, element);
  std::cout << position << "\n";
  return 0;
}
