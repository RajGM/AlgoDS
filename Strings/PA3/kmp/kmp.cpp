#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;

vector<int> find_pattern(const string& pattern, const string& text) {
  vector<int> result;
  if(pattern.size()>text.size())
    return result;
    /*
  char firstC = pattern[0];
  vector<int> fcLoc;
  for(int i=0;i<text.size();i++){
    if(firstC == text[i]){
        fcLoc.push_back(i);      
    }  
  }
    
    int k=0;
    for(int i=0;i<text.size();i++){
        i=fcLoc[k];
        k++;
        
      int j=0;
      int count=0;
      while(i+j<text.size() && pattern[j]==text[i+j]){
        count++;
        if(count == pattern.size()){
          result.push_back(i);
        }
        j++;
      }
        
    }
*/
    
  for(int i=0;i<text.size();i++){
    if(pattern[0]==text[i]){
      int j=0;
      int count=0;
      while(i+j<text.size() && pattern[j]==text[i+j]){
        count++;
        if(count == pattern.size()){
          result.push_back(i);
        }
        j++;
      }
    }
  }
  
  return result;
}

int main() {
  string pattern, text;
  cin >> pattern;
  cin >> text;
  vector<int> result = find_pattern(pattern, text);
  for (int i = 0; i < result.size(); ++i) {
    printf("%d ", result[i]);
  }
  printf("\n");
  return 0;
}