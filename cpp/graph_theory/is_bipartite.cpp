bool is_bipartite(vector<ll> &col, vector<vector<ll>> &adj, ll n) {
  queue<pair<ll, ll>> q;
  for (ll i = 0; i < n; i++) {
    if (col[i] == -1) {
      q.push({i, 0});
      col[i] = 0;
      while (!q.empty()) {
        pair<ll, ll> p = q.front();
        q.pop();
        ll v = p.first, c = p.second;
        for (ll j : adj[v]) {
          if (col[j] == c) {
            return false;
          }
          if (col[j] == -1) {
            col[j] = (c ? 0 : 1);
            q.push({j, col[j]});
          }
        }
      }
    }
  }
  return true;
}