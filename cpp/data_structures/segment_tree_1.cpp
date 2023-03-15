void build(vector<ll> &a, ll v, ll tl, ll tr) {
  if (tl == tr) {
    t[v] = a[tl];
  } else {
    ll tm = (tl + tr) / 2;
    build(a, v * 2, tl, tm);
    build(a, v * 2 + 1, tm + 1, tr);
    t[v] = 0;
  }
}
void update(ll v, ll tl, ll tr, ll l, ll r, ll add) {
  if (l > r) {
    return;
  }
  if (l == tl && r == tr) {
    t[v] += add;
  } else {
    ll tm = (tl + tr) / 2;
    update(v * 2, tl, tm, l, min(r, tm), add);
    update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, add);
  }
}
ll query(ll v, ll tl, ll tr, ll pos) {
  if (tl == tr) {
    return t[v];
  }
  ll tm = (tl + tr) / 2;
  if (pos <= tm) {
    return t[v] + get(v * 2, tl, tm, pos);
  } else {
    return t[v] + get(v * 2 + 1, tm + 1, tr, pos);
  }
}