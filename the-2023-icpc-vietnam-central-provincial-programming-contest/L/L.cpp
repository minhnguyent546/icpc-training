#include <bits/stdc++.h>

using namespace std;

const int MOD = (int) 1e9 + 7;
const int INF = 0x3f3f3f3f;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	set<string> s;
	s.insert("Welcome");
	s.insert("Hue");
	s.insert("University");
	s.insert("of");
	s.insert("Sciences");
	string t;
	while (getline(cin, t)) {
		int n = (int) t.size();
		for (int i = 0; i < n; ++i) {
			if (t[i] == ' ') continue;
			string cur = "";
			int j = i;
			while (j < n && t[j] != ' ') cur += t[j++];
			if (s.count(cur)) s.erase(cur);
		}
	}
	cout << (s.empty() ? "Yes" : "No") << '\n';
	return 0;
}