#include<iostream>
#include<algorithm>

int heap[100005];
int sz = 0; //heap에 들어있는 원소의 수

void push(int x) {
	heap[++sz] = x;
	int cur = sz;
	while (cur > 1) {
		int par = cur / 2;
		if (heap[par] > x) {
			swap(heap[cur], heap[cur / 2]);
			cur = par;
		}
		else break;
	}
}
int top() {
	return heap[1];
}
void pop() {
	heap[1] = heap[sz--];
	int cur = 1;
	// 왼쪽 자식의 인덱스(=2*cur)가 sz보다 크면 cur는 리프
	while (cur * 2 <= sz) {
		int lc = cur * 2, rc = cur * 2 + 1; // 왼쪽 자식, 오른쪽 자식
		int min_child = lc; //두 자식 중 작은 인덱스를 담을 예정
		if (rc <= sz && heap[rc] < heap[lc])
			min_child = rc;
		if (heap[cur] <= heap[min_child])break;
		swap(heap[cur], heap[min_child]);
		cur = min_child;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		if (p > 0) push(p);
		else {
			if (sz == 0) cout << 0 << '\n';
			else {
				cout << top() << '\n';
				pop();
			}
		}
	}
}
