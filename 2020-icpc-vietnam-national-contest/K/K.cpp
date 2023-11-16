/**            
 * author      minhnguyent546
 * created_at  Sat, 2023-11-11 09:23:54
 **/           
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "cp/debug.h"
#else
#define debug(...)
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;

using Point = pair<int, int>;

long long double_area(Point a, Point b, Point c) {
    long long res = 1LL * a.first * (b.second - c.second) + 1LL * b.first * (c.second - a.second) + 1LL * c.first * (a.second - b.second);
    return abs(res);
}

bool inside(Point a, Point b, Point c, Point x) {
    return double_area(a, b, c) == double_area(x, a, b) + double_area(x, b, c) + double_area(x, c, a);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    while (cin >> n) {
        if (n == 0) break;
        vector<Point> arr(n);
        for (int i = 0; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            arr[i] = Point{x, y};
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    for (int l = k + 1; l < n; ++l) {
                        if (!inside(arr[i], arr[j], arr[k], arr[l]) &&
                            !inside(arr[i], arr[j], arr[l], arr[k]) &&
                            !inside(arr[i], arr[k], arr[l], arr[j]) &&
                            !inside(arr[j], arr[k], arr[l], arr[i])) {
                            ++res;
                        }
                    }
                }
            }
        }
        cout << res << '\n';
    }

    return 0;
}
