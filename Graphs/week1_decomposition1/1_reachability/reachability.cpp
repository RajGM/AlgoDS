#include <bits/stdc++.h>

using namespace std;

int reach(vector<vector<int>> &adj, int x, int y, int n)
{

    if (x == y)
    {
        return 1;
    }
    vector<bool> visited(n);
    for (size_t i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    stack<int> record;
    visited[x] = true;
    record.push(x);

    while (!record.empty())
    {
        x = record.top();
        record.pop();

        for (int i = 0; i < adj[x].size(); i++)
        {
            if (adj[x][i] == y)
            {
                return 1;
            }
            if (visited[adj[x][i]] != true)
            {
                visited[adj[x][i]] = true;
                record.push(adj[x][i]);
                break;
            }
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
        adj[y - 1].push_back(x - 1);
    }
    int x, y;
    cin >> x >> y;
    cout << reach(adj, x - 1, y - 1, n);
}