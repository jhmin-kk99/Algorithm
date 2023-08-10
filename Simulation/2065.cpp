#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int m, t, n;
queue<pair<int, int>> lt;
queue<pair<int, int>> rt;
int ans[10002];
int arr[10002];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> m >> t >> n;
	for (int i = 0; i < n; i++) {
		int time;
		string dir;
		cin >> time >> dir;
		if (dir == "left")
			lt.push({ time , i });
		else
			rt.push({ time , i });
	}
	int time = 0; //초기
	int dir = 0; //left
	int check = 0;
	while (!(lt.empty() && rt.empty())) {
		int k = m;
		if (!dir) {
			//왼쪽에 있으면
			if (!lt.empty()) {
				//큐가 비어있지 않은 경우
				while (k--) {
					int lp, rp;
					if (lt.empty()) lp = 987654321;
					else lp = lt.front().first;
					if (rt.empty()) rp = 987654321;
					else rp = rt.front().first;
					if (lp <= time) {
						int index = lt.front().second;
						lt.pop();
						ans[index] = time + t;
						check = 1;
						if (lt.empty())break;
					}
					else {
						if (check)break;
						if (lp >= rp) {
							if (rp > time) {
								time = rp;
								time += t;
								dir = 1;
							}
							else {
								time += t;
								dir = 1;
							}

						}
						else {
							time = lp;
							k += 1;
							continue;
						}
						break;
					}
				};
				if (check)
				{
					time += t;
					dir = 1;
					check = 0;
				}
			}
			else {
				//큐가 비어있는 경우
				if (rt.empty()) break;
				int rp;
				rp = rt.front().first;
				if (time >= rp) {
					time += t;
					dir = 1;
				}
				else {
					time = rp;
					time += t;
					dir = 1;
				}

			}

		}
		else {
			//오른쪽에 있으면
			if (!rt.empty()) {
				//큐가 비어있지 않은 경우
				while (k--) {
					int lp, rp;
					if (lt.empty()) lp = 987654321;
					else lp = lt.front().first;
					if (rt.empty()) rp = 987654321;
					else rp = rt.front().first;
					if (rp <= time) {
						int index = rt.front().second;
						rt.pop();
						ans[index] = time + t;
						check = 1;
						if (rt.empty())break;
					}
					else {
						if (check)break;
						if (rp >= lp) {
							if (lp > time) {
								time = lp;
								time += t;
								dir = 0;
							}
							else {
								time += t;
								dir = 0;
							}

						}
						else {
							time = rp;
							k += 1;
							continue;
						}
						break;
					}
				};
				if (check)
				{
					time += t;
					dir = 0;
					check = 0;
				}
			}
			else {
				//큐가 비어있는 경우
				if (lt.empty()) break;
				int lp;
				lp = lt.front().first;
				if (time >= lp) {
					time += t;
					dir = 0;
				}
				else {
					time = lp;
					time += t;
					dir = 0;
				}

			}
		}
	}
	for (int i = 0; i < n; i++)
		cout << ans[i] << '\n';
}
