ll LCS(string x, string y, ll n, ll m) {
  vector<vector<ll>> dp(n + 1, vector<ll>(m + 1));
  for (ll i = 0; i <= n; i++) {
    for (ll j = 0; j <= m; j++) {
      if (i == 0 || j == 0) {
        dp[i][j] = 0;
      } else if (x[i - 1] == y[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  ll index = dp[n][m];
  vector<char> lcs(index + 1);
  lcs[index] = '\0';
  ll i = n, j = m;
  while (i > 0 && j > 0) {
    if (x[i - 1] == y[j - 1]) {
      lcs[index - 1] = x[i - 1];
      i--;
      j--;
      index--;
    } else if (dp[i - 1][j] > dp[i][j - 1]) {
      i--;
    } else {
      j--;
    }
  }
  return dp[n][m];
}