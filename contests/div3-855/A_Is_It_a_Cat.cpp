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
string next_str(){string x;cin>>x;return x;}
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

char f(char c) {
  return (char(tolower(c)));
}

auto solve(int tc) {
  int n = next();

  string s = next_str();

  if (n < 4) {
    cout << "NO\n";
    return;
  }

  string base = "meow";
  for (int i = 1; i < n; i++) {
    if (f(s[i]) == f(s[i - 1])) {
      s[i - 1] = '-';
    }
  }

  int i = 0;
  for (char c : s) {
    if (c != '-') {
      if (f(c) == base[i] && i < 4) {
        i++;
      } else {
        cout << "NO\n";
        return;
      }
    }
  }

  cout << (i > 3 ? "YES" : "NO") << endl;
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