#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const array<ll, 8> dx{-2, -2, -1, -1, 1, 1, 2, 2};
const array<ll, 8> dy{-1, 1, -2, 2, -2, 2, -1, 1};
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
  vector ans(n, vector<ll>(n, LLONG_MAX));
  ans[0][0] = 0;
  queue<array<ll, 2>> q;
  q.push({0, 0});
  while (!q.empty()) {
    auto [x, y]{q.front()};
    q.pop();
    for (ll i{}; i < 8; ++i) {
      ll nx{x + dx[i]};
      ll ny{y + dy[i]};
      if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
        continue;
      }
      if (ans[nx][ny] <= ans[x][y] + 1) {
        continue;
      }
      ans[nx][ny] = ans[x][y] + 1;
      q.push({nx, ny});
    }
  }
  for (auto& row : ans) {
    print_vec(row);
  }
}
