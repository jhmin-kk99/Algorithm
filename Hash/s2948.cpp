#include<iostream>
#include<algorithm>
#include<unordered_set>
using namespace std;
int tc;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		int n, m;
		cin >> n >> m;
		unordered_set<string> st;
		for (int i = 0; i < n + m; i++) {
			string s;
			cin >> s;
			st.insert(s);
		}
		int ans = n + m - st.size();
		cout << "#" << t << " " << ans << '\n';
	}
	return 0;
}
