vector<ll> prim_mst(ll n, vector<vector<pair<ll, ll>>> &adj) {
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
  ll src = 0;
  vector<ll> key(n, INF), parent(n, -1);
  vector<bool> in_mst(n, false);
  pq.push(make_pair(0, src));
  key[src] = 0;
  while (!pq.empty()) {
    ll u = pq.top().second;
    pq.pop();
    if (in_mst[u]){
      continue;
    }
    in_mst[u] = true;
    for (auto p : adj[u]) {
      ll v = p.first, w = p.second;
      if (in_mst[v] == false && w < key[v]) {
        key[v] = w;
        pq.push(make_pair(key[v], v));
        parent[v] = u;
      }
    }
  }
  return parent;
}