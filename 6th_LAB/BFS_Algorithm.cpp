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
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> adj(V);

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        addEdge(adj, u, v);
    }

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