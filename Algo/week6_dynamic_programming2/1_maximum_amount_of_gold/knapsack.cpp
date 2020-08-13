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

/*
int opti_w(int w,const vector<int> &wA){
    int len = wA.size();
    std::vector<std::vector<int>> strMat(w+1,std::vector<int>(wA.size()+1,0));
   for(int i=1;i<w;i++){
       for(int j=1;j<len;j++){
           strMat[j][i] = strMat[j][i-1];
           if(wA[i]<=w){
               int val = strMat[j-wA[i]][i-1];
               if(strMat[j][i]<val){
                    strMat[j][i] = val;
               }
           }
       }
   }
   
    return strMat[w][len];
}
*/

int opti_w(int W,const std::vector<int> &w,int n){
    std::vector<std::vector<int>> value(w.size());
    for(int i=0;i<value.size();i++){
        value[i] = vector<int>(w.size());
        for(int j=0;j<value.size();j++){
            if(j==0 || i ==0){
            value[i][j] = 0;
            }
        }
    }
    
    for(int i=1;i<n;i++){
        for(int j=1;j<w.size();j++){
            value[j][i]=value[j][i-1];
            if(w[i]<=j){
                int val = value[j-w[i]][i-1]; +w[i];
                if(value[j][i]<val){
                    value[j][i]=val;
                }
            }
        }
    }
    
    
    return value[w.size()-1][w.size()-1];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout<<opti_w(W, w, n);
  //std::cout << o_w(W, w) << '\n';
}
