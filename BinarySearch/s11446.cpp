#include <iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
using namespace std;
typedef long long ll;
int tc;
long long ans, M;
vector<long long> arr;
int n;

bool check(long long m) {
	long long cur = 0;
	for (auto e : arr) {
		cur += e / m;
	}
	return cur >= M;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		ans = 0;
		vector<ll>().swap(arr);
		cin >> n >> M;
		for (int i = 0; i < n; i++) {
			ll x;
			cin >> x;
			arr.push_back(x);
		}
		ll st, en, mid;
		st = 1; en = *max_element(arr.begin(), arr.end());

		while (st <= en) {
			mid = (st + en) / 2; // 가방 수
			if (check(mid)) {
				ans = mid;
				st = mid + 1;
			}
			else {
				en = mid - 1;
			}
		}

		cout << "#" << t << " " << ans << '\n';

	}

}