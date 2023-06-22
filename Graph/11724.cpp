#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M;
vector<int> adj[1002];
bool vis[1002];
int cnt = 0;

void bfs() {
	for (int i = 1; i <= N; i++) {
		queue<int> q;
		if (vis[i])continue;
		cnt++;
		q.push(i);
		vis[i] = true;
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			for (auto nxt : adj[cur]) {
				if (vis[nxt]) continue;
				q.push(nxt);
				vis[nxt] = true;
			}
		}
		
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	while(M--) {
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	bfs();
	cout << cnt;
}