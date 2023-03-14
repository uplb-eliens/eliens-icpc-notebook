void dfs(ll v) {
  visited[v] = true;
  for (ll u : adj[v]) {
    if (!visited[u]) {
      dfs(u);
    }
  }
  ans.push_back(v);
}
void topological_sort() {
  visited.assign(n, false);
  ans.clear();
  for (ll i = 0; i < n; ++i) {
    if (!visited[i]) {
      dfs(i);
    }
  }
  reverse(ans.begin(), ans.end());
}