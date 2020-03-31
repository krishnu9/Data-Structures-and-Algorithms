#include <bits/stdc++.h>
using namespace std;

int n, e;

void DFS(int **adj, int s, int *visited) {
  cout << s << ' ';
  visited[s] = 1;
  for (int i = 0; i < n; i++) {
    if (!visited[i] && adj[s][i] == 1) {
      DFS(adj, i, visited);
    }
  }
  return;
}

int main() {

  cin >> n >> e;

  int **adj = new int *[n];

  for (int i = 0; i < n; i++) {
    adj[i] = new int[n];
    for (int j = 0; j < n; j++) {
      adj[i][j] = 0;
    }
  }

  for (int i = 0; i < e; i++) {
    int f, s;
    cin >> f >> s;
    adj[f][s] = adj[s][f] = 1;
  }
  int visited[n] = {};
  DFS(adj, 0, visited);

  for (int i = 0; i < n; i++) {
    delete[] adj[i];
  }
  delete[] adj;

  return 0;
}