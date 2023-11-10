#include <bits/stdc++.h>
using namespace std;

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;

const int V = (int) 1e5;
int cnt[V + 3];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        cnt[arr[i]]++;
    }
    vector<long long> ans(k);
    for (int v = 0; v <= V; ++v) {
        int cur = v;
        while (cur < k) {
            ans[cur] += cnt[v];
            cur += v + 1;
        }
    }
    for (int i = 0; i < k; ++i) {
        cout << ans[i] << " \n"[i == k - 1];
    }
    return 0;
}
