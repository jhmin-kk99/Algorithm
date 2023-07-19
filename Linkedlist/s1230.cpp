#include<iostream>
#include<algorithm>
#include<list>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 1; i <= 10; ++i) {
		int n, m;
		cin >> n;
		list<int> li;
		for (int j = 0; j < n; ++j)
		{
			int t;
			cin >> t;
			li.push_back(t);
		}
		cin >> m;
		for (int j = 0; j < m; ++j) {
			char c;
			int x, y;
			cin >> c;
			if (c == 'I') {
				cin >> x >> y;
				auto st = li.begin(); // list에서 iterator로
				advance(st, x); // x인덱스 찾기
				for (int k = 0; k < y; ++k) {
					int s;
					cin >> s;
					li.insert(st, s);
				}

			}
			else if (c == 'D') {
				cin >> x >> y;
				auto st = li.begin();
				advance(st, x);
				for (int k = 0; k < y; ++k) {
					st = li.erase(st); // 삭제 후 다음 원소 반환 
				}
			}
			else {
				cin >> y;
				for (int k = 0; k < y; ++k) {
					int s;
					cin >> s;
					li.push_back(s);
				}
			}
		}
		cout << "#" << i << ' ';
		int cnt = 0;
		for (auto ans : li) {
			cout << ans << ' ';
			cnt++;
			if (cnt == 10)
				break;
		}
		cout << '\n';
	}
	return 0;
}