#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include<bits/stdc++.h> 
using std::vector;


int n,m;
vector<vector<int>> capacity;
vector<vector<int>> adj;


int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    std::queue<std::pair<int, int>> q;
    q.push({s, INT_MAX});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = std::min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int maxflow(int s, int t) {
    int flow = 0;
    vector<int> parent(n);
    int new_flow;

    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

int main(){
std::cin>>n>>m;

for(int i=0;i<m;i++){
    int s,d,c;
    std::cin>>s>>d>>c;
    capacity[s][d]=c;
    adj[s][d]=1;
}

    std::cout<<maxflow(0,n-1);
    
    return 0;    
}


