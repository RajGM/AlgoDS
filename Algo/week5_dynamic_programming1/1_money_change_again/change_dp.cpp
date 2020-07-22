#include <iostream>
#include <algorithm>    // std::min

int get_change(int m) {
  //write your code here
  int changeArr[m+1]={0};
  changeArr[0]=0;
  int coinsCount = 0;
  int q1,q3,q4,r1,r3,r4;
  for(int i=1;i<=m;i++){
      q1 = i/1;
      q3 = i/3;
      q4 = i/4;
      r1 = i%1;
      r3 = i%3;
      r4 = i%4;
      if(r3 == 0 && r4 == 0){
        changeArr[i] = q4;
      }
      else if(r3 == 0 && r4 != 0){
         if(i>4){
          int preV = changeArr[i-1];
          preV++;
          
          int r3M4 = changeArr[i-3];
          //if(changeArr[r3M4+3] == i)
            r3M4++;
          int r4M3 = changeArr[i-4];
          //if(changeArr[r4M3+4] == i)
            r4M3++;
         
          int min = std::min(r3M4,r4M3);
          int min2 = std::min(min,preV);
          changeArr[i] = min2;
          }
          else{
          int preV = changeArr[i-1];
          int min3rPrevV = std::min(preV+1,q3);
          changeArr[i] = min3rPrevV;
          }
      }
      else if(r3 != 0 && r4 == 0){
         if(i>4){
          int preV = changeArr[i-1];
          preV++;
          
          int r3M4 = changeArr[i-3];
          //if(changeArr[r3M4+3] == i)
            r3M4++;
          int r4M3 = changeArr[i-4];
          //if(changeArr[r4M3+4] == i)
            r4M3++;
         
          int min = std::min(r3M4,r4M3);
          int min2 = std::min(min,preV);
          changeArr[i] = min2;
          }
          else{
          int preV = changeArr[i-1];
          int min5rPrevV = std::min(preV+1,q4);
          changeArr[i] = min5rPrevV;
          }
      }
      else if(r3 != 0 && r4 != 0){
          if(i>4){
          int preV = changeArr[i-1];
          preV++;
          
          int r3M4 = changeArr[i-3];
          //if(changeArr[r3M4+3] == i)
            r3M4++;
          int r4M3 = changeArr[i-4];
          //if(changeArr[r4M3+4] == i)
            r4M3++;
         
          int min = std::min(r3M4,r4M3);
          int min2 = std::min(min,preV);
          changeArr[i] = min2;
          }
          else{
              int preV = changeArr[i-1];
              preV++;
              changeArr[i]=preV;
          }
      }
      //std::cout<<"I:"<<i<<" changeCount:"<<changeArr[i]<<"\n";
  }
  return changeArr[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}