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
#define print_arr(arr) for(auto &it: arr) {cout << it;cout<<' ';} cout << '\n';
#define read_set(st, n) while(n--){int temp;cin>>temp;st.insert(temp);}
#define max_heap(type) priority_queue<type>
#define min_heap(type) priority_queue<type, vector<type>, ::greater<type>>
#define pii pair<int, int>
#define f first
#define s second
// clang-format on

#define TESTS true

auto solve(int tc) {
  int n;
  cin >> n;

  vector<int> a(n);
  map<int, int> freq;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    freq[a[i] % 10]++;
  }

  for (int i = 0; i < 10; i++) {
    if (freq[i]) {
      for (int j = 0; j < 10; j++) {
        if (freq[j] - (i == j)) {
          for (int p = 0; p < 10; p++) {
            if ((freq[p] - (i == p) - (j == p)) && (p + i + j) % 10 == 3) {
              cout << "YES\n";
              return;
            }
          }
        }
      }
    }
  }

  cout << "NO\n";
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