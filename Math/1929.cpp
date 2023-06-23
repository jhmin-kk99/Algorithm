#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;

vector<int> sieve(int a, int b) {
	vector<int> primes;
	vector<bool> state(b + 1, true);
	state[1] = false;
	for (int i = 2; i * i <= b; i++) {
		if (!state[i]) continue;
		for (int j = i * i; j <= b; j += i) {
			state[j] = false;
		}
	}
	for (int i = a; i <= b; i++) {
		if (state[i])primes.push_back(i);
	}
	return primes;
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> m >> n;
	vector<int> k = sieve(m, n);
	for (auto ans : k) {
		cout << ans << '\n';
	}

}