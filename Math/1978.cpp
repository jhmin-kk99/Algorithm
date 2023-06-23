#include <iostream>
#include <algorithm>
using namespace std;
int n;



bool isprime(int n) {
	if (n == 1) return 0;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0)return 0;
	}
	return 1;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	int cnt = 0;
	while (n--) {
		int x;
		cin >> x;
		cnt += isprime(x);
	}
	cout << cnt << '\n';
}