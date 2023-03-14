ll knapsack(ll W, vector<ll> &wt, vector<ll> &val, ll n) {
  vector<ll> dp(W + 1, 0);
  for (ll i = 1; i <= n; i++) {
    for (ll w = W; w >= 0; w--) {
      if (wt[i - 1] <= w) {
        dp[w] = max(dp[w], dp[w - wt[i - 1]] + val[i - 1]);
      }
    }
  }
  return dp[W];
}