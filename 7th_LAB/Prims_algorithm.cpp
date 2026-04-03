#include <bits/stdc++.h>
using namespace std;
#define V7;

int minKey(vector<int> &key, vector<bool> &mstSet, int V) {
    int minVal = INT_MAX, min_index = -1;

    for (int v = 0; v <= V-1; v++) {
        if (!mstSet[v] && key[v] < minVal) {
            minVal = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void printMST(vector<int> &parent, vector<vector<int>> &graph, int V) {
    int cost = 0;
    cout << "Edge \tWeight\n";

    for (int i = 1; i <= V-1; i++) {
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << endl;
        cost += graph[i][parent[i]];
    }

    cout << "Minimum Cost Spanning Tree: " << cost << endl;
}
void primMST(vector<vector<int>> &graph) {
    int V = graph.size();

    vector<int> parent(V);
    vector<int> key(V, INT_MAX);
    vector<bool> mstSet(V, false);

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V);
        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph, V);
}

int main() {
    vector<vector<int>> graph = {
        {0, 3, 1, 0, 6, 6, 0},
        {3, 0, 4, 0, 0, 0, 0},
        {1, 4, 0, 5, 0, 0, 0},
        {0, 0, 5, 0, 5, 0, 7},
        {6, 0, 0, 5, 0, 0, 0},
        {6, 0, 0, 0, 0, 0, 3},
        {0, 0, 0, 7, 0, 3, 0},
    };

    primMST(graph);
    return 0;
}