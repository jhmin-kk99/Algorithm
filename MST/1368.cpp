#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <cmath>
using namespace std;
vector<int> p(305, -1);
int N;
int find(int x) {
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}
bool is_diff_group(int u, int v) {
	u = find(u);  v = find(v);
	if (u == v)return 0;
	if (p[u] == p[v]) p[u]--;
	if (p[u] < p[v]) p[v] = u;
	else p[u] = v;
	return 1;
}
vector<tuple<int, int, int>> edge;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	// 우물 파는 것을 , 가상의 논으로 생각
	for (int i = 1; i <= N; i++) {
		int cost;
		cin >> cost;
		edge.push_back({ cost,0,i }); //가상의 논
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int cost;
			cin >> cost;
			if (i == j)continue;
			edge.push_back({ cost,i,j });
		}
	}
	sort(edge.begin(), edge.end());
	int cnt = 0; // 간선이 N이 되는지 확인
	int ans = 0;
	for (auto nxt : edge) {
		int cost, a, b;
		tie(cost, a, b) = nxt;
		if (!is_diff_group(a, b)) continue;
		cnt++;
		ans += cost;
		if (cnt == N) break;
	}
	cout << ans;
}