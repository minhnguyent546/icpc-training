#include <bits/stdc++.h>
using namespace std;

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;

const int n = 10;
vector<string> a(n);
vector<vector<bool>> used(n, vector<bool>(n, false)), vis(n, vector<bool>(n, false));
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void dfs(int u1, int u2, bool &flag) {
    if(used[u1][u2] == true) {
        flag = true;
    }
    vis[u1][u2] = true;
    for(int t = 0; t < 4; t++) {
        int v1 = u1 + dx[t], v2 = u2 + dy[t];
        if(v1 >= 0 && v1 < n && v2 >= 0 && v2 < n && a[v1][v2] == '#' && vis[v1][v2] == false) {
            dfs(v1, v2, flag);
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int q;
    cin >> q;
    string show = "SHOW", shot = "SHOT";
    int un = 0, hit = 0, sunk = 0;
    while(q--) {
        string type;
        cin >> type;
        if(type == shot) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            used[u][v] = true;
        } else {
            vis.assign(n, vector<bool>(n, false));
            un = 0, hit = 0, sunk = 0;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(a[i][j] == '#' && used[i][j] == false && !vis[i][j]) {
                        bool flag = false;
                        dfs(i, j, flag);
                        if(flag) {
                            hit++;
                        } else {
                            un++;
                        }
                    }
                }
            }
            sunk = 10 - un - hit;
            cout << un << ' ' << hit << ' ' << sunk << '\n';
        }
    }
    return 0;
}
