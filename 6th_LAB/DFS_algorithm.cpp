#include <bits/stdc++.h>
using namespace std;

void DFSRec(vector<vector<int>> &adj, vector<bool> &visited, int s)
{
    visited[s] = true;
    cout << s << " ";

    for (int i : adj[s])
    {
        if (visited[i] == false)
        {
            DFSRec(adj, visited, i);
        }
    }
}

void DFS(vector<vector<int>> &adj, int s)
{
    vector<bool> visited(adj.size(), false);
    DFSRec(adj, visited, s);
}

void addEdge(vector<vector<int>> &adj, int s, int t)
{
    adj[s].push_back(t);
    adj[t].push_back(s); 
}

int main()
{
    int V = 5;
    vector<vector<int>> adj(V);

    vector<vector<int>> edges = {
        {1, 2},
        {1, 0},
        {2, 0},
        {2, 3},
        {2, 4}
    };

    for (auto &e : edges)
    {
        addEdge(adj, e[0], e[1]);
    }

    int s = 1;
    cout << "DFS from source: " << s << endl;

    DFS(adj, s);

    return 0;
}