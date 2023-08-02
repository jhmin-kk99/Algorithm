#include<iostream>
#include<vector>
#include <cmath>
#include<algorithm>
using namespace std;
int tc;
vector<int> cow;
vector<int> hor;
int n, m, c1, c2;
int cnt, closest;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> n >> m;
		cin >> c1 >> c2;
		vector<int>().swap(cow);
		vector<int>().swap(hor);
		int dist = abs(c1 - c2);
		closest = 0x7fffffff; cnt = 0;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			cow.push_back(x);
		}
		sort(cow.begin(), cow.end());

		while (m--) {
			int x;
			cin >> x;
			auto lo = lower_bound(cow.begin(), cow.end(), x);
			if (lo != cow.end()) {
				//값이 존재하면
				if (closest > * lo - x) {
					closest = *lo - x; cnt = 1;
				}
				else if (closest == *lo - x) {
					++cnt;
				}
			}
			if (lo != cow.begin()) {
				if (closest > x - *prev(lo)) {
					/*std::prev 함수는 C++이터레이터 라이브러리의 일부로,
					이터레이터가 가리키는 시퀀스에서 이터레이터를 한 위치 뒤로
					이동하는 데 사용됨*/
					closest = x - *prev(lo); cnt = 1;
				}
				else if (closest == x - *prev(lo)) {
					++cnt;
				}
			}

		}
		cout << "#" << t << " " << dist + closest << " " << cnt << '\n';
	}

}