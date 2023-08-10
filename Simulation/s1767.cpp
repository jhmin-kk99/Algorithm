#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int tc, n;
int map[15][15];
vector<pair<int, int>> v;
int max_power_cnt;
int core_cnt;
int ans;
// 코어 수, 전선 합
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

bool check(int curX, int curY, int dir) {
	int nx = curX + dx[dir];
	int ny = curY + dy[dir];
	switch (dir) {
	case 0: //남
		for (int i = nx; i < n; i++) {
			if (map[i][ny] != 0 && 0 <= i && i < n && 0 <= ny && ny < n) return false;
		}
		break;
	case 1: //동
		for (int i = ny; i < n; i++) {
			if (map[nx][i] != 0 && 0 <= i && i < n && 0 <= nx && nx < n) return false;
		}
		break;
	case 2: //북
		for (int i = nx; i >= 0; i--) {
			if (map[i][ny] != 0 && 0 <= i && i < n && 0 <= ny && ny < n) return false;
		}
		break;
	case 3: //서
		for (int i = ny; i >= 0; i--) {
			if (map[nx][i] != 0 && 0 <= i && i < n && 0 <= nx && nx < n) return false;
		}
		break;

	}
	return true;
}


void dfs(int index, int power_cnt) { //현재 인덱스, 연결된 코어수
	if (power_cnt + (core_cnt - index) < max_power_cnt) return;
	if (index == core_cnt) {
		if (power_cnt >= max_power_cnt) {
			int tmp = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (map[i][j] == 2) {
						tmp++;
					}
				}
			}
			if (power_cnt > max_power_cnt) ans = tmp;
			else ans = min(ans, tmp);

			max_power_cnt = power_cnt;
		}
		return;
	}
	int tmp[12][12];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tmp[i][j] = map[i][j];
		}
	}
	int curX = v[index].first;
	int curY = v[index].second;
	for (int dir = 0; dir < 4; dir++) {
		if (check(curX, curY, dir)) { //라인 놓을 수 있으면
			int nx = curX + dx[dir];
			int ny = curY + dy[dir];
			while (0 <= nx && nx < n && 0 <= ny && ny < n) {
				map[nx][ny] = 2; //라인 놓음
				nx += dx[dir];
				ny += dy[dir];
			}
			dfs(index + 1, power_cnt + 1);
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					map[i][j] = tmp[i][j]; //맵 복구
				}
			}
		}
	}
	//연결 안하는 경우
	dfs(index + 1, power_cnt);
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		ans = 0x7fffffff;
		cin >> n;
		memset(map, -1, sizeof(map));
		vector<pair<int, int>>().swap(v);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				if (map[i][j]) {
					if (i == 0 || i == n - 1 || j == 0 || j == n - 1) continue;
					v.push_back({ i,j });
				}
			}
		}
		core_cnt = v.size(); //코어 카운트를 벡터의 개수로 설정
		max_power_cnt = 0;
		dfs(0, 0);

		cout << "#" << t << " " << ans << '\n';

	}
}