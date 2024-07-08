#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// clang-format off
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0);
#define int long long
#define double long double
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sort(a) sort(all(a))
#define read_arr(arr) for(auto &it: arr) cin>>it;
#define print_arr(arr) for(auto &it: arr) {cout << *it;cout<<' ';} cout << '\n';
#define read_set(st, n) while(n--){int temp;cin>>temp;st.insert(temp);}
#define max_heap(type) priority_queue<type>
#define min_heap(type) priority_queue<type, vector<type>, ::greater<type>>
#define pii pair<int, int>
#define f first
#define s second
// clang-format on

#define TESTS false

void print(int up, int left, int right, int down) {
  for (int i = 0; i < up; i++) {
    cout << 'U';
  }
  for (int i = 0; i < left; i++) {
    cout << 'L';
  }
  for (int i = 0; i < right; i++) {
    cout << 'R';
  }
  for (int i = 0; i < down; i++) {
    cout << 'D';
  }
}

auto solve(int tc) {
  int n, m;
  cin >> n >> m;

  pii s_pos, f_pos;
  vector<vector<char>> grid(n, vector<char>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
      if (grid[i][j] == 'S')
        s_pos = make_pair(i, j);
      if (grid[i][j] == 'F')
        f_pos = make_pair(i, j);
    }
  }

  if (s_pos.f < f_pos.f) {
    int down = f_pos.f - s_pos.f;

    if (s_pos.s < f_pos.s) {
      int right = f_pos.s - s_pos.s;
      print(0, 0, right, down);
    } else {
      int left = s_pos.s - f_pos.s;
      print(0, left, 0, down);
    }
  } else {
    int up = s_pos.f - f_pos.f;

    if (s_pos.s < f_pos.s) {
      int right = f_pos.s - s_pos.s;
      print(up, 0, right, 0);
    } else {
      int left = s_pos.s - f_pos.s;
      print(up, left, 0, 0);
    }
  }
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