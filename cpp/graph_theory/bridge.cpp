void bridge_util(vector<vector<ll>> &adj, ll u, vector<bool> &visited, vector<ll> &disc, vector<ll> &low, vector<ll> &parent) {
  static ll time = 0;
  visited[u] = true;
  disc[u] = low[u] = ++time;
  list<ll>::iterator i;
  for (auto v : adj[u]) {
    if (!visited[v]) {
      parent[v] = u;
      bridge_util(adj, v, visited, disc, low, parent);
      low[u] = min(low[u], low[v]);
      if (low[v] > disc[u]) {
        cout << u << ' ' << v << '\n';
      }
    } else if (v != parent[u]) {
      low[u] = min(low[u], disc[v]);
    }
  }
}

void bridge(vector<vector<ll>> &adj, ll n) {
  vector<bool> visited(n, false);
  vector<ll> disc(n), low(n), parent(n, -1);
  for (ll i = 0; i < n; i++) {
    if (!visited[i]) {
      bridge_util(adj, i, visited, disc, low, parent);
    }
  }
}