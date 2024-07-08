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

  string s;
  cin >> s;

  int first_a = -1;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'A') {
      first_a = i;
      break;
    }
  }

  if (first_a == -1 || first_a == n - 1) {
    cout << 0 << endl;
    return;
  }

  int max_p_sequence = 0, current = 0;
  for (int i = first_a; i < n; i++) {
    if (s[i] == 'P') {
      current++;
      max_p_sequence = max(current, max_p_sequence);
    } else {
      current = 0;
    }
  }

  cout << max_p_sequence << endl;
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