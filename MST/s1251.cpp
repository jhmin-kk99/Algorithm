#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <cmath>
using namespace std;
vector<int> p(1005, -1);
int X[1005];
int Y[1005];
int t;
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


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		int v, e;
		vector<tuple<double, int, int>> edge; // 비용, 정점1, 정점2
		fill(p.begin(), p.end(), -1);
		fill(X, X + 1005, -1);
		fill(Y, Y + 1005, -1);
		cin >> v; //정점 수
		for (int i = 0; i < v; i++) {
			cin >> X[i];
		}
		for (int i = 0; i < v; i++) {
			cin >> Y[i];
		}
		double E;
		cin >> E;
		for (int i = 0; i < v - 1; i++) {
			for (int j = i + 1; j < v; j++) {
				double cost = E * (pow((X[i] - X[j]), 2) + pow((Y[i] - Y[j]), 2));
				edge.push_back({ cost,i,j });
				//	cout <<X[i]<<' '<<X[j]<<' '<<Y[i]<<' '<<Y[j]<<' '<< pow((X[i] - X[j]), 2) << "," << pow((Y[i] - Y[j]), 2) << "," << (pow((X[i] - X[j]), 2) + pow((Y[i] - Y[j]), 2)) << ", " << E * (pow((X[i] - X[j]), 2) + pow((Y[i] - Y[j]), 2)) << '\n';
			}
		}

		sort(edge.begin(), edge.end());
		int cnt = 0; //v-1인지 확인
		double ans = 0;
		for (auto kru : edge) {
			double cost;
			int a, b;
			tie(cost, a, b) = kru;
			if (!is_diff_group(a, b))continue;
			ans += cost;
			cnt++;
			if (cnt == v - 1)break;
		}
		cout << fixed; // 소수점 고정
		cout.precision(0); // 소수점 첫째자리에서 반올림
		cout << "#" << tc << ' ' << ans << '\n';

	}
}