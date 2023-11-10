#include <bits/stdc++.h>
using namespace std;

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    map<string, pair<int, int>> f;
    vector<string> arr(12);
    arr[0] = "Aries";
    arr[1] = "Taurus";
    arr[2] = "Gemini";
    arr[3] = "Cancer";
    arr[4] = "Leo";
    arr[5] = "Virgo";
    arr[6] = "Libra";
    arr[7] = "Scorpio";
    arr[8] = "Sagittarius";
    arr[9] = "Capricorn";
    arr[10] = "Aquarius";
    arr[11] = "Pisces";
    f["mar"] = {21,0};
    f["apr"] = {21,1};
    f["may"] = {21,2};
    f["jun"] = {22,3};
    f["jul"] = {23,4};
    f["aug"] = {23,5};
    f["sep"] = {22,6};
    f["oct"] = {23,7};
    f["nov"] = {23,8};
    f["dec"] = {22,9};
    f["jan"] = {21,10};
    f["feb"] = {20,11};
    int t;
    cin >> t;
    while (t--) {
        int d;
        string m;
        cin >> d >> m;
        transform(m.begin(), m.end(), m.begin(), ::tolower);
        if (f[m].first <= d) {
            cout << arr[f[m].second] << '\n';
        }
        else {
            cout << arr[(f[m].second - 1 + 12) % 12] << '\n';
        }
    }
    return 0;
}
