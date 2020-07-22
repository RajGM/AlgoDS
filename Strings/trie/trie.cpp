#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <utility>      
#include <algorithm>

using std::map;
using std::vector;
using std::string;

typedef map<char, int> edges;
typedef vector<edges> trie;

struct lea{
  char nodeChar = '!';
  bool isEnd = false;
  vector<lea> neiAll;
  //neiAll.resize(0);
  int neiSize = neiAll.size();
  map<char,int> edgesI;
};

trie build_trie(vector<string> & patterns) {
 //lea leavesTree;
 vector<lea> leavesVector;
 //leavesVector.resize(patterns.size());
 leavesVector.resize(0);
 map<char,int> mapRoot;
 std::map<char,int>::iterator it;
 for(int i=0;i<patterns.size();i++){
     for(int j=0;j<patterns[i].size();j++){
         it = mapRoot.find(patterns[i][j]);
         if(it==mapRoot.end() && j==0){
                mapRoot.insert(std::pair<char,int>(patterns[i][j],leavesVector.size()));
                leavesVector[leavesVector.size()].nodeChar = patterns[i][j];
            }else{
                //recursion until last or found
                int levelI=1;
                while(leavesVector[it].edgesI.find(patterns[i][j])!=edgesI.end()){
                    
                }
            }
            
     }
 }
 
}

int main() {
  size_t n;
  std::cin >> n;
  vector<string> patterns;
  for (size_t i = 0; i < n; i++){
    string s;
    std::cin >> s;
    patterns.push_back(s);
  }

  /*
  
  trie t = build_trie(patterns);
  for (size_t i = 0; i < t.size(); ++i) {
    for (const auto & j : t[i]) {
      std::cout << i << "->" << j.second << ":" << j.first << "\n";
    }
  }

  
  */
  
  
  return 0;
}