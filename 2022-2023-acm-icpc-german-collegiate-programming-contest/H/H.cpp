/**        
 * author  CTU.NegativeZero
 **/       
#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;

const char minchar = 'a';
const int ALPHABET = 26;
string chars = "abcdefghijklmnopqrstuvwxyz";

struct Segment {
    int l, r;
    set<int> indices;
};

inline set<int> ask(vector<array<int, 2>> idxs) {
    string s = "";
    for (auto &[l, r] : idxs) {
        s += chars.substr(l, r - l + 1);
    }
    cout << '?' << ' ' << s << endl;
    int n;
    cin >> n;
    vector<int> indices(n);
    for (int i = 0; i < n; ++i) {
        cin >> indices[i];
        --indices[i];
    }
    return set<int>(indices.begin(), indices.end());
}

#ifndef LOCAL
#define cerr if (false) cerr
#endif

int main() {
    auto tmp = ask({{0, ALPHABET - 1}});
    int n = (int) tmp.size();
    vector<Segment> segments = {Segment{0, ALPHABET - 1, set<int>(tmp.begin(), tmp.end())}};
    string ans(n, '@');
    while (true) {
        vector<Segment> new_segments;
        bool any = false;
        vector<array<int, 2>> idxs;
        for (auto &segment : segments) {
            int l = segment.l, r = segment.r;
            auto indices = segment.indices;
            if (l == r) {
                for (auto &idx : segment.indices) {
                    ans[idx] = (char) (l + minchar);
                }
                continue;
            }
            any = true;
            int mid = (l + r) >> 1;
            idxs.push_back({l, mid});
        }
        if (!any) break;
        auto result = ask(idxs);
        for (auto &segment: segments) {
            int l = segment.l, r = segment.r;
            if (l == r) continue;
            set<int> left;
            for (auto &v : segment.indices) {
                if (result.count(v)) {
                    left.insert(v);
                }
            }
            for (auto &v : left) {
                if (segment.indices.count(v)) {
                    segment.indices.erase(v);
                }
            }
            int mid = (l + r) >> 1;
            new_segments.push_back({l, mid, left});
            new_segments.push_back({mid + 1, r, segment.indices});
        }
        segments.swap(new_segments);
    }
    cout << "! " << ans << '\n';
    string answer;
    cin >> answer;
    assert(answer == "correct");

	return 0;
}
