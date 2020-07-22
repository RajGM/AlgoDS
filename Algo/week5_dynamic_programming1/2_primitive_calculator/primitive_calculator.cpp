#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}


void reverSeq(vector<int> seq,int n){
    vector<int> ans;
    
    for(int i=n;n>=1;n--){
        if(n%2!=0 && n%3==0){
            int iMinus1 = seq[n-1];
            int iDiv3 = seq[n/3];
            if(iMinus1>=iDiv3){
                ans.push_back(n);
                n = n/3;
            }else{
                ans.push_back(n);
                n = n-1;
            }
        }
        else if(n%2==0 && n!=0){
            int iMinus1 = seq[n-1];
            int iDiv2 = seq[n/2];
            if(iMinus1>=iDiv2){
                ans.push_back(n);
                n = n/2;
            }else{
                ans.push_back(n);
                n = n-1;
            }
        }else if(n%2==0 && n%3==0){
            int iMinus1 = seq[n-1];
            int iDiv2 = seq[n/2];
            int iDiv3 = seq[n/3];
            if(iDiv3<= iDiv2 && iDiv3<=iMinus1){
                ans.push_back(n);
                n = n/3;
            }
            else if(iDiv2<=iDiv3 && iDiv2<=iMinus1){
                ans.push_back(n);
                n = n/2;
            }
            else if(iMinus1<=iDiv3 && iMinus1<=iDiv2){
                ans.push_back(n);
                n = n-1;
            }
        }else{
            int iMinus1 = seq[n-1];
            ans.push_back(n);
            n = n-1;
        }
        n++;
        }
    
    std::reverse(ans.begin(),ans.end());
    
    for(int i=0;i<ans.size();i++){
        std::cout<<ans[i]<<" ";
    }
    
}

vector<int> opt_seq(int n){
    vector<int> seq(n+1);
    seq[0]=0;
    seq[1]=0;
    seq[2]=1;
    seq[3]=1;
    
    for(int i=4;i<=n;i++){
        if(i%3==0 && i%2!=0){
            int iMinus1 = seq[i-1];
            int iDiv3 = seq[i/3];
            int minR = std::min(iMinus1,iDiv3);
            //std::cout<<"I div by 3"<<"\n";
            //std::cout<<"I:"<<i<<" iMinus1:"<<iMinus1<<" iDiv3:"<<iDiv3<<" minR:"<<minR<<"\n";
            minR++;
            seq[i]=minR;
        }
        else if(i%2==0 && i%3!=0){
            int iMinus1 = seq[i-1];
            int iDiv2 = seq[i/2];
            int min=std::min(iMinus1,iDiv2);
            //std::cout<<"I div by 2"<<"\n";
            //std::cout<<"I:"<<i<<" iMinus1:"<<iMinus1<<" iDiv2:"<<iDiv2<<" min:"<<min<<"\n";
            min++;
            seq[i]=min;
        }else if(i%2==0 && i%3==0){
            int iMinus1 = seq[i-1];
            int iDiv2 = seq[i/2];
            int iDiv3 = seq[i/3];
            int min1 = std::min(iMinus1,iDiv2);
            int min2 = std::min(min1,iDiv3);
            //std::cout<<"I div by 2 and 3"<<"\n";
            //std::cout<<"I:"<<i<<" iMinus1:"<<iMinus1<<" iDiv2:"<<iDiv2<<" iDiv3:"<<iDiv3<<" min1:"<<min1<<"min2:"<<min2<<"\n";
            min2++;
            seq[i]=min2;
        }else{
            int iMinus1 = seq[i-1];
            //std::cout<<"I div by 1"<<"\n";
            //std::cout<<"I:"<<i<<" iMinus1:"<<iMinus1<<"\n";
            iMinus1++;
            seq[i]=iMinus1;
        }
    }
    
    return seq;
}

int main() {
  int n;
  std::cin >> n;
  /*
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
  
  std::cout<<"\n";
  */
  
  vector<int> seqOp = opt_seq(n);
  int countO = seqOp[seqOp.capacity()-1];
  
  
    std::cout << countO <<std::endl;
    reverSeq(seqOp,n);
  
  
  /*
  for (int i = 0; i <= seqOp.capacity()-1; i++) {
        std::cout<<seqOp[i]<<" ";
  } 
  */
  
  
    
}