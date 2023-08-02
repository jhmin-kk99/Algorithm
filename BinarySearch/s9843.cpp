#include <iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
using namespace std;
typedef long long ll;
int tc;
long long N, ans;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		ans = -1;
		cin >> N;
		ll st, en, mid;
		st = 1;
		en = sqrt(2 * N); // k*(k+!) = 2N , k^2 < 2N

		while (st <= en) {
			mid = (st + en) / 2;
			ll X = (mid * (mid + 1)) / 2;
			if (X == N) {
				ans = mid;
				break;
			}
			else if (X < N) st = mid + 1;
			else en = mid - 1;
		}

		cout << "#" << t << " " << ans << '\n';

	}

}