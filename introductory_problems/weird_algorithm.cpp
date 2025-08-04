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
  ll n;
  cin >> n;
  vector<ll> ans{n};
  while (n > 1) {
    if (n % 2 == 0) {
      n /= 2;
    } else {
      n *= 3;
      ++n;
    }
    ans.push_back(n);
  }
  print_vec(ans);
}
