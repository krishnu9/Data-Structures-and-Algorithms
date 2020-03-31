#include <bits/stdc++.h>
using namespace std;
// dis[i] = distance from 0th node to ith node,
void bfs(vector<vector<int>> &adj) {
  int n = adj.size();
  queue<int> q;
  vector<int> dis(n, -1);
  dis[0] = 0;
  q.push(0);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    cout << u << ' ';
    for (auto i : adj[u]) {
      if (dis[i] != -1)
        continue;
      dis[i] = dis[u] + 1;
      q.push(i);
    }
  }
}

int main() {

  // GRAPH Adjacency List
  int n;
  cin >> n;                   // Number of nodes
  vector<vector<int>> adj(n); // Adjacency lists.
  for (int i = 0; i < n; i++) {
    cout << "Node: " << i << '\n';
    int c;
    cin >> c;
    while (c != -1) {
      adj[i].push_back(c);
      cin >> c;
    }
  }

  bfs(adj);
  return 0;
}