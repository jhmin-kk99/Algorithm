#include<iostream>
#include<algorithm>
using namespace std;

#define mod 1000000007
typedef long long ll;
const int t = 1 << 4;
long long dp[10002][1 << 4]; //dp[day][활동여부]

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		string s;
		cin >> s;
		const int size = s.length();
		for (int a = 0; a < 10002; a++) fill(dp[a], dp[a] + t, 0);
		for (int j = 0; j < size; ++j) {
			int manager = 1 << (s[j] - 'A');
			for (int k = 1; k < t; ++k) { //경우의 수 확인
				if (j == 0) { // 첫날, A : key
					if ((k & manager) != 0 && (k & 1) != 0) {
						dp[j][k] = 1;
					}
				}

				else { //다른 날
					if (dp[j - 1][k] != 0) { //경우의 수 존재
						for (int m = 1; m < t; ++m) { //전체 경우 확인
							if ((m & manager) != 0 && (k & m) != 0) {
								// manager o , 전날 사람 o
								dp[j][m] += dp[j - 1][k];
								dp[j][m] %= mod;
							}
						}
					}
				}

			}
		}
		ll ans = 0;
		for (int j = 1; j < t; j++) {
			ans += dp[size - 1][j];
			ans %= mod;
		}
		cout << "#" << i << ' ' << ans << '\n';
	}
	return 0;
}