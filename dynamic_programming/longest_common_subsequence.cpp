#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <typename T>
void print_vec(const vector<T>& vec) {
  if (!vec.empty()) {
    cout << vec[0];
  }
  for (ll i{1}; i < vec.size(); ++i) {
    cout << ' ' << vec[i];
  }
  cout << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, m;
  cin >> n >> m;
  vector<ll> vec1(n);
  for (ll& x : vec1) {
    cin >> x;
  }
  vector<ll> vec2(m);
  for (ll& x : vec2) {
    cin >> x;
  }
  vector dp(n + 1, vector<ll>(m + 1));
  for (ll i{1}; i <= n; ++i) {
    for (ll j{1}; j <= m; ++j) {
      if (vec1[i - 1] == vec2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  ll mx{};
  ll i0{};
  ll j0{};
  for (ll i{1}; i <= n; ++i) {
    for (ll j{1}; j <= m; ++j) {
      if (mx < dp[i][j]) {
        mx = dp[i][j];
        i0 = i;
        j0 = j;
      }
    }
  }
  vector<ll> ans;
  ans.reserve(mx);
  while (i0 > 0 && j0 > 0) {
    if (dp[i0][j0] == dp[i0 - 1][j0]) {
      --i0;
    } else if (dp[i0][j0] == dp[i0][j0 - 1]) {
      --j0;
    } else {
      ans.push_back(vec1[i0 - 1]);
      --i0;
      --j0;
    }
  }
  reverse(ans.begin(), ans.end());
  cout << mx << '\n';
  print_vec(ans);
}
