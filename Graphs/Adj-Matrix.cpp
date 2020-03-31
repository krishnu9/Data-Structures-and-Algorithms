#include <bits/stdc++.h>
using namespace std;

void processGraph(int **adj, int n) {}

int main() {

  int n, e;
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

  processGraph(adj, n);

  for (int i = 0; i < n; i++) {
    delete[] adj[i];
  }
  delete[] adj;

  return 0;
}