#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <map>


using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
using std::string;
using std::vector;

vector<int> BuildSuffixArray(const string& text) {
  vector<int> result;
  std::map<string,int> mymap;
  vector<string> suffStrings(text.size());
  
  for(int i=0;i<text.size();i++){
    string tmpS;
    tmpS.resize(text.size()-i);
    for(int j=i,index=0;j<text.size();j++,index++){
      tmpS[index] = text[j];
    }
    suffStrings[i]=tmpS;
    mymap.insert ( std::pair<string,int>(tmpS,i) );
  }
  
  std::sort(suffStrings.begin(),suffStrings.end());
  for(int i=0;i<text.size();i++){
    string tmpS = suffStrings[i];
    result.push_back(mymap.find(tmpS)->second);
  }
  
  
  return result;
}

int main() {
  string text;
  cin >> text;
  vector<int> suffix_array = BuildSuffixArray(text);
  for (int i = 0; i < suffix_array.size(); ++i) {
    cout << suffix_array[i] << ' ';
  }
  cout << endl;
  return 0;
}
