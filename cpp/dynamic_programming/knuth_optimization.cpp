ll solve() {
  ll N;
  // read N and input
  vector<vector<ll>> dp(N, vector<ll>(N)), opt(N, vector<ll>(N));
  auto C = [&](ll i, ll j) {
    // Implement cost function C.
  };
  for (ll i = 0; i < N; i++) {
    opt[i][i] = i;
    ... // Initialize dp[i][i] according to the problem
  }
  for (ll i = N - 2; i >= 0; i--) {
    for (ll j = i + 1; j < N; j++) {
      ll mn = ll_MAX, cost = C(i, j);
      for (ll k = opt[i][j - 1]; k <= min(j - 1, opt[i + 1][j]); k++) {
        if (mn >= dp[i][k] + dp[k + 1][j] + cost) {
          opt[i][j] = k; 
          mn = dp[i][k] + dp[k + 1][j] + cost; 
        }
      }
      dp[i][j] = mn; 
    }
  }
  cout << dp[0][N - 1] << '\n';
}