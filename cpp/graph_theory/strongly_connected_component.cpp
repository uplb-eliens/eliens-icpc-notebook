void dfs(ll u, vector<vector<ll>> &adj, vector<bool> &visited) {
  visited[u] = true;
  cout << u + 1 << ' ';
  for (ll v : adj[u]) {
    if (!visited[v]) {
      dfs(v, adj, visited);
    }
  }
}
vector<vector<ll>> get_transpose(ll n, vector<vector<ll>> &adj) {
  vector<vector<ll>> res(n);
  for (ll u = 0; u < n; u++) {
    for (ll v : adj[u]) {
      res[v].push_back(u);
    }
  }
  return res;
}
void fill_order(ll u, vector<vector<ll>> &adj, vector<bool> &visited, stack<ll> &stk) {
  visited[u] = true;
  for(auto v : adj[u]) {
    if(!visited[v]) {
      fill_order(v, adj, visited, stk);
    }
  }
  stk.push(u);
}
void get_scc(ll n, vector<vector<ll>> &adj) {
  stack<ll> stk;
  vector<bool> visited(n, false);
  for (ll i = 0; i < n; i++) {
    if (!visited[i]) {
      fill_order(i, adj, visited, stk);
    }
  }
  vector<vector<ll>> transpose = get_transpose(n, adj);
  for (ll i = 0; i < n; i++) {
    visited[i] = false;
  }
  while (!stk.empty()) {
    ll u = stk.top();
    stk.pop();
    if (!visited[u]) {
      dfs(u, transpose, visited);
      cout << '\n';
    }
  }
}