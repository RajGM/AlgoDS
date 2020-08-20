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
    if(bwt.size()<=1){
        return bwt;
    }
    
    
  string text = "";
  string tmpB = bwt;
  std::sort(tmpB.begin(),tmpB.end());
  vector<string> tmpSV;
  vector<string> tmpSV2;
  //tmpSV.resize(bwt.size());
  for(int i=0;i<bwt.size();i++){
    string tmpString;
    tmpString.resize(2);
    tmpString[0]=bwt[i];
    tmpString[1]=tmpB[i];
    tmpSV.push_back(tmpString);
   }
    std::sort(tmpSV.begin(),tmpSV.end()); 
   
  if(bwt.size()>2){
      for(int i=0;i<bwt.size()-2;i++){
          for(int j=0;j<bwt.size();j++){
            string tmpS;
            tmpS.resize(1);
            tmpS[0]=bwt[j];
            tmpS.append(tmpSV[j]);
            tmpSV[j]=tmpS;
          }
          std::sort(tmpSV.begin(),tmpSV.end());
      }
  }
  
  std::sort(tmpSV.begin(),tmpSV.end());
  
  
  //which position to return
  string finalans=tmpSV[0];
  text.resize(bwt.size());
  for(int i=0;i<bwt.size()-1;i++){
      text[i]=finalans[i+1];
  }
  text[text.size()-1]='$';
  return text;
}

int main() {
  string bwt;
  cin >> bwt;
  cout << InverseBWT(bwt) << endl;
  return 0;
}