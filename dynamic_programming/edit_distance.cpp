#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string str1, str2;
  cin >> str1 >> str2;
  vector dp(str1.size() + 1, vector<ll>(str2.size() + 1, LLONG_MAX));
  dp[0][0] = 0;
  for (ll i{1}; i <= str1.size(); ++i) {
    dp[i][0] = i;
  }
  for (ll i{1}; i <= str2.size(); ++i) {
    dp[0][i] = i;
  }
  for (ll i{1}; i <= str1.size(); ++i) {
    for (ll j{1}; j <= str2.size(); ++j) {
      if (str1[i - 1] == str2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1];
      } else {
        dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
      }
    }
  }
  cout << dp.back().back() << '\n';
}
