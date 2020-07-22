/*

#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;

class dataNode{
    public:
    int Node;
    int cost;
};

struct compareV{
bool operator()(dataNode const& p1, dataNode const& p2) 
    { 
        if(p1.cost < p2.cost)
            return p1.Node;
        else
            return p2.Node;
    } 
};

int distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t,int n,int totalWeight) {
  //std::cout<<"s:"<<s<<" t:"<<t<<"\n";
  bool isFound = false;
  vector<int> distance(n,totalWeight);
  vector<int> prev(n,-1);
  distance[s]=0;
  std::priority_queue<dataNode,vector<dataNode>,compareV> mypq;
  dataNode d1;
  d1.Node = s;
  d1.cost = 0;
  mypq.push(d1);
  while(!mypq.empty()){
    //std::cout<<"Initial mypq.size():"<<mypq.size()<<"\n";
    dataNode minT;
    minT = mypq.top();
    mypq.pop();
    //std::cout<<"minT Node+1:"<<minT.Node+1<<" minT cost:"<<minT.cost<<"\n";
    //std::cout<<"Dist minT:"<<distance[minT.Node]<<"\n";
    for(int i=0;i<adj[minT.Node].size();i++){
        if(adj[minT.Node][i] == t || minT.Node == t){
                //std::cout<<"Found"<<"\n";
                isFound = true;
            }
        if(distance[adj[minT.Node][i]]>distance[minT.Node]+cost[minT.Node][i]){
           distance[adj[minT.Node][i]]=distance[minT.Node]+cost[minT.Node][i];
           prev[adj[minT.Node][i]] = minT.Node;
           //std::cout<<"adj[minT.Node][i]+1:"<<adj[minT.Node][i]+1<<"\n";
           //std::cout<<"distance[minT.Node]+cost[minT.Node][i]:"<<distance[minT.Node]+cost[minT.Node][i]<<"\n";
           dataNode chPri;
           chPri.Node = adj[minT.Node][i];
           chPri.cost = distance[adj[minT.Node][i]];
           mypq.push(chPri);
        }
    }
    //std::cout<<"Final mypq.size():"<<mypq.size()<<"\n";
  }
  
  //std::cout<<"distance[2]+1:"<<distance[2]<<"\n";
  
  if(isFound == true){
    int totalCost=0;
    int lastCost=0;
    while(t!=s){
        totalCost = totalCost + distance[t];
        lastCost = distance[t];
        t = prev[t];
    }
    totalCost = totalCost - lastCost;
    return totalCost;
  }
  
  //td::cout<<"Not found"<<"\n";
  return -1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  int totalWeight=0;
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    totalWeight = totalWeight + w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  
  /*
  for(int i=0;i<n;i++){
      for(int j=0;j<adj[i].size();j++){
          std::cout<<"i:"<<i<<" adj[i][j]:"<<adj[i][j]<<"\n";
          std::cout<<"cost:"<<cost[i][j]<<"\n";
      }
  }
  */
 /*
 // std::cout << distance(adj, cost, s, t,n,totalWeight);
}

*/

#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pi pair<int, int>
#define s second
#define f first

int distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int source, int target) {
    int n = adj.size();
    vector<long long> dist(n, INT_MAX);

    // min heap
    priority_queue < pi, vector<pi>, greater<pi> > pq;

    pq.push(mp(0, source));
    dist[source] = 0;

    while (!pq.empty()) {
        // get first vertex
        int u = pq.top().s;
        pq.pop();

        // going through all adjacent vertices of a vertex
        for (int i = 0; i < adj[u].size(); i++) {
            int w = adj[u][i];
            int weight = cost[u][i];

            // if there is a shirter path to w through u, update
            if (dist[w] > dist[u] + weight) {
                dist[w] = dist[u] + weight;
                pq.push(mp(dist[w], w));
            }
        }
    }

    return dist[target] == INT_MAX ? -1 : (int) dist[target];
}

int main() {
    int n, m;
    std::cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>());
    vector<vector<int> > cost(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int x, y, w;
        std::cin >> x >> y >> w;
        adj[x - 1].push_back(y - 1);
        cost[x - 1].push_back(w);
    }
    int s, t;
    std::cin >> s >> t;
    s--, t--;
    std::cout << distance(adj, cost, s, t);
}