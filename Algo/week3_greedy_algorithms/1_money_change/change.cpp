#include <iostream>

int get_change(int m) {
  //write your code here
  int n=0;
  return n;
}

int change_pro(int m) {
  //write your code here
  int coins=0;
  int rem=0;
  while(m!=0){
      if(m%10==0){
          m = m-10;
          coins++;
      }else if(m%5==0){
          m = m-5;
          coins++;
      }else if(m>=1){
          m = m-1;
          coins++;
      }
  }
  return coins;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << change_pro(m) << '\n';
}
