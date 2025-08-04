#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const array<ll, 4> dx{-1, 0, 0, 1};
const array<ll, 4> dy{0, -1, 1, 0};

string str;
array<array<bool, 7>, 7> mat{};

bool is_avail(ll x, ll y) {
  return x >= 0 && y >= 0 && x < 7 && y < 7 && !mat[x][y];
}

ll solve(ll idx, ll x, ll y) {
  if (x == 6 && y == 0) {
    return idx == 48 ? 1 : 0;
  }
  if ((is_avail(x - 1, y) && is_avail(x + 1, y)) &&
      (!is_avail(x, y - 1) && !is_avail(x, y + 1))) {
    return 0;
  }
  if ((!is_avail(x - 1, y) && !is_avail(x + 1, y)) &&
      (is_avail(x, y - 1) && is_avail(x, y + 1))) {
    return 0;
  }
  if (48 - idx < (6 - x) + (y - 0)) {
    return 0;
  }
  char c{str[idx]};
  if (c == '?') {
    ll res{};
    for (ll i{}; i < 4; ++i) {
      ll nx{x + dx[i]};
      ll ny{y + dy[i]};
      if (!is_avail(nx, ny)) {
        continue;
      }
      mat[nx][ny] = true;
      res += solve(idx + 1, nx, ny);
      mat[nx][ny] = false;
    }
    return res;
  }
  ll i;
  switch (c) {
    case 'U':
      i = 0;
      break;
    case 'L':
      i = 1;
      break;
    case 'R':
      i = 2;
      break;
    case 'D':
      i = 3;
  }
  ll nx{x + dx[i]};
  ll ny{y + dy[i]};
  if (!is_avail(nx, ny)) {
    return 0;
  }
  mat[nx][ny] = true;
  ll res{solve(idx + 1, nx, ny)};
  mat[nx][ny] = false;
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> str;
  mat[0][0] = true;
  cout << solve(0, 0, 0) << '\n';
}
