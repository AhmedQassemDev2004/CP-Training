#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template<typename T>
using ordered_set =
        tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


// @formatter:off
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0);
#define int long long
#define double long double
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pii pair<int, int>
#define f first
#define s second
// @formatter:on

#define TESTS false

void ans(int p, int n) {
    if (p > n) {
        return;
    }

    for (int i = 1; i <= ((n * 2 - 1) - (p * 2 - 1)) / 2; ++i) {
        cout << ' ';
    }

    for (int j = 1; j <= p * 2 - 1; ++j) {
        cout << '*';
    }

    cout << '\n';

    ans(p + 1, n);
}

auto solve(int tc) {
    int n;
    cin >> n;

//    for (int i = 1; i <= n; ++i) {
//        for (int j = 1; j <= ((n * 2 - 1) - (i * 2 - 1)) / 2; ++j) {
//            cout << " ";
//        }
//
//        for (int j = 1; j <= i * 2 - 1; ++j) {
//            cout << '*';
//        }
//
//        cout << endl;
//    }

    ans(1, n);
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