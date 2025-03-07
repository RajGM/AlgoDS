#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

bool IsBinarySearchTree(const vector<Node>& tree) {
  // Implement correct algorithm here
  return true;
}

int main() {
  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  int tTraversed=0;
  for(int i=0;i<nodes;i++){
      int key;
      int lkey=-1;
      int rkey=-1;
      key = tree[i].key;
      if(tree[i].left!=-1){
          lkey=tree[tree[i].left].key;
      } 
      if(tree[i].right!=-1){
          rkey=tree[tree[i].right].key;
      }
      
      if(lkey!=-1){
        if(lkey>key)
            break;
      }
      if(rkey!=-1){
        if(rkey<key)
            break;
      }
      
      tTraversed++;
  }
  
  if(tTraversed==nodes){
      std::cout<<"CORRECT"<<"\n";
  }else{
      std::cout<<"INCORRECT"<<"\n";
  }
  
  return 0;
}
