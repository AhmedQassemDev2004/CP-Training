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
// #define int long long
#define double long double
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sort(a) sort(all(a))
int next(){int x;cin>>x;return x;}
#define read_arr(arr) for(auto &it: arr) cin>>it;
#define print_arr(arr) for(auto &it: arr) {cout << it;cout<<' ';} cout << '\n';
#define read_set(st, n) while(n--){int temp;cin>>temp;st.insert(temp);}
#define max_heap(type) priority_queue<type>
#define min_heap(type) priority_queue<type, vector<type>, ::greater<type>>
#define pii pair<int, int>
#define f first
#define s second
// clang-format on

#define TESTS false

int get_bit(int p, int i) {
  return (p >> i) & 1;
}

int set_bit(int p, int i) {
  return (p | (1 << i));
}

int reset_bit(int p, int i) {
  return (p & ~(1 << i));
}

int flip_bit(int p, int i) {
  return (p ^ (1 << i));
}

auto solve(int tc) {
  int n = next(), q = next();

  while (q--) {
    int op = next();
    if (op == 1) {
      for (int i = 0; i < 32; i++) {
        if (get_bit(n, i) == 0) {
          n = set_bit(n, i);
          break;
        }
      }
      cout << n << endl;
    } else if (op == 2) {
      for (int i = 0; i < 32; i++) {
        if (get_bit(n, i) == 1) {
          n = reset_bit(n, i);
          break;
        }
      }
      cout << n << endl;
    } else if (op == 3) {
      if (n == 0) {
        n = -1;
      } else {
        for (int i = 0; i < 32; i++) {
          if (get_bit(n, i) == 1) {
            break;
          }
          n = set_bit(n, i);
        }
      }
      cout << n << endl;
    } else if (op == 4) {
      for (int i = 0; i < 32; i++) {
        if (get_bit(n, i) == 0) {
          break;
        }
        n = reset_bit(n, i);
      }
      cout << n << endl;
    } else if (op == 5) {
      if (__builtin_popcount(n) == 1) {
        cout << "is power of two\n";
      } else {
        cout << "not power of two\n";
      }
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