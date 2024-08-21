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

int ans(vector<int> &a, int i = 0, int sum = 0) {
    int n = a.size();
    if (i == n) {
        if (sum == 0) return 0;
        else return 1e5;
    }

    int val = a[i], val2 = -a[i];
    if (val < 0) swap(val, val2);

    int plus = ans(a, i + 1, sum + val) + (a[i] < 0);
    int minus = ans(a, i+1, sum+val2) + (a[i]>0);

    return min(plus, minus);
}

auto solve(int tc) {
    int n;
    cin >> n;

    vector<int> nums(n);
    cin >> nums[0];
    for (int i = 1; i < n; ++i) {
        char o;
        cin >> o;
        cin >> nums[i];

        if (o == '-') nums[i] *= -1;
    }

    int res = ans(nums, 1, nums[0]);
    if (res > 20) cout << -1;
    else cout << res;
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
