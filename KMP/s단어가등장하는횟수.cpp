#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int tc;

vector<int> failure(string& p) {
	vector<int> f(p.size());
	int j = 0;
	for (int i = 1; i < p.size(); i++) {
		while (j > 0 && p[i] != p[j]) j = f[j - 1];
		if (p[i] == p[j]) f[i] = ++j;
	}
	return f;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	for (int t = 1; t <= tc; t++) {

		string st;
		cin >> st;
		string pt;
		cin >> pt;
		//  kmp
		vector<int>f = failure(pt);
		int j = 0;
		int ans = 0;
		for (int i = 0; i < st.size(); i++)
		{
			while (j > 0 && st[i] != pt[j]) j = f[j - 1];
			if (st[i] == pt[j]) {
				if (j == pt.size() - 1) { //패턴찾음
					ans++;
					j = f[j];
				}
				else j++;
			}
		}
		cout << "#" << t << " " << ans << '\n';
	}
	return 0;
}