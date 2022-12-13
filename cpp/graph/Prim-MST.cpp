vector<int> prim_mst(int n, vector<vector<pair<int, ll>>> &adj) {
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
  int src = 0;
  vector<ll> key(n, INF);
  vector<int> parent(n, -1);
  vector<bool> in_mst(n, false);
  pq.push(make_pair(0, src));
  key[src] = 0;
  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();
    if(in_mst[u] == true){
      continue;
    }
    in_mst[u] = true;
    for (auto p : adj[u]) {
      int v = p.first;
      ll w = p.second;
      if (in_mst[v] == false && w < key[v]) {
        key[v] = w;
        pq.push(make_pair(key[v], v));
        parent[v] = u;
      }
    }
  }
  return parent;
}