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

#define TESTS true

char rev(char c) {
  return (c == 'R' ? 'B' : 'R');
}

auto solve(int tc) {
  //   int n;
  //   cin >> n;

  //   string s;
  //   cin >> s;

  //   for (int i = 0; i < n; i++) {
  //     if (s[i] == '?') {
  //       if (i == 0) {
  //         if (s[1] == 'B' || s[1] == 'R')
  //           s[0] = rev(s[1]);
  //         else
  //           s[0] = 'B';
  //       } else if (i == n - 1) {
  //         if (s[n - 2] == 'B' || s[n - 2] == 'R')
  //           s[n - 1] = rev(s[n - 2]);
  //         else
  //           s[n - 1] = 'B';
  //       } else {
  //         if (s[i + 1] == '?') {
  //           s[i] = rev(s[i - 1]);
  //         } else if (s[i + 1] != s[i - 1]) {
  //           s[i] = 'R';
  //         } else if (s[i + 1] == s[i - 1]) {
  //           s[i] = rev(s[i + 1]);
  //         }
  //       }
  //     }
  //   }

  //   cout << s << endl;

  int n;
  cin >> n;

  string s;
  cin >> s;

  int index(0);
  while (index < n && s[index] == '?') {
    index++;
  }

  if (index == n) {
    s[--index] = 'B';
  }

  for (int i = index - 1; i >= 0; i--) {
    if (s[i] == '?')
      s[i] = rev(s[i + 1]);
  }

  for (int i = index + 1; i < n; i++) {
    if (s[i] == '?')
      s[i] = rev(s[i - 1]);
  }

  cout << s << endl;
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
