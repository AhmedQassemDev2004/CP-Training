#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template<typename T>
using ordered_set =
        tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// @formatter:off
int next() {int x;cin >> x;return x;}
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0);
#define int long long
#define double long double
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define read_arr(arr) for(auto &it: arr) cin>>it;
#define pii pair<int, int>
#define f first
#define s second
// @formatter:on

#define TESTS true

auto solve(int tc) {
    // VALID FOR HARD VERSION TOO
    int n = next();

    vector<int> a(n);
    read_arr(a);

    priority_queue<int> pq;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0 && !pq.empty()) {
            res += pq.top();
            pq.pop();
        } else {
            pq.push(a[i]);
        }
    }

    cout << res << endl;
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