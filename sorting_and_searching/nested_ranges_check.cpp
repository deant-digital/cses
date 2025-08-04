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
  vector<array<ll, 3>> vec(n);
  for (ll i{}; i < n; ++i) {
    auto& [a, b, i0]{vec[i]};
    cin >> a >> b;
    i0 = i;
  }
  vector<bool> ans1(n);
  vector<bool> ans2(n);
  ll best;
  sort(vec.begin(), vec.end(),
       [](const array<ll, 3>& a, const array<ll, 3>& b) -> bool {
         if (a[0] != b[0]) {
           return a[0] > b[0];
         }
         return a[1] < b[1];
       });
  best = LLONG_MAX;
  for (auto [a, b, i] : vec) {
    if (b >= best) {
      ans1[i] = true;
    } else {
      best = b;
    }
  }
  reverse(vec.begin(), vec.end());
  best = LLONG_MIN;
  for (auto [a, b, i] : vec) {
    if (b <= best) {
      ans2[i] = true;
    } else {
      best = b;
    }
  }
  print_vec(ans1);
  print_vec(ans2);
}
