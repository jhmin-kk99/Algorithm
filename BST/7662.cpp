#include <iostream>
#include <set>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int k;
		cin >> k;
		multiset<int> arr;
		for (int i = 0; i < k; i++) {
			char op;
			int num;
			cin >> op >> num;
			if (op == 'I') {
				arr.insert(num);
			}
			else {
				if (!arr.empty()) {
					if (num == 1) {
						//최댓값 삭제
						arr.erase(--arr.end());
						//arr.erase(prev(arr.end());
					}
					else {
						//최솟값 삭제
						arr.erase(arr.begin());
					}
				}
				else continue;
			}
		}
		if (!arr.empty()) {
			cout << *(--arr.end()) << ' ' << *arr.begin() << '\n';
		}
		else cout << "EMPTY" << '\n';

	}
}