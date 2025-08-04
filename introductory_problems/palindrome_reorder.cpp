#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string str;
  cin >> str;
  array<ll, 26> cnt{};
  for (char c : str) {
    ll i{c - 'A'};
    ++cnt[i];
  }
  string pre, mid;
  for (ll i{}; i < 26; ++i) {
    char c(i + 'A');
    pre += string(cnt[i] / 2, c);
    mid += string(cnt[i] % 2, c);
  }
  if (mid.size() > 1) {
    cout << "NO SOLUTION" << '\n';
    return 0;
  }
  string post{pre};
  reverse(post.begin(), post.end());
  cout << pre << mid << post << '\n';
}
