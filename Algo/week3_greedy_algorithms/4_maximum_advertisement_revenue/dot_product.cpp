#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

long long max_dot_product(vector<long long> a, vector<long long> b) {
  // write your code here
  long long result = 0;
  /*
  for (size_t i = 0; i < a.size(); i++) {
    result += ((long long) a[i]) * b[i];
  }*/
  std::sort(a.begin(),a.begin()+a.size());
  std::sort(b.begin(),b.begin()+b.size());
  vector<long long> c;
  c.resize(a.size());
  for(int i=0;i<a.size();i++){
      c[i]=a[i]*b[i];
  }
  for(int i=0;i<c.size();i++){
      result = result + c[i];
  }
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<long long> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
}
