#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int tc;
string dic[405] = { "" };
string solve(string& s, int idx) {
	fill(dic, dic + 405, "");
	string ans = "";
	for (int i = 0; i < s.length(); i++) {
		for (int j = 0; j <= i; j++) {
			dic[j] += s[i];
		}
	}
	sort(dic, dic + s.length());
	ans += dic[idx];
	if (ans == "") return "none";
	return ans;
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