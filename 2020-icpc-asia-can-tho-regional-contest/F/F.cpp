#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MOD = (int) 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    vector<char> arr(n);
    for (int i =0 ; i < n; ++i) {
        cin >> arr[i];
    }
    int cnt = 0;
    for (int i = 1; i < n; ++i) {
        if (arr[i] == arr[i - 1]) ++cnt;
    }
    cout << cnt << '\n';
}