#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    std::string bwt;
    cin>>bwt;
    string bwtSorted;
    bwtSorted.resize(bwt.size());
    std::map<char,int> oriCouM;
    
    for(int i=0;i<bwt.size();i++){
        if(oriCouM.find(bwt[i])==oriCouM.end()){
            oriCouM.insert(std::pair<char,int>(bwt[i],1));
        }else{
            oriCouM.at(bwt[i])=oriCouM.find(bwt[i])->second+1;
        }
    }
    

    std::cout << "mymap contains:\n";
    std::map<char,int>::iterator it = oriCouM.begin();
  for (it=oriCouM.begin(); it!=oriCouM.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

    
    for(int i=0;i<bwt.size();i++){
        char tmpC = bwt[i];
        std::cout<<"tmpC:"<<tmpC<<"\n";
        int posC = oriCouM.find(tmpC)->second;
        std::cout<<"posC:"<<posC<<"\n";
        bwtSorted[posC]=tmpC;
        std::cout<<"bwtSorted[posC]:"<<bwtSorted[posC]<<"\n";
        oriCouM.at(tmpC)=posC-1;
    }

    std::cout<<bwtSorted<<"\n";

    
    std::cout << "mymap contains:\n";
   // std::map<char,int>::iterator it = oriCouM.begin();
  for (it=oriCouM.begin(); it!=oriCouM.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

    
    return 0;
}

