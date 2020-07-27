#include <string>
#include <iostream>
#include <vector>
#include <map>

using std::map;
using std::vector;
using std::string;

typedef map<char, int> edges;
typedef vector<edges> trie;

trie build_trie(vector<string> & patterns) {
  trie t;
  //edges e;
  // write your code here
  for(int j=0;j<patterns.size();j++){
    //current NOde  = root;
    int currNI=0;
    for(int i=0;i<patterns[j].size();i++){
      char currS = patterns[j][i];
      if(t[currNI].find(currS)!=t[currNI].end()){
        currNI = t[currNI].find(currS)->second;
      }else{
        t.push_back(std::pair<char,int>(currS,t.size()));
        t[currNI].insert(std::pair<char,int>(currS,t.size()));
        currNI = t.size();
      }
    }
  }
  return t;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<string> patterns;
  for (size_t i = 0; i < n; i++) {
    string s;
    std::cin >> s;
    patterns.push_back(s);
  }

  trie t = build_trie(patterns);
    std::cout<<"print fault\n";
  for (size_t i = 0; i < t.size(); ++i) {
    for (const auto & j : t[i]) {
      std::cout << i << "->" << j.second << ":" << j.first << "\n";
    }
  }

  return 0;
}