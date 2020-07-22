/*
#include <iostream>
#include <vector>
#include <algorithm>    // std::sort

using std::vector;

int partition3(vector<int> &A) {
  int netSum=0;
  int eachG=0;
  sort(A.begin(),A.begin()+A.size());
  //std::cout<<"can't sort"<<"\n";
  for(int i=0;i<A.size();i++){
      netSum = netSum + A[i];
  }
  if(netSum%3!=0 || A.size()==0 || netSum==0)
    return 0;
  
  std::vector<int> board;
  board.resize(A.size());
  eachG = netSum/3;
  int n1=eachG,n2=eachG,n3=eachG;
  //std::cout<<"Not good copying"<<"\n";
 
 for(int i=0;i<A.size();i++){
     board[i] = A[i];
 }
 
 for(int i=0;i<board.size();i++){
     std::cout<<board[i]<<" ";
 }
 std::cout<<"\n";
 
 std::cout<<"OK upto here"<<"\n";
 
 int rm=0;
 int i=board.size()-1;
 for(;i>=0;){
     
     //std::cout<<"Begin:"<<"N1:"<<n1<<" N2:"<<n2<<" N3:"<<n3<<"\n";
     
     if (n1 == 0 && n2 == 0 && n3 == 0)
		break;

	// base case: no items left
	if (board.size() <= 0)
		break;
     
    if(n1-board[i]>=0){
        n1=n1-board[i];
        rm=board[i];
        board.erase(board.begin()+i);
        
        for(int i=0;i<board.size();i++){
        std::cout<<board[i]<<" ";
        }
        std::cout<<"\n";
        
        i--;
    }
    else if(n2-board[i]>=0){
        n2=n2-board[i];
        rm=board[i];
        board.erase(board.begin()+i);
        /*
        for(int i=0;i<board.size();i++){
        std::cout<<board[i]<<" ";
        }
        std::cout<<"\n";
        
        i--;
    }
    else if(n3-board[i]>=0){
        n3=n3-board[i];
        rm=board[i];
        board.erase(board.begin()+i);
        /*
        for(int i=0;i<board.size();i++){
        std::cout<<board[i]<<" ";
        }
        std::cout<<"\n";
        
        i--;
    }
    else{
        break;
    }
    
    //std::cout<<"After:"<<"N1:"<<n1<<" N2:"<<n2<<" N3:"<<n3<<" rm:"<<rm<<"\n";
 }
 
 if(n1==0 && n2==0 && n3==0)
    return 1;
 else
    return 0;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}

*/

#include <iostream>
#include <numeric>

bool subsetSum(int S[], int n, int a, int b, int c)
{
	if (a == 0 && b == 0 && c == 0)
		return true;

	if (n < 0)
		return false;
    
	bool A = false;
	if (a - S[n] >= 0){
	    std::cout<<"a-S[n] a:"<<a<<" S[n]:"<<S[n]<<"\n";
		A = subsetSum(S, n - 1, a - S[n], b, c);
		std::cout<<"Inside function call A:"<<A<<"\n";
	}
	bool B = false;
	if (!A && (b - S[n] >= 0)){
	    std::cout<<"b-S[n] b:"<<b<<" B[n]:"<<S[n]<<"\n";
		B = subsetSum(S, n - 1, a, b - S[n], c);
		std::cout<<"Inside function call B:"<<B<<"\n";
	}
	bool C = false;
	if ((!A && !B) && (c - S[n] >= 0)){
	    std::cout<<"c-S[n] c:"<<c<<" S[n]:"<<S[n]<<"\n";
		C = subsetSum(S, n - 1, a, b, c - S[n]);
		std::cout<<"Inside function call C:"<<C<<"\n";
	}
	std::cout<<"Return:"<<"A:"<<A<<" B:"<<B<<" C:"<<C<<"\n";
	return A || B || C;
}

bool partition(int S[], int n)
{
	if (n < 3)
		return false;

	int sum = std::accumulate(S, S + n, 0);
	return !(sum % 3) && subsetSum(S, n - 1, sum/3, sum/3, sum/3);
}

int main()
{
	int S[] = { 7, 3, 2, 1, 5, 4, 8 };
    
	int n = sizeof(S) / sizeof(S[0]);
    for(int i=0;i<n;i++){
        std::cout<<S[i]<<" ";
    }
    std::cout<<"\n";
	if (partition(S, n))
		std::cout << "Yes";
	else
		std::cout << "No";

	return 0;
}