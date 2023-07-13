# 우선순위 큐 

> 우선순위 큐 = pop을 할 때 가장 먼저 들어온 원소가 나오는 대신 우선순위가 가장 높은 원소가 나오는 큐
>> 1. 원소의 추가가 O(logN)
>> 2. 우선순위가 가장 높은 원소의 확인 O(1)
>> 3. 우선순위가 가장 높은 원소의 제거가 O(logN)
<구현>
x번지의 왼쪽, 오른쪽 자식 : 2x, 2x+1
x번지의 부모 : x/2
```
int heap[100005];
int sz = 0; //heap에 들어있는 원소의 수

void push(int x){
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
int top(){
	return heap[1];
}
void pop(){
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
```
```
#include <iostream>
#include <queue>
using namespace std;
int heap[100005];
int sz = 0; //heap에 들어있는 원소의 수

void push(int x){
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
int top(){
	return heap[1];
}
void pop(){
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
    priority_queue<int> pq; // 최대 힙
 // priority_queue<int, vector<int>, greater<int>>로 선언시 최소 힙
    pq.push(10); pq.push(2); pq.push(5); pq.push(9); // {10, 2, 5, 9}
    cout << pq.top() << '\n'; // 10
    pq.pop(); // {2, 5, 9}
    cout << pq.size() << '\n'; // 3
    if (pq.empty()) cout << "PQ is empty\n";
    else cout << "PQ is not empty\n";
    pq.pop(); // {2, 5}
    cout << pq.top() << '\n'; // 5  
    pq.push(5); pq.push(15); // {2, 5, 5, 15}
    cout << pq.top() << '\n'; // 15  
}
```

> priority_queue는 set보다 수행속도가 빠르고, 공간도 적게 차지한다.
> priority_queue에서 제공하는 기능들만 필요한 경우 priority_queue를 쓰면 좋음

____   
| 문제 번호 | 정답 코드 |  중요한 문제(아이디어) | 
| :--: | :--: |:--: |
| __[Baekjoon 1927번](https://www.acmicpc.net/problem/1927)__   | [Solution](https://github.com/jhmin-kk99/Algorithm-Study/blob/main/PriorityQueue/1927.cpp)    | |
| __[Baekjoon 11286번](https://www.acmicpc.net/problem/11286)__   | [Solution](https://github.com/jhmin-kk99/Algorithm-Study/blob/main/PriorityQueue/11286.cpp)    | |
| __[Baekjoon 1715번](https://www.acmicpc.net/problem/1715)__   | [Solution](https://github.com/jhmin-kk99/Algorithm-Study/blob/main/PriorityQueue/1715.cpp)    | |
