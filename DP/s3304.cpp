#include <iostream>
#include <algorithm>
using namespace std;
int d[1002][1002];
int tc;

int LCS(string& input, string& compare) {
	for (int i = 1; i <= compare.length(); i++) {
		for (int j = 1; j <= input.length(); j++) {
			if (compare[i - 1] == input[j - 1]) {
				d[i][j] = d[i - 1][j - 1] + 1;
			}
			else {
				d[i][j] = max(d[i - 1][j], d[i][j - 1]);
			}
		}
	}
	return d[compare.length()][input.length()];
}

//역추적
//string output;
//void backTracking(int m, int n) {
//	if (m == 0 || n == 0)return;
//	if (d[m][n] > d[m - 1][n - 1] && d[m][n] > d[m][n - 1] && d[m][n] > d[m - 1][n]) {
//		// 문자열 인덱스는 d 인덱스보다 1씩 더 작다.
//		output = input[n - 1] + output;
//		backTracking(m - 1, n - 1);
//	}
//	else if (d[m][n] > d[m - 1][n] && d[m][n] == d[m][n - 1]) {
//		backTracking(m, n - 1);
//	}
//	else {
//		backTracking(m - 1, n);
//	}
//}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		string s1, s2;
		cin >> s1;
		cin >> s2;
		for (int i = 0; i < 1002; i++)fill(d[i], d[i] + 1002, 0);
		cout << "#" << t << ' ' << LCS(s1, s2) << '\n';

	}
}