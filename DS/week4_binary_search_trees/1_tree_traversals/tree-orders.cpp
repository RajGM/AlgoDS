#include <iostream>
#include <vector>
#include <algorithm>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#include <stack>
//#include <unordered_map>
#include <map>
#include <queue>          // std::priority_queue
#endif

using std::vector;
using std::ios_base;
using std::cin;
using std::cout;

class TreeOrders {
  int n;
  vector <int> key;
  vector <int> left;
  vector <int> right;
  std::map<int,int> indexR;
  vector <bool> isVisited;
  std::priority_queue<int> pqL;

public:
  void read() {
    cin >> n;
    key.resize(n);
    left.resize(n);
    right.resize(n);
    isVisited.resize(n);
    for (int i = 0; i < n; i++) {
      int val;
      int lI;
      int rI;
      cin>>val;
      key[i]=val; 
      cin>> lI;
      left[i] = lI;
      
      if(lI!=-1){
        pqL.push(lI);  
      }
      
      cin >> right[i];
      //indexR[val] = i;
      indexR.insert ( std::pair<int,int>(val,i) );
      isVisited[i]=false;
    }
  }
  
  vector <int> in_order() {
    std::cout<<"F12"<<"\n";
    for(int i=0;i<isVisited.size();i++){
        isVisited[i]=false;
    }
    
    vector<int> result;    
    std::stack<int> recordS;
    std::cout<<"F11"<<"\n";
    recordS.push(key[0]);
    int currV = recordS.top();
    int currI = indexR.find(currV)->second;
    
    std::cout<<"F1"<<"\n";
    while(!recordS.empty()){
        std::cout<<"F2"<<"\n";
        if(result.size()==n)
        break;
        currV = recordS.top();
        currI = indexR.find(currV)->second;
        std::cout<<"F3"<<"\n";
        if(left[currI]==-1){
           /*
            currV = recordS.top();
            currI = indexR.find(currV)->second;
            */
            std::cout<<"F6"<<"\n";
            recordS.pop();
            result.push_back(currV);
            isVisited[currI]=true;
            std::cout<<"F7"<<"\n";
            while(right[currI]==-1){
                currV = recordS.top();
                currI = indexR.find(currV)->second;
                recordS.pop();
                result.push_back(currV);
                isVisited[currI]=true;
            }
            currI = right[currI];
            currV = key[currI];
            recordS.push(currV);
        }else{
            /*
            if(isVisited[currI]==false){
            recordS.push(currV);   
           }
           */
           std::cout<<"F5"<<"\n";
            currI = left[currI];
            currV = key[currI];
            recordS.push(currV);
            }   
        std::cout<<"F4"<<"\n";
    }  
    
    return result;
  
  }

  vector <int> pre_order() {
      
    for(int i=0;i<isVisited.size();i++){
        isVisited[i]=false;
    }
    
    vector<int> result;    
    std::stack<int> recordS;
    recordS.push(key[0]);
    result.push_back(key[0]);
    isVisited[0]=true;
    int currV = recordS.top();
    int currI = indexR.find(currV)->second;
        
    while(!recordS.empty()){
        if(result.size()==n)
            break;
        currV = recordS.top();
        currI = indexR.find(currV)->second;
        if(isVisited[currI]==false){
        result.push_back(currV);
        isVisited[currI]=true;
        }
        if(left[currI]==-1){
            currV = recordS.top();
            currI = indexR.find(currV)->second;
            recordS.pop();
            while(right[currI]==-1){
            currV = recordS.top();                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
            currI = indexR.find(currV)->second;
            recordS.pop();
            }
            currI = right[currI];
            currV = key[currI];
            result.push_back(currV);
            recordS.push(currV);
            isVisited[currI]=true;
         }else{
            currI = left[currI];
            currV = key[currI];
            
            if(isVisited[currI]==false){
            result.push_back(currV);
            isVisited[currI]=true;
            recordS.push(currV);
            }
       
        }
    }
    
    
    return result;
  }

  vector <int> post_order() {
    vector<int> result;
    // Finish the implementation
    // You may need to add a new recursive method to do that
    
    return result;
  }
};

void print(vector <int> a) {
  for (size_t i = 0; i < a.size(); i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << a[i];
  }
  cout << '\n';
}

int main_with_large_stack_space() {
  ios_base::sync_with_stdio(0);
  TreeOrders t;
  t.read();
  print(t.in_order());
  print(t.pre_order());
  print(t.post_order());
  return 0;
}

int main (int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }
#endif

  return main_with_large_stack_space();
}
