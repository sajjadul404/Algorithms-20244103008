#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>>& adj, int s, vector<bool>& visited)
{
    queue<int> q;

    visited[s] = true;

    q.push(s);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop(); 

        cout << curr << " ";  

        for (int x : adj[curr])
        {
            if (!visited[x])
            {
                visited[x] = true;
                q.push(x);
            }
        }
    }
}

void addEdge(vector<vector<int>>& adj, int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{
    int V = 6; 
    vector<vector<int>> adj(V);

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);

    addEdge(adj, 4, 5);

    vector<bool> visited(V, false);

    cout << "BFS Traversal of Disconnected Graph: ";

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            bfs(adj, i, visited);
        }
    }

    return 0;
}