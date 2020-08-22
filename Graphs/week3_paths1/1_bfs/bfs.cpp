#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int distance(vector<vector<int> > &adj, int s, int t,int n) {
  vector<int> nodeDis(n,-1);
  vector<int> prevN(n,-1);
  nodeDis[s]=0;
  queue<int> orderQueue;
  orderQueue.push(s);
  bool isPath=false;
  while(!orderQueue.empty()){
      int u = orderQueue.front();
      orderQueue.pop();
      for(int i=0;i<adj[u].size();i++){
          if(nodeDis[adj[u][i]] == -1){
              if(adj[u][i] == t)
                isPath = true;
              orderQueue.push(adj[u][i]);
              nodeDis[adj[u][i]] = nodeDis[u]+1;
              prevN[adj[u][i]] = u;
          }
      }
  }
  
  
  int result=0;
  if(isPath == true){
      result = nodeDis[t];
      return result;
  }
  
  return -1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t,n);
}