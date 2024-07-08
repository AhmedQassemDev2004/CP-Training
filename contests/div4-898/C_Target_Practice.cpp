#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// clang-format off
int next(){int x;cin>>x;return x;} 
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0);
#define int long long
#define double long double
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sort(a) sort(all(a))
#define read_arr(arr) for(auto &it: arr) cin>>it;
#define print_arr(arr) for(auto &it: arr) {cout << it;cout<<' ';} cout << '\n';
#define read_set(st, n) while(n--){int temp;cin>>temp;st.insert(temp);}
#define pii pair<int, int>
#define f first
#define s second
// clang-format on

#define TESTS true

int score[10][10] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 2, 2, 2, 2, 2, 2, 2, 2, 1},
    {1, 2, 3, 3, 3, 3, 3, 3, 2, 1},
    {1, 2, 3, 4, 4, 4, 4, 3, 2, 1},
    {1, 2, 3, 4, 5, 5, 4, 3, 2, 1},
    {1, 2, 3, 4, 5, 5, 4, 3, 2, 1},
    {1, 2, 3, 4, 4, 4, 4, 3, 2, 1},
    {1, 2, 3, 3, 3, 3, 3, 3, 2, 1},
    {1, 2, 2, 2, 2, 2, 2, 2, 2, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

auto solve(int tc) {
  vector<vector<char>> grid(11, vector<char>(11));

  for (int i = 1; i <= 10; i++) {
    for (int j = 1; j <= 10; j++) {
      cin >> grid[i][j];
    }
  }

  int res = 0;
  for (int i = 1; i <= 10; i++) {
    for (int j = 1; j <= 10; j++) {
      if (grid[i][j] == 'X') {
        res += score[i - 1][j - 1];
      }
    }
  }

  cout << res << '\n';
}

signed main() {
  FAST_IO

#if TESTS
  int t = next();
  for (int tc = 0; tc < t; tc++) {
    solve(tc + 1);
  }
#else
  solve(1);
#endif

  return 0;
}