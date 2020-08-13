#include <iostream>
#include<vector>
#include<string>
#include<map>
#include<stack>
using namespace std;

string computeInfo(vector<string> dataSet){
    string res="";
    int continuousM=0;
    std::map<string,int> mymap;
    for(int i=0;i<dataSet.size();i++){
        for(int j=0,k=0;j<dataSet.size();j++){
            while(k<dataSet[j].size()){
                if(dataSet[i][k]==dataSet[j][k]){
                    continuousM++;
                }else{
                    continuousM=0;
                }
            }
            
        }
    }
    
    
    
    return res;
} 

int main()
{
    cout<<"Hello World"<<endl;
    vector<string> dataSet(1618);
    for(int i=0;i<1618;i++){
        cin>>dataSet[i];
    }
        
   // computeInfo(dataSet);

    return 0;
}