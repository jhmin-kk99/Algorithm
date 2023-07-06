#include <iostream>
#include <algorithm>

using namespace std;
int a[100005];
int n;

int binarysearch(int x) {
	int st = 0;
	int en = n - 1;
	while (st <= en) {
		int mid = (st + en) / 2;
		if (a[mid] < x) {
			st = mid + 1;
		}
		else if (a[mid] > x) {
			en = mid - 1;
		}
		else
			return 1;
	}
	return 0;
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
		cout << binarysearch(x) << '\n';
		//cout << binary_search(a, a + n, x) << '\n'; //STL이용
	}
}