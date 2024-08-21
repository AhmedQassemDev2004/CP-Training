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

#define TESTS false

auto solve(int tc) {
    int n, m;
    cin>>n>>m;

    vector<vector<char>> a(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin>>a[i][j];
        }
    }

    int count=0;
    for (int i = 0; i < n; ++i) {
        bool found=false;
        for (int j = 0; j < m; ++j) {
            if(!found && a[i][j]=='|') {
                found=true;
                continue;
            }

            if(found) {
                count+=(a[i][j]=='.');
            }

            if(a[i][j]=='|' && found) {
                found=false;
                break;
            }
        }
    }

    cout << count;
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