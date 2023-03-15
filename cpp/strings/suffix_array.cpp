vector<ll> sort_cyclic_shifts(string const& s) {
  ll n = s.size();
  const ll alphabet = 256;
  vector<ll> p(n), c(n), cnt(max(alphabet, n), 0);
  for (ll i = 0; i < n; i++) {
    cnt[s[i]]++;
  }
  for (ll i = 1; i < alphabet; i++) {
    cnt[i] += cnt[i - 1];
  }
  for (ll i = 0; i < n; i++) {
    p[--cnt[s[i]]] = i;
  }
  c[p[0]] = 0;
  ll classes = 1;
  for (ll i = 1; i < n; i++) {
    if (s[p[i]] != s[p[i - 1]]) {
      classes++;
    }
    c[p[i]] = classes - 1;
  }
  vector<ll> pn(n), cn(n);
  for (ll h = 0; (1 << h) < n; ++h) {
    for (ll i = 0; i < n; i++) {
      pn[i] = p[i] - (1 << h);
      if (pn[i] < 0) {
        pn[i] += n;
      }
    }
    fill(cnt.begin(), cnt.begin() + classes, 0);
    for (ll i = 0; i < n; i++) {
      cnt[c[pn[i]]]++;
    }
    for (ll i = 1; i < classes; i++) {
      cnt[i] += cnt[i - 1];
    }
    for (ll i = n-1; i >= 0; i--) {
      p[--cnt[c[pn[i]]]] = pn[i];
    }
    cn[p[0]] = 0;
    classes = 1;
    for (ll i = 1; i < n; i++) {
      pair<ll, ll> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
      pair<ll, ll> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << h)) % n]};
      if (cur != prev) {
        ++classes;
      }
      cn[p[i]] = classes - 1;
    }
    c.swap(cn);
  }
  return p;
}
vector<ll> build_suff_arr(string s) {
  s += (char) 0;
  vector<ll> sorted_shifts = sort_cyclic_shifts(s);
  sorted_shifts.erase(sorted_shifts.begin());
  return sorted_shifts;
}