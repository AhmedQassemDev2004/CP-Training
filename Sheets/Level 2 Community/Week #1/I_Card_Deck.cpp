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
#define read_arr(arr, n) for(int i=0;i<n;i++) cin>>arr[i];
#define print_arr(arr,n) for(int i=0;i<n;i++) {cout << arr[i];cout<<' ';} cout << '\n';
#define read_set(st, n) while(n--){int temp;cin>>temp;st.insert(temp);}
#define max_heap priority_queue<int>
#define min_heap(type) priority_queue<type, vector<type>, ::greater<type>>
#define pii pair<int, int>
#define f first
#define s second
// clang-format on

#define TESTS true

auto solve(int tc) {
  // int n;
  // cin >> n;

  // vector<int> p(n);
  // set<int, greater<int>> st;

  // for (int i = 0; i < n; i++) {
  //   cin >> p[i];
  //   st.insert(p[i]);
  // }

  // vector<int> res;
  // while (!st.empty() && res.size() < n) {
  //   bool flag = false;
  //   for (int i = 0; i < n; i++) {
  //     if (p[i] == *st.begin()) {
  //       flag = true;
  //       res.push_back(p[i]);
  //       st.erase(*st.begin());
  //     } else if (flag && st.count(p[i])) {
  //       res.push_back(p[i]);
  //       st.erase(p[i]);
  //     }
  //   }
  // }

  // print_arr(res, n);

  int n;
  cin >> n;

  vector<int> p(n);
  read_arr(p, n);

  vector<int> pref_max(n);
  pref_max[0] = p[0];
  for (int i = 1; i < n; i++) {
    pref_max[i] = max(pref_max[i - 1], p[i]);
  }

  // print_arr(pref_max, n);

  stack<int> stack;
  int prev_pref;
  for (int i = n - 1; i >= 0; i--) {
    if (i == n - 1) {
      prev_pref = pref_max[i];
      stack.push(p[i]);
    } else {
      if (pref_max[i] == prev_pref) {
        stack.push(p[i]);
      } else {
        while (!stack.empty()) {
          cout << stack.top() << ' ';
          stack.pop();
        }

        stack.push(p[i]);
        prev_pref = pref_max[i];
      }
    }
  }

  while (!stack.empty()) {
    cout << stack.top() << ' ';
    stack.pop();
  }

  cout << '\n';
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