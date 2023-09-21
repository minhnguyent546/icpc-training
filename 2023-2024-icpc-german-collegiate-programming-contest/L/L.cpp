/**        
 * author  CTU.NegativeZero
 **/       
#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;

struct Vertex {
	int next[2];
	bool leaf;
	Vertex() {
		leaf = false;
		next[0] = next[1] = -1;
	}
};

struct Trie {
	vector<Vertex> tree;
	Trie() {
		tree.emplace_back();
	}
	void insert(const string &s) {
		int i = 0;
		for (const char &ch : s) {
			int j = (ch == '(' ? 0 : 1);
			if (tree[i].next[j] == -1) {
				tree[i].next[j] = tree.size();
				tree.emplace_back();
			}
			i = tree[i].next[j];
		}
		tree[i].leaf = true;
	}
	bool find(const string &s) {
		int i = 0;
		for (const char &ch : s) {
			int j = (ch == '(' ? 0 : 1);
			if (tree[i].next[j] == -1) {
				return false;
			}
			i = tree[i].next[j];
		}
		return tree[i].leaf;	
	}
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s;
    cin >> s;
    int n = (int) s.size();
    vector<array<int, 2>> segments;
    stack<array<int, 2>> st;
    for (int i = 0; i < n; ++i) {
    	char ch = s[i];
    	if (ch == '(') {
    		st.push({ch, i});
    	}
    	else {
    		auto top = st.top();
    		st.pop();
    		if (st.empty()) {
    			segments.push_back({top[1], i});
    		}
    	}
    }
    if ((int) segments.size() == 1) {
    	cout << "no\n";
    	return 0;
    }
    string first = s.substr(segments[0][0], segments[0][1] - segments[0][0] + 1);
    segments.erase(segments.begin());
    Trie tree;
    tree.insert(first);
    bool any = false;
    for (auto [l, r] : segments) {
    	string cur = s.substr(l, r - l + 1);
    	if (!tree.find(cur)) {
    		any = true;
    		break;
    	}
    	tree.insert(cur);
    }
    if (!any) {
    	cout << "no\n";
    	return 0;
    }
    string ans = s.substr(segments[0][0]);
    cout << ans + first << '\n';
	return 0;
}
