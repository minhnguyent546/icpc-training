/**        
 * author  CTU.NegativeZero
 **/       
#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];

    }
    long long sum = accumulate(arr.begin(), arr.end(), 0LL);
    int res = 0;
    sort(arr.begin(), arr.end(), greater<>());
    for (int i = 0, ptr = -1; i < n; ++i) {
        double cur = (double) sum / (n - i);
        while (ptr + 1 < n && arr[ptr + 1] > cur) {
            ++ptr;
        }
        res = max(res, ptr - i + 1);
        sum -= arr[i];
    }
    cout << res << '\n';
    return 0;
}
