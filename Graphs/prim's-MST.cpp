#include <bits/stdc++.h>
using namespace std;

void primMST(vector<vector<int>> adj, int V)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int src = 0;
    vector<int> key(V, INFINITY);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);
    pq.push({0, src});
    key[src] = 0;
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        inMST[u] = true;
        for (int i = 0; i < V; i++)
        {
            int v = i;
            int wt = adj[u][i];
            if (!inMST[v] && key[v] > wt)
            {
                key[v] = wt;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }
    for (int i = 1; i < V; i++)
        cout << parent[i] << ' ' << i << endl;
}