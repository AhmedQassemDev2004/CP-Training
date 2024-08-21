#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int node) {
  visited[node] = true;
  cout << "VISITED: " << node << endl;

  for (auto it : adj[node]) {
    if (!visited[it]) {
      dfs(it);
    }
  }
}

int main() {
  int n = 5;
  adj.resize(n);
  visited.resize(n, false);

  adj[0].push_back(1);
  adj[0].push_back(2);
  adj[1].push_back(0);
  adj[1].push_back(3);
  adj[2].push_back(0);
  adj[2].push_back(4);
  adj[3].push_back(1);
  adj[4].push_back(2);

  cout << "Adjacency List:" << endl;
  for (int i = 0; i < n; i++) {
    cout << i << ": ";
    for (auto j : adj[i]) {
      cout << j << " ";
    }
    cout << endl;
  }

  dfs(0);

  return 0;
}
