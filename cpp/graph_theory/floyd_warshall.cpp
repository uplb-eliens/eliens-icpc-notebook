void floyd_warshall(vector<vector<ll>> &dis, ll n) {
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < n; j++) {
      dis[i][j] = (i == j ? 0 : INF);
    }
  }
  for (ll k = 0; k < n; k++) {
    for (ll i = 0; i < n; i++) {
      for (ll j = 0; j < n; j++) {
        if (dis[i][k] < INF && dis[k][j] < INF) {
          dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        }
      }
    }
  }
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < n; j++) {
      for (ll k = 0; k < n; k++) {
        if (dis[k][k] < 0 && dis[i][k] < INF && dis[k][j] < INF) {
          dis[i][j] = -INF;
        }
      }
    }
  }
}