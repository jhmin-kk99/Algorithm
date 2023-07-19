정수 N, M 이 주어질 때, M의 이진수 표현의 마지막 N 비트가 모두 1로 켜져 있는지 아닌지를 판별하여 출력하라.



[입력]

첫 번째 줄에 테스트 케이스의 수 TC가 주어진다.
이후 TC개의 테스트 케이스가 새 줄로 구분되어 주어진다.
각 테스트 케이스는 다음과 같이 구성되었다.
첫 번째 줄에 정수 N, M이 주어진다. (1 ≤ N ≤ 30, 0 ≤ M ≤ 108)



[출력]

각 테스트 케이스마다 한 줄씩

마지막 N개의 비트가 모두 켜져 있다면 ON

아니면 OFF 를 출력하라.

#include<iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		int n, m;
		cin >> n >> m;

		int ans = (m | ((1 << n) - 1));
		if (m == ans) cout << "#" << i << ' ' << "ON" << '\n';
		else  cout << "#" << i << ' ' << "OFF" << '\n';
	}
}
