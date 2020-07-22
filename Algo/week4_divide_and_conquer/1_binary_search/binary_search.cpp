#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int binary_search(const vector<int> &a, int x,int low,int high) {
  int left = 0, right = (int)a.size(); 
  //write your code here
  /*
  if(high<low)
    return -1;
  int midpoint = low + (high-low)/2;
  if(x == a[midpoint])
    return midpoint;
  else if(x<a[midpoint])
    return binary_search(a,x,low,midpoint-1);
  else
    return binary_search(a,x,midpoint+1,high);
*/

  while(low<=high){
    int midpoint = low +(high-low)/2;
    if(x == a[midpoint])
      return midpoint;
    else if(x<a[midpoint]){
      high = midpoint-1;
    }else{
      low = midpoint+1;
    }
  }
  return -1;
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  /*
  std::cout<<"Linear Search"<<"\n";
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << linear_search(a, b[i]) << ' ';
  }
 
  std::cout<<"\n";
  
    std::cout<<"Binary Search"<<"\n";
 */
    for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search(a, b[i],0,n-1) << ' ';
  }
}
