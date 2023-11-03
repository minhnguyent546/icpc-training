#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].first >> arr[i].second;
    }
    long long res = 0;
    map<int, int> mp;
    for (auto [x, y] : arr) {
        res += mp[x];
        mp[x]++;
    }
    mp.clear();
    for (auto [x, y] : arr) {
        res += mp[y];
        mp[y]++;
    }
    map<pair<int, int>, int> mp_p;
    for (auto &p : arr) {
        res -= mp_p[p];
        mp_p[p]++;
    }
    cout << res << '\n';
    return 0;
}
