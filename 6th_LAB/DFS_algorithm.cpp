#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj, int node, vector<int>& visited)
{
    visited[node] = 1;
    cout << node << " ";

    for(int x : adj[node])
    {
        if(visited[x] == 0)
        {
            dfs(adj, x, visited);
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
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> adj(V);

    cout << "Enter edges (u v):\n";
    for(int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        addEdge(adj, u, v);
    }

    int start;
    cout << "Enter starting node: ";
    cin >> start;

    vector<int> visited(V, 0);

    cout << "DFS Traversal: ";
    dfs(adj, start, visited);

    return 0;
}