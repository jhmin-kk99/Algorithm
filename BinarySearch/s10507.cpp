#include <iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int tc;
int ans, n, p;
vector<int> study;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		vector<int>().swap(study);
		cin >> n >> p;
		ans = p + 1;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			study.push_back(x);
		}
		for (int i = 0; i < n; i++) {
			int st, en, mid;
			st = i;
			en = n - 1;
			while (st <= en) {
				mid = (st + en) / 2;
				int blank = study[mid] - study[i] + 1 - (mid - i + 1);
				if (blank <= p) {
					ans = max(ans, study[mid] - study[i] + 1 + p - blank);
					st = mid + 1;
				}
				else {
					en = mid - 1;
				}
			}
		}
		cout << "#" << t << " " << ans << '\n';

	}

}