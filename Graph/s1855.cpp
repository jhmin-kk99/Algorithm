#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int tc;
int dp[18][100005]; //dp[k][n] : n번 노드의 2^k번째 부모
// 점화식 : dp[k][n] = dp[k-1][dp[k-1][n]]
//-> n의 2^k번째 부모 노드는 n의 2^k-1번째 부모 노드의 2^k-1부모 노드
// 배열에서 k는 '트리의 깊이 > 2^k'를 만족하는 최댓값
// k = 0 이 초기화값
int depth[100005];
vector<int> child[100005];

//LCA 알고리즘
//1. 모든 노드에 대한 깊이(depth)를 계산, 부모를 저장
//2. 최소 공통 조상을 찾을 두 노드를 확인
//	1. 먼저 두 노드의 깊이(depth)가 동일하도록 거슬러 올라감
// dp를 이용해 테이블에 2^i번째 부모를 저장
//	2. 이후에 부모가 같아질 때까지 반복적으로 두 노드의 부모 방향으로 거슬러 올라감
//3. 모든 LCA(a,b)연산에 대하여 2번의 과정을 반복


// 특정 노드의 깊이(depth)를 구하는 함수, 부모를 이용
int dfs(int cur) {
	if (cur == 1 || depth[cur] > 0) return depth[cur];
	return dfs(dp[0][cur]) + 1;
}
// 전체 부모 관계를 설정하는 함수
void set_parent(int num) {
	for (int i = 1; i <= num; i++) depth[i] = dfs(i);
	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= 17; j++) {
			dp[j][i] = dp[j - 1][dp[j - 1][i]];
		}
	}
}

// a와 b의 최소 공통 조상을 찾는 함수
int LCA(int a, int b) {
	// b가 더 깊도록 설정
	int low, high;
	high = a; low = b;
	if (depth[a] > depth[b]) {
		int tmp = low;
		low = high;
		high = tmp;
	}
	// 먼저 깊이(depth)가 동일하도록
	for (int i = 17; i >= 0; i--) {
		if (depth[low] - depth[high] >= (1 << i)) {
			low = dp[i][low];
		}
	}
	// 부모가 같아지도록
	if (low == high) return low;
	for (int i = 17; i >= 0; i--) {
		if (dp[i][high] != dp[i][low]) {
			high = dp[i][high];
			low = dp[i][low];
		}
	}
	return dp[0][low];
}

long long bfs() {
	long long ans = 0;
	queue<int> q;
	q.push(1);
	int pre = 0;
	while (!q.empty()) {
		int cur = q.front();
		//cout << "cur: " << cur << '\n';
		//cout << "pre: " << pre << '\n';
		if (pre != 0) {
			int t = LCA(pre, cur);
			if (t != pre) {
				ans += (depth[pre] + depth[cur] - 2 * depth[t]);
			}
			else {
				ans += (depth[cur] - depth[pre]);
			}
		}
		/*	cout <<"ans: "<< ans << '\n';*/
		q.pop();
		pre = cur;
		for (auto nxt : child[cur]) {
			q.push(nxt);
		}

	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		int n;
		cin >> n;
		fill(depth, depth + 100005, 0);
		for (int i = 0; i < 100005; i++) {
			vector<int>().swap(child[i]);
		}
		for (int i = 0; i < 18; i++)fill(dp[i], dp[i] + 100005, 0);
		// parent[1] = 0 루트노드
		for (int i = 2; i <= n; i++) {
			int par;
			cin >> par;
			dp[0][i] = par;
			child[par].push_back(i);
		}
		set_parent(n);
		cout << "#" << t << " " << bfs() << '\n';
	}




}