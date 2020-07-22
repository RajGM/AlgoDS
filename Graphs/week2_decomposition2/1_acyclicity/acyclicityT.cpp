#include <bits/stdc++.h>

using namespace std;

bool iscyclic(vector<vector<int> > &adj, int v, vector<bool> &visited, 
vector<bool> &stack){
    
    if(visited[v]==false){
        visited[v]=true;
        stack[v]=true;

        for (int i = 0; i < adj[v].size(); i++)
        {
            //std::cout<<"v:"<<v<<"\n";
            //std::cout<<"adj[v][i]:"<<adj[v][i]<<"\n";
            
//std::cout<<"visited[adj[v][i]]:"<<visited[adj[v][i]]<<"\n";
            if(!visited[adj[v][i]] && 
iscyclic(adj,adj[v][i],visited,stack)){
                //std::cout<<"Above true"<<"\n";
                return true;
            }else if(stack[adj[v][i]]){
                //std::cout<<"Below true"<<"\n";
                return true;
            }
        }
    }
    stack[v]=false;
    return false;
}

int acyclic(vector<vector<int> > &adj, int n) {

    vector<bool> visited(n);
    vector<bool> stack(n);
    for (int i = 0; i < n; i++){
        visited[i] = false; 
        stack[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if(iscyclic(adj,i,visited,stack)){
            return 1;
        }
    }
    return 0;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>());
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x - 1].push_back(y - 1);
    }
    cout << acyclic(adj, n);
}
