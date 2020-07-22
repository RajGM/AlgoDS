#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;

int optimal_weight(int W, const vector<int> &w) {
  //write your code here
  int current_weight = 0;
  for (size_t i = 0; i < w.size(); ++i) {
    if (current_weight + w[i] <= W) {
      current_weight += w[i];
    }
  }
  return current_weight;
}

int o_w(int W, const vector<int> &w) {
  vector<int> c(W+1);
  for (size_t i = 0; i < w.size(); ++i) {
	  for(int j = W; j - w[i] >= 0; --j) {
			c[j] = std::max(c[j], c[j - w[i]] + w[i]);
	  }
  }
  return c[W];
}

int opti_w(int w,const vector<int> &wA){
    int len = wA.size();
    //std::reverse(wA.begin(),wA.begin()+len);
    std::vector<std::vector<int>> strMat(w+1,std::vector<int>(wA.size()+1,0));
   for(int i=1;i<=w;i++){
       for(int j=1;j<=len;j++){
           strMat[j][i] = strMat[j][i-1];
           std::cout<<"Working point1"<<"\n";
           if(wA[i]<=w){
               std::cout<<"Working point2"<<"\n";
               std::cout<<"J:"<<j<<" I:"<<i<<" wA[i]:"<<wA[i]<<"\n";
               int val = strMat[j-wA[i]][i-1];
               std::cout<<"Working point3"<<"\n";
               if(strMat[j][i]<val){
                std::cout<<"Working point4"<<"\n";
                    strMat[j][i] = val;
               std::cout<<"Working point5"<<"\n";
               }
           }
       }
   }
   
    return strMat[w][len];
}


int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  //opti_w(W, w);
  std::cout << o_w(W, w) << '\n';
}
