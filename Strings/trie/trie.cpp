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

trie build_trie(vector<string> &patterns) {
 //vector<vector<int>> vec{{0}};
 
 if (patterns.empty()) {
        return trie{};
    }
 trie t{edges{}}; 
 int root{0},cnt{0};
 
 for(auto& i:patterns){
     int currentN = root;
     for(auto j:i){
         if(t[currentN].find(j)!=t[currentN].end()){
             currentN = t[currentN][j];
         }else{
            t.emplace_back(edges{});
            t[currentN][j] = ++cnt;
            currentN = cnt;
         }
     }
 }
 
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
 
  for (size_t i = 0; i < t.size(); ++i) {
    for (const auto & j : t[i]) {
      std::cout << i << "->" << j.second << ":" << j.first << "\n";
    }
  }

  return 0;
}