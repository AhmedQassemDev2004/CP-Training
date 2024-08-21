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

int bs(int l, int r, int target, vector<int> &a) {
    int mid = ((l + r) / 2);

    if (l > r) {
        return -1;
    }

    if (a[mid] == target) {
        return mid;
    }

    if (a[mid] > target) {
        return bs(l, mid - 1, target, a);
    } else {
        return bs(mid + 1, r, target, a);
    }
}

auto solve(int tc) {
    int n, p;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int q;
    cin >> q;

    while (q--) {
        cin >> p;

        int ans = bs(0, n - 1, p, a);
        if (ans != -1) ans++;
        cout << ans << '\n';
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