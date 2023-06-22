#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n, k;
vector<int> adj[100005];
int depth[100005];
int apple[100005];
int cnt = 0;

void bst(int root, int dt) {
	queue<int> q;
	q.push(root);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (depth[cur] > k) break;
		if (apple[cur])cnt++;
		for (auto nxt : adj[cur]) {
			q.push(nxt);
			depth[nxt] = depth[cur] + 1;
		}
	}
}



int main(void) {
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 0; i < n - 1; i++) {
		int p, c;
		cin >> p >> c;
		adj[p].push_back(c);
	}
	for (int i = 0; i < n; i++) {
		cin >> apple[i];
	}
	bst(0, k);
	cout << cnt;
}