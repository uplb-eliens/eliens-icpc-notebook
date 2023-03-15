struct Edge {
  ll u, v, weight;
  bool operator<(Edge const& other) {
    return weight < other.weight;
  }
};
ll n;
vector<Edge> edges;
ll cost = 0;
vector<ll> tree_id(n);
vector<Edge> result;
for (ll i = 0; i < n; i++) {
  tree_id[i] = i;
}
sort(edges.begin(), edges.end());
for (Edge e : edges) {
  if (tree_id[e.u] != tree_id[e.v]) {
    cost += e.weight;
    result.push_back(e);
    ll old_id = tree_id[e.u], new_id = tree_id[e.v];
    for (ll i = 0; i < n; i++) {
      if (tree_id[i] == old_id) {
        tree_id[i] = new_id;
      }
    }
  }
}