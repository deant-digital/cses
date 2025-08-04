#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string str;
  cin >> str;
  ll best{1};
  ll cur{1};
  for (ll i{1}; i < str.size(); ++i) {
    if (str[i] == str[i - 1]) {
      ++cur;
      if (best < cur) {
        best = cur;
      }
    } else {
      cur = 1;
    }
  }
  cout << best << '\n';
}
