#include <bits/stdc++.h>
#define ll long long
#define infInt (int)1e9 + 1
// #define infLL 0x3f3f3f3f3f3f
#define infLL (int)1e18
#define vt vector<int>
#define vtt vector<vt>
#define vttt vector<vtt>
#define vtttt vector<vttt>
#define pii pair<int, int>
#define vpii vector<pii>
#define endl '\n'
#define all(a) a.begin(), a.end()
#define _sort(a) sort(all(a))
#define bsUp(a, x) upper_bound(all(a), x) - a.begin()
#define bsLow(a, x) lower_bound(all(a), x) - a.begin()
#define rev(a) reverse(all(a))
#define uni(vals) vals.resize(distance(vals.begin(), unique(all(vals))))
// #define int ll
// #define in(a); ; 
// #define hi ;
// #include "/home/phamngocthi/cp/see.cpp"
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;
    cin >> n;
    vt a(n), b(n);
    for(int &x : a)
        cin >> x;
    for(int &x : b)
        cin >> x;
    priority_queue<int> q1, q2;
    for(int i = 0; i < n; i++) {
        q1.push(a[i]);
        q2.push(b[i]);
    }
    int cnt = 0;
    while(q1.size() && q2.size()) {
        int endA = q1.top(), endB = q2.top();
        if(endA == endB) {
            q1.pop();
            q2.pop();
            continue;
        }
        if(endA < endB) {
            if(endB & 1) {
                cout << -1;
                return 0;
            } else {
                q2.pop();
                q2.push(endB / 2);
                cnt++;
            }
        } else {
            q1.pop();
            q1.push(endA / 2);
            cnt++;
        }
    }
    cout << cnt;
}
