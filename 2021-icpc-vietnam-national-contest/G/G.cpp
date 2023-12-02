#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MOD = (int) 1e9 + 7;

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        if (arr[i] == 1) arr[i] = 0;
    }
    sort(arr.begin(), arr.end());
    int a = accumulate(arr.begin(), arr.begin() + k, 0);
    int b = accumulate(arr.begin() + n - k, arr.end(), 0);
    cout << a << ' ' << b << '\n';

    return 0;
}