#include<iostream>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for (int a = 1; a <= T; a++) {
		int N;
		cin >> N;
		int ans = 0;
		int cnt = 1;
		while (1) {
			int k = N * cnt;
			string str = to_string(k);
			for (int i = 0; i < str.length(); i++)
			{
				int cur = str[i] - '0';
				ans = ans | (1 << cur);
			}
			if (ans == (1 << 10) - 1) {
				cout << "#" << a << ' ' << str << '\n';
				break;
			}
			cnt++;

		}
	}

}
