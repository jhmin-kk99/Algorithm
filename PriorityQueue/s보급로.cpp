#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;
int tc;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		int n;			//깊이, x, y
		priority_queue< tuple<int, int, int>,
			vector<tuple<int, int, int>>,
			greater<tuple<int, int, int>> > pq;
		int map[102][102] = {};
		int dist[102][102] = {};
		int vis[102][102] = {};
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			string s;
			cin >> s;
			for (int j = 0; j < n; j++) {
				map[i][j] = s[j] - '0';
			}
		}

		pq.push({ 0, 0, 0 });
		dist[0][0] = 0;
		vis[0][0] = 1;
		while (!pq.empty()) {
			int d, curX, curY;
			auto cur = tie(d, curX, curY);
			cur = pq.top();
			pq.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = curX + dx[dir];
				int ny = curY + dy[dir];
				if (dist[nx][ny] > 0 || vis[nx][ny])continue;
				if (nx < 0 || ny < 0 || nx >= n || ny >= n)continue;
				dist[nx][ny] = d + map[nx][ny];
				pq.push({ dist[nx][ny], nx, ny });
				vis[nx][ny] = 1;
			}
		}

		cout << "#" << t << ' ' << dist[n - 1][n - 1] << '\n';

	}
}