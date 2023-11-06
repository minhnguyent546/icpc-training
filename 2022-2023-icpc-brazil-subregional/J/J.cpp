#include <bits/stdc++.h>

using namespace std;

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin >> n;
    int score1 = 0, score2 = 0;
    int x;
    vector<int> a(14);
    cin >> x; score1 += min(x, 10); a[x]++;
    cin >> x; score1 += min(x, 10); a[x]++;
    cin >> x; score2 += min(x, 10); a[x]++;
    cin >> x; score2 += min(x, 10); a[x]++;

    for (int i = 0; i < n; i++)
        cin >> x, a[x]++, score1 += min(x, 10), score2 += min(x, 10);

    for (int i = 1; i <= 13; i++) {
        if (a[i] + 1 > 4) continue;
        int add = (i >= 10) ? 10 : i;
        if ((score2 + add == 23) || (score1 + add > 23 && score2 + add <= 23))
            return !(cout << i);
    }

    cout << -1;

    return 0;
}
