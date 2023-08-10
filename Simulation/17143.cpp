#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
int board1[102][102];
vector<int> board2[102][102];
int ans = 0;
//오른쪽으로 이동
//가장 가까운 상어 잡기
//각 상어 이동 (정보 : (x,y) , 속력, 방향, 크기)
//같은 칸 상어 큰게 작은거 잡아먹기
int r, c, m;
#define X first
#define Y second
struct shark {
	pair<int, int> pos;
	int dir;
	int v;
	int sz;
	bool check;
};
shark pool[10002];
int cnt = 1;
bool OOB(int a, int b) { //벽에 부딪히는지
	return a < 0 || b < 0 || a >= r || b >= c;
}
void upd(int idx) { //상어 이동, 시간복잡도를 고려해서 단축할 수 있는 곳을 줄여야함
	auto cur = pool[idx].pos;
	int v = pool[idx].v;
	int nx = cur.X;
	int ny = cur.Y;
	if (0 <= pool[idx].dir && pool[idx].dir <= 1) { //up down
		v = v % (2 * (r - 1));
		while (v--) {
			nx += dx[pool[idx].dir];
			ny += dy[pool[idx].dir];
			if (OOB(nx, ny)) {
				pool[idx].dir = 1 - pool[idx].dir;
				nx += 2 * dx[pool[idx].dir]; // 앞에서 1 더해준 것도 포함해서 빼야함
				ny += 2 * dy[pool[idx].dir];
			}
		}
	}
	else { // right left
		v = v % (2 * (c - 1));
		while (v--) {
			nx += dx[pool[idx].dir];
			ny += dy[pool[idx].dir];
			if (OOB(nx, ny)) {
				pool[idx].dir = 5 - pool[idx].dir;
				nx += 2 * dx[pool[idx].dir];
				ny += 2 * dy[pool[idx].dir];
			}
		}
	}
	board2[nx][ny].push_back(idx);
	pool[idx].pos = { nx, ny };
}
void eat() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (board2[i][j].size() > 0) {
				int MX = board2[i][j][0];
				for (int k = 1; k < board2[i][j].size(); k++) {
					if (pool[MX].sz < pool[board2[i][j][k]].sz) {
						pool[MX].check = true;
						MX = board2[i][j][k];
					}
					else {
						pool[board2[i][j][k]].check = true;
					}
				}
				board2[i][j].clear();
				board2[i][j].push_back(MX);
			}
		}
	}
}
void solve() {
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < r; j++) {
			if (board1[j][i] > 0 && pool[board1[j][i]].check == false) {
				ans += pool[board1[j][i]].sz;
				pool[board1[j][i]].check = true;
				board1[j][i] = 0; //상어 잡기
				break;
			}
		}
		for (int j = 1; j <= m; j++) {
			if (pool[j].check == false)
				upd(j); // 각 상어 이동
		}
		eat(); //상어 잡아먹기
		for (int a = 0; a < r; a++) {
			for (int b = 0; b < c; b++) {
				if (board2[a][b].size() > 0) board1[a][b] = board2[a][b][0];
				else board1[a][b] = 0;
				board2[a][b].clear();
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> r >> c >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		shark s;
		s.pos = { a - 1,b - 1 }; //좌표가 0부터 시작하는지 1부터시작하는지 확인
		s.v = c;
		s.dir = d - 1; //방향이 1,2,3,4 임을 고려
		s.sz = e;
		s.check = false;
		board1[a - 1][b - 1] = cnt;
		pool[cnt++] = s;
	}
	solve();
	cout << ans;
}