#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(0);
#define int long long
#define p(str) return (void)(cout << str << '\n');

bool is_winning(char c1, char c2, char c3, char p) {
  return (c1 == p && c2 == p && c3 == p);
}

bool check_winner(vector<string>& grid, char p) {
  for (int i = 0; i < 3; i++) {
    if (is_winning(grid[i][0], grid[i][1], grid[i][2], p))
      return true;
  }

  for (int i = 0; i < 3; i++) {
    if (is_winning(grid[0][i], grid[1][i], grid[2][i], p))
      return true;
  }

  if (is_winning(grid[0][0], grid[1][1], grid[2][2], p))
    return true;
  if (is_winning(grid[0][2], grid[1][1], grid[2][0], p))
    return true;

  return false;
}

void solve() {
  vector<string> grid(3);

  int x_count = 0, o_count = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> grid[i][j];
      if (grid[i][j] == 'X')
        x_count++;
      if (grid[i][j] == 'O')
        o_count++;
    }
  }

  if (!(x_count == o_count || x_count == o_count + 1))
    p("no");

  bool x_wins = check_winner(grid, 'X');
  bool o_wins = check_winner(grid, 'O');

  if (x_wins && o_wins)
    p("no");

  if (x_wins && x_count != o_count + 1)
    p("no");

  if (o_wins && x_count != o_count)
    p("no");

  p("yes");
}

signed main() {
  FAST_IO

  int t;
  cin >> t;

  while (t--) {
    solve();
  }
  return 0;
}