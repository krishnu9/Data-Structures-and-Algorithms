#include <bits/stdc++.h>
using namespace std;

int visited[1000001];

void DFS(vector<vector<int>> &adj, int s) {
  int n = adj.size();
  cout << s << ' ';
  visited[s] = 1;
  for (auto i : adj[s]) {
    if (!visited[i])
      DFS(adj, i);
  }
}

int main() {

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

  DFS(adj, 0);

  return 0;
}

// Input: 5 1 2 -1 4 -1 1 3 -1 4 -1 -1
// Output: 0 1 4 2 3