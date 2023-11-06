#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n = 8;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; ++i) {
        if (arr[i] == 9) {
            cout << 'F' << '\n';
            return 0;
        }
    }
    cout << 'S' << '\n';
}
