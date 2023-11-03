/**        
 * author  CTU.NegativeZero
 **/       
#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = (int) 1e9 + 7;
const long double eps = 1e-8;
const long double INF = 1.0 / 0;

struct Point {
    long double x, y;
};

long long kc(Point a, Point b) {
    auto [xa, ya] = a;
    auto [xb, yb] = b;
    return 1LL * (xa - xb) * (xa - xb) + 1LL * (ya - yb) * (ya - yb);
}

vector<Point> a;
vector<vector<pair<int, long double>>> adj;
vector<long double> dist;
vector<bool> mark;

void DT(int s, int t) {
    priority_queue<pair<long double, int>, vector<pair<long double,int>>, greater<>> q;
    q.push({0, s});
    dist[s] = 0;
    while(!q.empty()) {
        auto [w, u] = q.top();
        q.pop();
        if(mark[u])
            continue;
        mark[u] = true;
        for(auto [v, wv] : adj[u]) {
            if(dist[v] + eps > dist[u] + wv) {
                dist[v] = dist[u] + wv;
                q.push({dist[v], v});
            }
        }
    }
    cout << dist[t] << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout.precision(20);
    cout << fixed;
    int n, s, t;
    cin >> n;
    for(int i = 0; i < n; i++) {
        long double x, y;
        cin >> x >> y;
        a.push_back({x, y});
    }
    long double xs, ys, xt, yt, v1, v2;
    cin >> xs >> ys >> xt >> yt >> v1 >> v2;
    a.push_back({xs, ys});
    a.push_back({xt, yt});
    n += 2;
    s = n - 2, t = n - 1;
    adj.resize(n);
    dist.assign(n, INF);
    mark.resize(n);
    for(int i = 0; i < n; i++) {
        long double w = sqrt((long double) kc(a[i], a[s])) / v1;
        adj[s].push_back({i, w});
    }
    long long stt = 9LL * v2 * v2;
    for(int i = 0; i < n - 2; i++) {
        for(int j = 0; j < n; j++) {
            long long d = kc(a[i], a[j]);
            if(stt + eps >= d) {
                long double w = sqrt((long double) d) / v2;
                adj[i].push_back({j, w});
            } else {
                long double w = 3 + (sqrt((long double) d) - stt) / v1;
                adj[i].push_back({j, w});
            }
        }
    }
    DT(s, t);
    return 0;
}
