ll log2_floor(ll i) {
  return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}
vector<vector<ll>> build_sum(ll N, ll K, vector<ll> &array) {
  vector<vector<ll>> st(K + 1, vector<ll>(N + 1));
  for (ll i = 0; i < N; i++) {
    st[0][i] = array[i];
  }
  for (ll i = 1; i <= K; i++) {
    for (ll j = 0; j + (1 << i) <= N; j++) {
      st[i][j] = st[i - 1][j] + st[i - 1][j + (1 << (i - 1))];
    }
  }
  return st;
}
ll sum_query(ll L, ll R, ll K, vector<vector<ll>> &st) {
  ll sum = 0;
  for (ll i = K; i >= 0; i--) {
    if ((1 << i) <= R - L + 1) {
      sum += st[i][L];
      L += 1 << i;
    }
  }
  return sum;
}
vector<vector<ll>> build_min(ll N, ll K, vector<ll> &array) {
  vector<vector<ll>> st(K + 1, vector<ll>(N + 1));
  for (ll i = 0; i < N; i++) {
    st[0][i] = array[i];
  }
  for (ll i = 1; i <= K; i++) {
    for (ll j = 0; j + (1 << i) <= N; j++) {
      st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
    }
  }
  return st;
}
ll min_query(ll L, ll R, vector<vector<ll>> &st) {
  ll i = log2_floor(R - L + 1);
  return min(st[i][L], st[i][R - (1 << i) + 1]);
}