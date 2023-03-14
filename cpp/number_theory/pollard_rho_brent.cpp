ll mult(ll a, ll b, ll mod) {
  return (__int128_t) a * b % mod;
}

ll f(ll x, ll c, ll mod) {
  return (mult(x, x, mod) + c) % mod;
}

ll pollard_rho_brent(ll n, ll x0 = 2, ll c = 1) {
  ll x = x0, g = 1, q = 1, xs, y, m = 128, l = 1;
  while (g == 1) {
    y = x;
    for (ll i = 1; i < l; i++) {
      x = f(x, c, n);
    }
    ll k = 0;
    while (k < l && g == 1) {
      xs = x;
      for (ll i = 0; i < m && i < l - k; i++) {
        x = f(x, c, n);
        q = mult(q, abs(y - x), n);
      }
      g = __gcd(q, n);
      k += m;
    }
    l *= 2;
  }
  if (g == n) {
    do {
      xs = f(xs, c, n);
      g = __gcd(abs(xs - y), n);
    } while (g == 1);
  }
  return g;
}