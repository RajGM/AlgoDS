#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

string InverseBWT(const string& bwt) {
  string text = "";
  text.resize(bwt.size());
  vector<string> twoV(bwt.size(),"00");
  string tmpOri = bwt;
  string tmpNew = bwt;
  std::sort(tmpNew.begin(),tmpNew.end());
  std::map<char,int> charVo;
  std::map<char,int> charVn;
  vector<int> oldCount(bwt.size(),0);
  vector<int> newCount(bwt.size(),0);

  charVo.insert(std::pair<char,int>('A',0));
  charVo.insert(std::pair<char,int>('C',0));
  charVo.insert(std::pair<char,int>('G',0));
  charVo.insert(std::pair<char,int>('T',0));
  charVo.insert(std::pair<char,int>('$',0));
  
  charVn.insert(std::pair<char,int>('A',0));
  charVn.insert(std::pair<char,int>('C',0));
  charVn.insert(std::pair<char,int>('G',0));
  charVn.insert(std::pair<char,int>('T',0));
  charVn.insert(std::pair<char,int>('$',0));
  
  for(int i=0;i<bwt.size();i++){
    twoV[i][0] = tmpNew[i];
    twoV[i][1] = tmpOri[i];

    newCount[i] = charVn.find(twoV[i][0])->second;
    charVn[twoV[i][0]] = charVn.find(twoV[i][0])->second+1;
  
    oldCount[i] = charVo.find(twoV[i][1])->second;
    charVo[twoV[i][1]] = charVo.find(twoV[i][1])->second+1;
  }
 
   for(int i=0;i<bwt.size();i++){
        
    }
  
  return text;
}

int main() {
  string bwt;
  cin >> bwt;
  cout << InverseBWT(bwt) << endl;
  return 0;
}
