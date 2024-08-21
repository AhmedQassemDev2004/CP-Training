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

//
//bool cmp(pii p1, pii p2) {
//    if (p1.s == p2.s) return p1.f < p2.f;
//    return p1.s < p2.s;
//}


auto solve(int tc) {
//    int n, k;
//    cin >> n >> k;
//
//    vector <pii> a(k);
//    for (auto &it: a) cin >> it.f >> it.s;
//
//    sort(all(a), cmp);
//
//    int count = 0, last = 0;
//    for (auto it: a) {
//        if (it.f >= last) {
//            last = it.s;
//            count++;
//        }
//    }
//
//    cout << count;

    int n, k;
    cin >> n >> k;

    vector<int> idx[n + 1];
    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        idx[x].push_back(y);
    }

    vector<int> dp(n + 1, -1);

    function<int(int)> rec = [&](int i = 1) {
        if (i > n) return 0ll;

        if (dp[i] != -1) return dp[i];

        dp[i] = rec(i + 1);
        for (auto it: idx[i]) {
            dp[i] = max(dp[i], rec(it) + 1);
        }

        return dp[i];
    };

    cout << endl;

    cout << rec(1);
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