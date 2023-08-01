#include <iostream>
#include<algorithm>
#include<string>
#include<set>
using namespace std;
int tc;

class cmp {
public:
	bool operator()(string s1, string s2) const {
		//std::set은 원소들을 정렬하는 데 사용되는 비교 함수가 const 멤버 함수로 선언되어야 함
		if (s1.length() < s2.length()) return true;
		if (s1.length() > s2.length())return false;
		if (s1 < s2)return true;
		return false;
	}
};

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> tc;
	for (int t = 1; t <= tc; t++) {

		int n;
		cin >> n;
		set<string, cmp> v;
		while (n--)
		{
			string s;
			cin >> s;
			v.insert(s);
		}
		cout << "#" << t << '\n';
		for (auto e : v) {
			cout << e << '\n';
		}

	}

}