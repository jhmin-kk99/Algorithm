#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int tc;
typedef long long ll;
#define mod 20171109

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		priority_queue<int> pqMax; //최대힙
		priority_queue<int, vector<int>, greater<int>> pqMin; //최소힙
		// 최대힙의 개수 = 최소힙의 개수 + 1 (유지)
		// 중간값 : 최대힙.top();
		ll ans = 0;
		int n, a;
		cin >> n >> a;
		pqMax.push(a);
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			if (x < pqMax.top()) {
				pqMax.push(x);
				if (y < pqMax.top()) {
					pqMax.push(y);
				}
				else {
					pqMin.push(y);
				}
			}
			else {
				pqMin.push(x);
				if (y < pqMax.top()) {
					pqMax.push(y);
				}
				else {
					pqMin.push(y);
				}
			}
			if (pqMax.size() > pqMin.size() + 1)
			{
				while (pqMax.size() > pqMin.size() + 1) {
					pqMin.push(pqMax.top());
					pqMax.pop();
				}
			}
			else if (pqMin.size() > pqMax.size()) {
				while (pqMin.size() > pqMax.size()) {
					pqMax.push(pqMin.top());
					pqMin.pop();
				}
			}
			int tmp = pqMax.top() % mod;
			ans += tmp;
			ans %= mod;
		}
		cout << "#" << t << ' ' << ans << '\n';

	}
}