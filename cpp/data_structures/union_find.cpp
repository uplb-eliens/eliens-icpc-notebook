struct UnionFind {
  vector<ll> p;
  UnionFind(ll n) {
    p.assign(n, -1);
  }
  ll find_set(ll i) {
    return (p[i] < 0) ? i : (p[i] = find_set(p[i]));
  }
  bool is_same(ll i, ll j) {
    return find_set(i) == find_set(j);
  }
  void union_sets(ll i, ll j) {
    ll x = find_set(i), y = find_set(j);
    if (x != y) {
      if (p[x] < p[y]) {
        p[x] += p[y];
        p[y] = x;
      } else {
        p[y] += p[x];
        p[x] = y;
      }
    }
  }
};