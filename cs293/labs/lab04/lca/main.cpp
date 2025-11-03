#include <bits/stdc++.h>
#include "tree.h"

using namespace std;

// ************************************************************
// DO NOT CHANGE ANYTHING IN THIS FILE

vector<string> parse;

void split (string str, char seperator) {
    parse.clear();
    unsigned i = 0;
    int startIndex = 0, endIndex = 0;
    while ( i <= str.length() ) {
      if (str[i] == seperator || i == str.length()) {
        endIndex = i;
        parse.push_back(str.substr(startIndex,endIndex-startIndex));
        startIndex = endIndex + 1;
      }
      i++;
    }
}

int main(int argc, char **argv) {
  // a map from keys to pointer of their nodes
  unordered_map<int, TreeNode*> key_to_pointer; 

  char which = '1';
  if( argc >= 2 ) {
    if( argv[1][0] == '0' ) {
      cout << "Entering in the interactive mode:\n";
      which = '0';
    }else if (freopen(argv[1], "r", stdin) == nullptr) {
      std::cerr << "Error: Could not open input file " << argv[1] << std::endl;
      cout<<"Give mode of operation:\n 0 for interactive testing \n"
        "<file> for feeding testcases via file \n"
        " no options for testing findlca \n" << endl;
      return 1;
    }
  }


  if (which == '1') {
    // Read entire input from stdin: tree values first, then two keys at the end
    std::vector<int> all;
    int val;
    while (std::cin >> val) all.push_back(val);
  
    if (all.size() < 3) {
      std::cerr << "Input must contain at least one tree value followed by two keys.\n";
      return 1;
    }
  
    // Last two ints are the keys
    int k2 = all.back(); all.pop_back();
    int k1 = all.back(); all.pop_back();
  
    // Write tree part to a temporary file because TREE::load expects a filename
    std::string tmp_tree = "stdin_tree.tmp";
    std::ofstream fout(tmp_tree);
    if (!fout) {
      std::cerr << "Cannot write temporary tree file: " << tmp_tree << '\n';
      return 1;
    }
    for (int x : all) fout << x << '\n';
    fout.close();
  
    // Load tree and find LCA
    TREE *b = new TREE();
    key_to_pointer.clear();
    b->load(LOAD_FULL_TREE, tmp_tree, key_to_pointer);
  
    // clean up temporary file
    std::remove(tmp_tree.c_str());
  
    TreeNode* x = nullptr;
    if (key_to_pointer.find(k1) != key_to_pointer.end()) x = key_to_pointer.at(k1);
    TreeNode* y = nullptr;
    if (key_to_pointer.find(k2) != key_to_pointer.end()) y = key_to_pointer.at(k2);
  
    if (TreeNode* ret = b->findlca(x, y)) {
      std::cout << "LCA is: " << ret->key << std::endl;
    } else {
      std::cout << "LCA doesn't exist" << std::endl;
    }
  
    delete b;
  }
  else if( which == '0') {
    TREE *b = new TREE();
    string s;
    while(true){
      cout<<">>>";
      getline(cin,s);
      split(s,' ');

      if(parse[0]=="LOAD"){
        auto fname = parse[1];
        b = new TREE();
        cout <<"Loading: "<< fname << endl;
        key_to_pointer.clear();
        b->load(LOAD_FULL_TREE, fname, key_to_pointer);
        cout << key_to_pointer.size() << " nodes loaded" << endl;
      }else if(parse[0]=="FINDLCA"){
        int k1 = stoi(parse[1]);
        int k2 = stoi(parse[2]);
        TreeNode* x = nullptr;
        if(key_to_pointer.find(k1) != key_to_pointer.end()){
          x = key_to_pointer.at(k1);
        }
        TreeNode* y = nullptr;
        if(key_to_pointer.find(k2) != key_to_pointer.end()){
          y = key_to_pointer.at(k2);
        }
        if(TreeNode* ret = b->findlca(x, y)){
          cout << "LCA is: " << ret->key << endl;
        }else{
          cout << "LCA doesn't exist" << endl;
        }
      }else if(parse[0]=="PRINT"){
        b->printTREE("");
      }else if(parse[0]=="QUIT"){
        break;
      }else{
        cout<<parse[0] << " is an INVALID REQUEST"<<endl;
      }
    }
  }else {
    cout << "INVALID MODE!";
  }
  return 0;
}
