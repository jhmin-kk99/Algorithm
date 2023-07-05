#include <iostream>
#include <algorithm>
using namespace std;
int comb[1002][1002];
const int mod = 10007;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= 1000; i++) {
		comb[i][0] = comb[i][i] = 1;
		for (int j = 1; j < i; j++) {
			comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % mod;
		}
	}
	cout << comb[n][k];
}