void bellman_ford(vector<vector<ll>> &edges, ll n, ll m, ll src, vector<ll> &dis) {
  for (ll i = 0; i < n; i++) {
    dis[i] = INF;
  }
  for (ll i = 0; i < n - 1; i++) {
    for (ll j = 0; j < m; j++) {
      ll u = edges[j][0], v = edges[j][1], w = edges[j][2];
      if (dis[u] < INF) {
        dis[v] = min(dis[v], dis[u] + w);
      }
    }
  }
  for (ll i = 0; i < m; i++) {
    ll u = edges[i][0], v = edges[i][1], w = edges[i][2];
    if (dis[u] < INF && dis[u] + w < dis[v]) {
      cout << "The graph contains a negative cycle." << '\n';
    }
  }
}