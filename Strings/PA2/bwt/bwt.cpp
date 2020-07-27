#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

string BWT(const string& text) {
  string result = "";
  // write your code here
  vector<string> vecR;
  int i = text.size()-1;
  for(int k=0;k<text.size();k++){
      string tmpS;
      tmpS.resize(text.size());
      int pI=0;
      for(int z=i;z<text.size();z++){
        tmpS[pI]=text[z];
        pI++;
      }
      for(int j=0;j<i;j++){
        tmpS[pI]=text[j];
        pI++;
      }
      vecR.push_back(tmpS);
      i--;
  }
  
  std::sort(vecR.begin(),vecR.end());
  string finTr;
  finTr.resize(text.size());
  int counter=0;
  for(int i=0;i<vecR.size();i++){
      finTr[counter] = vecR[i][text.size()-1];
      counter++;
  }
  
  result = finTr;
  
  return result;
}

int main() {
  string text;
  cin >> text;
  cout << BWT(text) << endl;
  return 0;
}