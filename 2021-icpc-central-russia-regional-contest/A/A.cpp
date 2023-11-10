#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        cin >> grid[0][i];
        --grid[0][i];
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            grid[i][j] = (grid[i - 1][j] + 1) % n;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << grid[i][j] + 1 << " \n"[j == n - 1];
        }
    }
    return 0;
}
