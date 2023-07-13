#include <iostream>
#include <queue>
using namespace std;

class cmp { //priority queue에서 비교함수 만들 때, class를 이용해야함
public:
	bool operator() (int a, int b) {
		// priority queue는 기본적으로 최대힙
		// -> 가장 작은 값이 맨 뒤에 오도록 해야 함
		if (abs(a) != abs(b)) return abs(a) > abs(b);
		return a > 0 && b < 0;
		// 둘이 같은 부호면 false, 앞이 양수이고 뒤가 음수일 때만 true를 반환
		//cmp 함수에서 비교연산이 false면 swap이 됨
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	priority_queue<int, vector<int>, cmp> pq; // 최대 힙
	while (n--) {
		int x;
		cin >> x;
		if (x == 0) {
			if (pq.empty()) cout << 0 << '\n';
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else pq.push(x);
	}
}