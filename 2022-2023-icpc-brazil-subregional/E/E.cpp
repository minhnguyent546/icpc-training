#include <bits/stdc++.h>

using namespace std;

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
    multiset<int> s;
    for (int i = 0; i < n; ++i) {
        auto it = s.find(arr[i]);
        if (it != s.end()) {
            s.erase(it);
        }
        s.insert(arr[i] - 1);
    }
    cout << s.size() << '\n';
    return 0;
}
