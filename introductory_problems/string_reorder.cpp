#include <bits/stdc++.h>
using namespace std;
using ll = long long;
array<ll, 26> cnt{};
bool is_possible(ll len) {
  return *max_element(cnt.begin(), cnt.end()) <= (len + 1) / 2;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string str;
  cin >> str;
  for (char c : str) {
    ll i{c - 'A'};
    ++cnt[i];
  }
  string ans(str.size(), 0);
  for (ll i{}; i < str.size(); ++i) {
    bool bl{true};
    for (ll j{}; j < 26; ++j) {
      if (cnt[j] == 0) {
        continue;
      }
      char c(j + 'A');
      if (i > 0 && c == ans[i - 1]) {
        continue;
      }
      --cnt[j];
      if (!is_possible(str.size() - i - 1)) {
        ++cnt[j];
        continue;
      }
      ans[i] = c;
      bl = false;
      break;
    }
    if (bl) {
      cout << -1 << '\n';
      return 0;
    }
  }
  cout << ans << '\n';
}
