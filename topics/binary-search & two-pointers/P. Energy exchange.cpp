#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0);
#define int long long

#define TESTS false

auto solve(int tc) {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    auto can = [&](double mid) {
        double have = 0, need = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] > mid) {
                double x = arr[i] - mid;
                have += ((x * (100 - k)) / 100.0);
            } else {
                need += (mid - arr[i]);
            }
        }
        return (have >= need);
    };

    double l = 0, r = *max_element(arr.begin(), arr.end()), ans = 0;

    while (r - l > 1e-9) {
        double mid = l + (r - l) / 2;
        if (can(mid)) {
            ans = mid;
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << fixed << setprecision(9) << ans << endl;
}

signed main() {
    FAST_IO

#if TESTS
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve(i + 1);
    }
#else
    solve(1);
#endif

    return 0;
}
