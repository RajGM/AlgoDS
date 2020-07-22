#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using std::string;

int edit_distance(const string str1, const string str2) {
  //write your code here
  /*
  std::vector<char> st1;
  std::vector<char> st2;
  for(int i=0;i<str1.length();i++){
      st1[i]=str1[i];
  }
  
    for(int j=0;j<str2.length();j++){
      st2[j]=str2[j];
  }
  */
  //int strMat[str1.length()+1][str2.length()+1];
  std::vector<std::vector<int>> strMat(str1.length()+1,std::vector<int>(str2.length()+1,0));
  
  for(int i=0;i<=str1.length();i++){
    strMat[i][0] = i;
    //std::cout<<strMat[i][0]<<" ";
  }
    //std::cout<<"\n";
  for(int j=0;j<=str2.length();j++){
    strMat[0][j] = j;
    //std::cout<<strMat[0][j]<<" ";
  }
  //std::cout<<"\n";
    
  for(int i=1;i<=str1.length();i++){
      for(int j=1;j<=str2.length();j++){
             // std::cout<<"I:"<<i<<" J:"<<j<<"\n";
              int min1 = std::min(strMat[i][j-1]+1,strMat[i-1][j]+1);
              int min2;
             // std::cout<<"strMat[i][j-1]:"<<strMat[i][j-1]<<" strMat[i-1][j]:"<<strMat[i-1][j]<<"\n";
             // std::cout<<"Min1:"<<min1<<"\n";
              if(str1[i-1]==str2[j-1]){
               //   std::cout<<"Equal"<<"\n";
            //      std::cout<<"str1[i]"<<str1[i]<<" str2[j]"<<str2[j]<<"\n";
                  min2 = std::min(min1,strMat[i-1][j-1]);
              //    std::cout<<"Min2:"<<min2<<"\n";
              }
              else if(str1[i-1]!=str2[j-1]){
                //  std::cout<<"Not Equal"<<"\n";
                 // std::cout<<"str1[i]"<<str1[i-1]<<" str2[j]"<<str2[j-1]<<"\n";
                  min2 = std::min(min1,strMat[i-1][j-1]+1);
                  //std::cout<<"Min2:"<<min2<<"\n";
              }
              strMat[i][j] = min2;
              //std::cout<<"strMat[i][j]:"<<strMat[i][j]<<"\n";
          }
      }
    /*  
  for(int i=0;i<=str1.length();i++){
      for(int j=0;j<=str2.length();j++){
          std::cout<<strMat[i][j]<<" ";
      }
      std::cout<<"\n";
  }
  */
  
  int ans = strMat[str1.length()][str2.length()]; 
  return ans;
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
