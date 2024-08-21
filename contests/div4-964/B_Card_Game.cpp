#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(0);
#define int long long
#define double long double
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pii pair<int, int>
#define f first
#define s second

#define TESTS true

auto solve(int tc) {
  int a1, a2, b1, b2;
  cin >> a1 >> a2 >> b1 >> b2;

  int res = 0;

  int games[4][2][2] = {
      {{a1, a2}, {b1, b2}},
      {{a1, a2}, {b2, b1}},
      {{a2, a1}, {b1, b2}},
      {{a2, a1}, {b2, b1}}};

  for (int i = 0; i < 4; ++i) {
    int a_score = 0;
    int b_score = 0;

    if (games[i][0][0] > games[i][1][0])
      a_score++;
    else if (games[i][0][0] < games[i][1][0])
      b_score++;

    if (games[i][0][1] > games[i][1][1])
      a_score++;
    else if (games[i][0][1] < games[i][1][1])
      b_score++;

    if (a_score > b_score)
      res++;
  }

  cout << res << endl;
}

signed main() {
  FAST_IO

#if TESTS
  int t;
  cin >> t;
  for (int tc = 0; tc < t; tc++) {
    solve(tc + 1);
  }
#else
  solve(1);
#endif

  return 0;
}