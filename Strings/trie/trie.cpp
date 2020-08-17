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

trie build_trie(vector<string> &patterns) {
 //vector<vector<int>> vec{{0}};
 trie t;
 edges mapT;
 mapT.insert(0,(int)mapT.size());
 t[0].insert(mapT);
 /*
 for(int i=0;i<patterns.size();i++){
     //int currNode = root;
     for(int j=0;j<patterns[i].size();j++){
       char currS = patterns[i][j];
       if()
     }
 }
 */
 
 return t;
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

  trie t = build_trie(patterns);
 /*
  for (size_t i = 0; i < t.size(); ++i) {
    for (const auto & j : t[i]) {
      std::cout << i << "->" << j.second << ":" << j.first << "\n";
    }
  }
*/
  return 0;
}