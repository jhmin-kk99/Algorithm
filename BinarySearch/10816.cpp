#include <iostream>
#include <algorithm>

using namespace std;
int a[500005];
int n;

int upper_idx(int x, int len) { //x보다 큰 바로 다음 수
	int st = 0;
	int en = len;
	while (st < en) {
		int mid = (st + en) / 2;
		if (a[mid] > x)en = mid;
		else st = mid + 1;
	}
	return st;
}
int lower_idx(int x, int len) { //x인 수들 중 가장 인덱스가 작은 수
	int st = 0;
	int en = len;
	while (st < en) {
		int mid = (st + en) / 2;
		if (a[mid] >= x) en = mid;
		else st = mid + 1;
	}
	return st;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int m;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	sort(a, a + n);
	cin >> m;
	while (m--) {
		int x;
		cin >> x;
		int ans = upper_idx(x, n) - lower_idx(x, n);
		// ans = upper_bound(a,a+n,x)-lower_bound(a,a+n,x);
		cout << ans << ' ';
	}
}