#include <bits/stdc++.h>
using namespace std;
#define MX 100005

int arrival[MX], departure[MX], vis[MX], parent[MX];
vector<pair<int, int>> g[MX];
int n, m;

void dijkstra(int source, int destination) {
  // Distances to and from all nodes = infinity
  // Mark all nodes as unvisited
  for (int i = 1; i <= n; i++) {
    arrival[i] = INFINITY;
    departure[i] = INFINITY;
    vis[i] = 0;
  }
  // set to store nodes being preprocessed
  // vertex label is stored in second of pair (it has to be done this way to
  // keep the vertices sorted by distance (distance must be first item in pair)
  set<pair<int, int>> s;
  // source to source = 0
  s.insert({0, source});
  cout << "Inserted " << source << " into set." << '\n';
  arrival[source] = 0;
  while (!s.empty()) {
    // s.begin() is the minimum distance vertex, read as u
    auto x = *s.begin();
    s.erase(x); // erase from set, min distance is finalized
    int u = x.second;
    cout << "Removed " << u << " from set." << '\n';
    cout << "Current vertex being processed, u: " << u << '\n';
    vis[u] = 1; // Mark the vertex being processed as visited
    departure[u] = arrival[u];
    // Iterate over neighbors of vertex being processed
    for (auto node : g[u]) {
      int v = node.first;
      int wt = node.second;
      cout << "Adjacent of " << u << ": " << v << '\n';
      if (arrival[v] > departure[u] + wt) {
        /*  If distance of v is not INF then it must be in
        our set, so removing it and inserting again
        with updated less distance. */
        s.erase({arrival[v], v});
        arrival[v] = departure[u] + wt;
        s.insert({arrival[v], v});
        cout << "Updated and inserted " << v << " into set." << '\n';
        /* Note : We extract only those vertices from Set
        for which distance is finalized. So for them,
        we would never reach here.  */
        parent[v] = u;
      }
    }
  }
  if (!vis[destination]) {
    cout << "-1";
    return;
  }
  // Displaying the shortest path
  int v = destination;
  vector<int> ans;
  while (parent[v]) {
    ans.push_back(v);
    v = parent[v];
  }
  ans.push_back(source);
  reverse(ans.begin(), ans.end());
  for (auto it : ans) {
    cout << it << ' ';
  }
  // Distance to destination
  if (vis[destination])
    cout << '\n' << arrival[destination];
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w}); // Input for undirected weighted graphs
    g[v].push_back({u, w});
  }

  dijkstra(1, n);

  return 0;
}

// Problem: https://codeforces.com/contest/20/problem/C
// Input :
// 5 6
// 1 2 2
// 2 5 5
// 2 3 4
// 1 4 1
// 4 3 3
// 3 5 1
// Output: 1 4 3 5      5
