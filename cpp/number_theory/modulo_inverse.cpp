ll mod_inv(ll a, ll m) {
  if (m == 1) {
    return 0;
  }
  ll m0 = m, x = 1, y = 0;
  while (a > 1) {
    ll q = a / m, t = m;
    m = a % m;
    a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) {
    x += m0;
  }
  return x;
}