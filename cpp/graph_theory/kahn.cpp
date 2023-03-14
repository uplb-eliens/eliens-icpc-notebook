void kahn(vector<vector<ll>> &adj) {
  ll n = adj.size();
  vector<ll> in_degree(n, 0);
  for (ll u = 0; u < n; u++) {
    for (ll v: adj[u]) {
      in_degree[v]++;
    }
  }
  queue<ll> q;
  for (ll i = 0; i < n; i++) {
    if (in_degree[i] == 0) {
      q.push(i);
    }
  }
  ll cnt = 0;
  vector<ll> top_order;
  while (!q.empty()) {
    ll u = q.front();
    q.pop();
    top_order.push_back(u);
    for (ll v : adj[u]) {
      if (--in_degree[v] == 0) {
        q.push(v);
      }
    }
    cnt++;
  }
  if (cnt != n) {
    cout << -1 << '\n';
    return;
  }
  for (ll i = 0; i < (ll) top_order.size(); i++) {
    cout << top_order[i] << ' ';
  }
  cout << '\n';
}