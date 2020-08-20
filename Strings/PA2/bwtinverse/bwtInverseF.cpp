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

string InverseBWT(string &bwt){
    string text ="";
    string sortedS = bwt;
    std::sort(sortedS.begin(),sortedS.end());
    
    std::map<char,int> oriPosM;
    std::map<char,int> oriCouM;
    std::map<char,int> sorPosM;
    std::map<char,int> sorCouM;
    
    for(int i=0;i<bwt.size();i++){
        if(oriCouM.find(bwt[i])==oriCouM.end()){
            oriCouM.insert(std::pair<char,int>(bwt[i],1));
            oriPosM.insert(std::pair<char,int>(bwt[i]+1,1));
        }else{
            oriCouM.at(bwt[i])=oriCouM.find(bwt[i])->second+1;
            oriPosM.insert(std::pair<char,int>(bwt[i]+oriCouM.find(bwt[i])->second,i));
        }
        
        if(sorCouM.find(bwt[i])==sorCouM.end()){
            sorCouM.insert(std::pair<char,int>(bwt[i],1));
            sorPosM.insert(std::pair<char,int>(bwt[i]+1,1));
        }else{
            sorCouM.at(bwt[i])=sorCouM.find(bwt[i])->second+1;
            sorPosM.insert(std::pair<char,int>(bwt[i]+sorCouM.find(bwt[i])->second,i));
        }
        
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