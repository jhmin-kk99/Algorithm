//Problem
//No. 19[Professional] 고속도로 건설 2
//시간 : 8개 테스트케이스를 합쳐서 C / C++의 경우 3초 / Java의 경우 5초
//메모리 : 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
//※ SW Expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.
//
//
//모든 도시를 잇는 고속도로를 건설하려 한다.
//
//그러나 비싼 비용의 문제에 부딪혀, 정부는 최소 비용으로 모든 도시 간을 이동할 수 있게 하고 싶어한다.
//
//또한 하나의 제약이 더 있는데, 언덕 등을 깎지 않는 친환경 건설을 위해 어떤 도시끼리는 직접 도로를 이을 수 없다.
//
//친환경 건설을 위해 이을 수 있는 도로의 목록이 주어질 때, 정부를 도와 모든 도시 간을 잇는 고속도로를 건설하는 최소 비용을 알아내자.
//
//
//[입력]
//
//첫 줄에 테스트케이스의 개수 T가 주어진다. (1 ≤ T ≤ 8)
//
//각 테스트 케이스의 첫 번째 줄에 도시의 수 N이 주어진다. (2 ≤ N ≤ 50, 000)
//
//각 테스트 케이스의 두 번째 줄에 도로 후보의 수 M이 주어진다. (1 ≤ M ≤ 200, 000)
//
//각 테스트 케이스의 세 번째 줄부터 M개의 줄에 걸쳐 각 도로 후보의 정보 s, e, c가 주어진다.
//
//s와 e는 도로 후보가 잇는 각 도시의 번호이고, c는 그 도로를 건설하는데 드는 비용이다. (1 ≤ c ≤ 10, 000)
//
//항상 모든 도시를 잇는 고속도로를 건설할 수 있는 입력만 주어진다.
//
//[출력]
//
//각 테스트케이스마다 한 줄에 걸쳐, 테스트케이스 수 “#(TC)“를 출력하고, 모든 도시를 잇는 고속도로를 건설하는데 드는 최소 비용을 출력한다.


#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
vector<int> p(50005, -1);
int tc;

int find(int x) {
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}
bool is_diff_group(int u, int v) {
	u = find(u); v = find(v);
	if (u == v) return 0;
	if (p[u] == p[v]) p[u]--;
	if (p[u] < p[v]) p[v] = u;
	else p[u] = v;
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		fill(p.begin(), p.end(), -1);
		int v;
		cin >> v;
		int E;
		cin >> E;
		vector<tuple<int, int, int>> edge;
		for (int i = 0; i < E; i++) {
			int s, e, cost;
			cin >> s >> e >> cost;
			edge.push_back({ cost,s,e });
		}
		sort(edge.begin(), edge.end());
		int cnt = 0; //v-1인지 확인
		long long ans = 0;
		for (auto k : edge)
		{
			int cost, s, e;
			tie(cost, s, e) = k;
			if (!is_diff_group(s, e)) continue;
			cnt++;
			ans += cost;
			if (cnt == v - 1)break;
		}
		cout << "#" << t << " " << ans << '\n';

	}
}