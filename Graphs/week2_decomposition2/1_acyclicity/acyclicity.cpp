#include <bits/stdc++.h>
//#include <algorithm>    // std::reverse

using namespace std;

int reach(vector<vector<int>> &adj, int x, int n)
{
    vector<bool> visited(n);
    for (size_t i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    stack<int> record;
    //visited[x] = true;
    record.push(x);
    vector<int> preV(n,0);
    vector<int> postV(n,0);
    int counter = 0;
    int nVisited=0;
    while(!record.empty())
    {
        x = record.top();
        record.pop();
        preV[x]=counter;
        counter++;
        if(visited[x]==false){
            visited[x]=true;
            for(int i=0;i<adj[x].size();i++){
                if(visited[adj[x][i]] == false)
                record.push(adj[x][i]);
            }
            
        std::cout<<"x:"<<x<<"\n";
        
        for(int i=0;i<adj[x].size();i++){
            if(visited[adj[x][i]]==true)
                nVisited++;
        }
        
        if(nVisited==adj[x].size()){
            postV[x]=counter;
            counter++;
            std::cout<<"postV[x]:"<<postV[x]<<" counter:"<<counter<<"\n";
            nVisited=0;
        }else{
            nVisited=0;
        }
        
        }
        
    }
    
    postV[0]=counter;
    for(int i=0;i<n;i++){
        std::cout<<preV[i]<<" ";
    }
    std::cout<<"\n";
    for(int i=0;i<n;i++){
        std::cout<<postV[i]<<" ";
    }
    
    /*
    for(int i=0;i<n;i++){
        for(int j=0;j<adj[i].size();j++){
            int chV = adj[i][j];
            std::cout<<"I:"<<i<<"\n";
            std::cout<<"chV:"<<chV<<"\n";
            std::cout<<"finalPost[i]:"<<finalPost[i]<<"\n";
            std::cout<<"finalPost[chV]:"<<finalPost[chV]<<"\n";
            if(!(finalPost[i]>finalPost[chV])){
                std::cout<<"Return point"<<"\n";
                return 1;
            }
        }
    }
    */
    std::cout<<"\n";
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
        //adj[y - 1].push_back(x - 1);
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<adj[i].size();j++){
            std::cout<<"Node:"<<i<<" Nei:"<<adj[i][j]<<"\n";
        }
    }
    //int x;
    //cin >> x;
    cout << reach(adj, 0, n);
}