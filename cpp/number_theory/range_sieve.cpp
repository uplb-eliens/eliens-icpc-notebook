vector<bool> range_sieve(ll l, ll r) {
  ll n = sqrt(r);
  vector<bool> is_prime(n + 1, true);
  vector<ll> prime;
  is_prime[0] = is_prime[1] = false;
  prime.push_back(2);
  for (ll i = 4; i <= n; i += 2) {
    is_prime[i] = false;
  }
  for (ll i = 3; i <= n; i += 2) {
    if (is_prime[i]) {
      prime.push_back(i);
      for (ll j = i * i; j <= n; j += i) {
        is_prime[j] = false;
      }
    }
  }
  vector<bool> result(r - l + 1, true);
  for (ll i : prime) {
    for (ll j = max(i * i, (l + i - 1) / i * i); j <= r; j += i) {
      result[j - l] = false;
    }
  }
  if (l == 1) {
    result[0] = false;
  }
  return result;
}