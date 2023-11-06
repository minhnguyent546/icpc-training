#include <bits/stdc++.h>

using namespace std;

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;

const char minchar = 'a';
const int ALPHABET = 26;

struct Vertex {
    int next[ALPHABET];
    int cnt;
    Vertex() {
        cnt = 0;
        fill(next, next + ALPHABET, -1);
    }
};

struct Trie {
    vector<Vertex> trie;
    Trie() {
        trie.emplace_back();
    }
    void insert(const string &s) {
        int i = 0;
        for (const char &ch : s) {
            int j = ch - minchar;
            if (trie[i].next[j] == -1) {
                trie[i].next[j] = trie.size();
                trie.emplace_back();
            }
            i = trie[i].next[j];
        }
        trie[i].cnt++;
    }
    int find(const string &s) {
        int i = 0;
        for (const char &ch : s) {
            int j = ch - minchar;
            if (trie[i].next[j] == -1) {
                return 0;
            }
            i = trie[i].next[j];
        }
        return trie[i].cnt;
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, sz;
    cin >> n >> sz;
    Trie trie;
    vector<string> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; ++i) {
        int lost = arr[i].find('*');
        string cur = arr[i];
        assert(lost != string::npos);
        for (int ch = 0; ch < ALPHABET; ++ch) {
            cur[lost] = (char) (ch + minchar);
            trie.insert(cur);
        }
    }
    string ans = "";
    int f = 0;
    for (int i = 0; i < n; ++i) {
        int lost = arr[i].find('*');
        string cur = arr[i];
        assert(lost != string::npos);
        for (int ch = 0; ch < ALPHABET; ++ch) {
            cur[lost] = (char) (ch + minchar);
            int cur_f = trie.find(cur);
            if (cur_f > f) {
                f = cur_f;
                ans = cur;
            }
            else if (cur_f == f && (ans == "" || cur < ans)) {
                ans = cur;
            }
        }
    }
    cout << ans << ' ' << f << '\n';
    return 0;
}
