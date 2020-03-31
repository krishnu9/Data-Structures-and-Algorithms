#include <bits/stdc++.h>
using namespace std;
// dis[i] = distance from starting node to ith node,
// ways[i] = number of ways to reach ith node from stating node, s

int s = 0;

void bfs(vector<vector<int>> &adj) {
  int n = adj.size();
  queue<int> q;
  vector<int> dis(n, -1), ways(n);
  dis[s] = 0;
  ways[s] = 1;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    cout << u << ' ';
    for (auto i : adj[u]) {
      if (dis[i] == -1) {
        dis[i] = dis[u] + 1;
        ways[i] += ways[u];
        q.push(i);
      } else {
        if (dis[u] + 1 == dis[i])
          ways[i] += ways[u];
      }
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