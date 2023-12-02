#include<bits/stdc++.h>
using namespace std;

#define int long long

int distance(pair<int, int> &p, int a, int b, int c) {
    return abs(a * p.first + b * p.second + c);
}

void solve() {
    int a, b, c1, c2; cin >> a >> b >> c1 >> c2;

    int k; cin >> k;
    vector<pair<int, int>> points(k);
    vector<int> d1(k), d2(k);
    for (int i = 0; i < k; i++)
        cin >> points[i].first >> points[i].second;

    c1 = -c1; c2 = -c2;
    int d = abs(c1 - c2);
    bool in1 = false, in2 = false, out1 = false, out2 = false, in12 = false;
    for (int i = 0; i < k; i++) {
        d1[i] = distance(points[i], a, b, c1);
        d2[i] = distance(points[i], a, b, c2);

        if (d1[i] == 0) in1 = true;
        if (d2[i] == 0) in2 = true;
        if (d1[i] != 0 && d2[i] != 0 && d1[i] + d2[i] == d) in12 = true;
        if (d2[i] != 0 && d1[i] == d2[i] + d) out2 = true;
        if (d1[i] != 0 && d2[i] == d1[i] + d) out1 = true;
    }

    if (in12 || (in1 && in2) || (out1 && out2) || (in1 && out2) || (in2 && out1))
        cout << "YES\n";
    else cout << "NO\n";
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int tt; cin >> tt;
    while (tt--) solve();
}
