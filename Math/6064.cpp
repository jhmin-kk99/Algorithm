#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int t;

int gcd(int a, int b) {
	if (a == 0) return b;
	return gcd(b % a, a);
}

int lcm(int a, int b) { //최소공배수
	return a / gcd(a, b) * b;
}

int year(int m, int n, int x, int y) {
	int ans = x;
	int a = x;
	int b = x % n;
	if (!b) b = n;
	int MX = lcm(m, n);
	while (1) {
		if (a == x && b == y) break;
		if (ans > MX) {
			ans = -1;
			break;
		}
		else {
			ans += m;
			b = (b + m) % n;
			if (!b) b = n;
		}
	}

	return ans;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		int m, n, x, y;
		cin >> m >> n >> x >> y;
		int k = year(m, n, x, y);
		cout << k << '\n';

	}

}