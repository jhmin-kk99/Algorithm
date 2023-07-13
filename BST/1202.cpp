#include <iostream>
#include <map>
#include <set>
#include<algorithm>
using namespace std;
multimap<int, int, greater<int>> jew; //내림차순
multiset<int> bag;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int m, v;
		cin >> m >> v;
		jew.insert({ v,m });
	}
	for (int i = 0; i < k; i++) {
		int c;
		cin >> c;
		bag.insert(c);
	}
	ll s = 0;
	for (auto e : jew) {
		if (bag.empty()) break;
		auto it = bag.lower_bound(e.second);
		if (it != bag.end()) {
			s += e.first;
			bag.erase(it);
		}
	}
	cout << s;
}