ll m, n;
vector<ll> dp_before(n), dp_cur(n);
ll C(ll i, ll j);
void compute(ll l, ll r, ll optl, ll optr) {
  if (l > r) {
    return;
  }
  ll mid = (l + r) >> 1;
  pair<ll, ll> best = {LLONG_MAX, -1};
  for (ll k = optl; k <= min(mid, optr); k++) {
    best = min(best, {(k ? dp_before[k - 1] : 0) + C(k, mid), k});
  }
  dp_cur[mid] = best.first;
  ll opt = best.second;
  compute(l, mid - 1, optl, opt);
  compute(mid + 1, r, opt, optr);
}
ll solve() {
  for (ll i = 0; i < n; i++) {
    dp_before[i] = C(0, i);
  }
  for (ll i = 1; i < m; i++) {
    compute(0, n - 1, 0, n - 1);
    dp_before = dp_cur;
  }
  return dp_before[n - 1];
}