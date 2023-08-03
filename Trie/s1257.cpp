#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int tc;
vector<string> dic;
string solve(string& s, int idx) {
	dic.clear();
	for (int i = 0; i < s.length(); i++) {
		string tmp = "";
		for (int j = i; j < s.length(); j++) {
			tmp += s[j];
			dic.push_back(tmp);
		}
	}
	sort(dic.begin(), dic.end());
	dic.erase(unique(dic.begin(), dic.end()), dic.end());
	if (idx > dic.size()) return "none";
	return dic[idx];
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		int idx;
		cin >> idx;
		string s;
		cin >> s;
		cout << "#" << t << " " << solve(s, idx - 1) << '\n';
	}
}