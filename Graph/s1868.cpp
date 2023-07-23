#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
char map[302][302];
int vis[302][302];
int dy[8] = { 0, 0, -1, 1, -1, 1, -1, 1 };
int dx[8] = { -1, 1, 0, 0, -1, 1, 1, -1 };
int n;
string s;

bool safe(int x, int y) {
	for (int dir = 0; dir < 8; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (0 <= nx && nx < n && 0 <= ny && ny < n) {
			if (map[nx][ny] == '*') return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {

		int click = 0; // 클릭 수
		for (int j = 0; j < 302; j++) {
			fill(map[j], map[j] + 302, '?');
			fill(vis[j], vis[j] + 302, false);
		}
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> s;
			for (int k = 0; k < n; k++) {
				map[j][k] = s[k];
			}
		}
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (safe(j, k) && map[j][k] == '.' && !vis[j][k]) {
					click++;
					queue<pair<int, int>> q;
					q.push({ j, k });
					while (!q.empty()) {
						int curX = q.front().first;
						int curY = q.front().second;
						vis[curX][curY] = true;
						q.pop();
						for (int dir = 0; dir < 8; dir++)
						{
							int nx = curX + dx[dir];
							int ny = curY + dy[dir];
							if (nx < 0 || ny < 0 || nx >= n || ny >= n)continue;
							if (map[nx][ny] == '*')continue;
							if (vis[nx][ny])continue;
							vis[nx][ny] = true;
							if (safe(nx, ny)) q.push({ nx,ny });
						}
					}
				}
			}
		}

		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (!vis[j][k] && map[j][k] == '.') click++;
			}
		}
		cout << "#" << i << ' ' << click << '\n';

	}
}