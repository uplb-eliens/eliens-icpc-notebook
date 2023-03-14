void dijkstra(ll n, vector<vector<pair<ll, ll>>> &adj, vector<ll> &dis) {
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
  for (int i = 0; i < n; i++) {
    dis[i] = INF;
  }
  dis[0] = 0;
  pq.push({0, 0});
  while (!pq.empty()) {
    auto p = pq.top();
    pq.pop();
    ll u = p.second;
    if (dis[u] != p.first) {
      continue;
    }
    for (auto x : adj[u]) {
      ll v = x.first, w = x.second;
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        pq.push({dis[v], v});
      }
    }
  }
}