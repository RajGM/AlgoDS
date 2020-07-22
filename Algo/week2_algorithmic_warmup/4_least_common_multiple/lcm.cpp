#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long int gcd_pro(long long int a,long long int b){
  long long int rem=b;
  while(rem!=0){
      rem=a%b;
      a=b;
      b=rem;
  }
  return (long long)a;
}

long long int lcm_pro(long long int a,long long int b){
  int gcd = gcd_pro(a,b);
  long long int lcm = (a*b)/gcd;
  return lcm;
}

int main() {
  long long int a, b;
  //a = 714552;
  //b = 374513;
  std::cin >> a >> b;
  //std::cout << lcm_naive(a, b) << std::endl;
  std::cout << lcm_pro(a,b) << std::endl;
  return 0;
}
