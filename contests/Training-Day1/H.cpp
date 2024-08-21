#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template<typename T>
using ordered_set =
        tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


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
    int n, k;
    cin >> n >> k;

    vector<int> a(n, 0);
    map<int, bool> done;
    int last = 0;
    for (int i = 0; i < n; ++i) {
        if (!done[i]) {
            a[i] = ++last;
            done[i] = true;
        }

        if (i + k < n && !done[i + k]) {
            a[i + k] = ++last;
            done[i + k] = true;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << a[i] << ' ';
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