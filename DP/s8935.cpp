#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int tc;
//dp[n_i][m_i][skip][get]
//n_i : n봉지의 과자 중 n_i번째를 보고있는 상태(0과 n은 각각 왼쪽 끝, 오른쪽 끝을 의미한다.
//m_i : m봉지의 과자 중 고른 과자의 수
//skip : m봉지 중 스킵한 개수
//get : 위 상태일 때 바로 직전에 과자를 get했는가 (했으면 1)
int dp[3001][101][101][2];
vector<int> va, vb;
int n, m;

int go(int n_i, int m_i, int skip, int get) {
	if (n_i == n && m_i == m) return 0;
	int& ans = dp[n_i][m_i][skip][get];
	//ans와 dp[n_i][m_i][skip][get]의 주소 값이 같음

	if (ans != -1)return ans; //한번이라도 골랐으면 
	ans = 0; // 맨 처음 초기화 

	// 고르지x
	if (get == 0) {
		//만약 n봉지를 다 고르지 않은상태일때
		if (n_i < n) {
			ans = max(ans, go(n_i + 1, m_i, skip, 1) + va[n_i]); //고르거나
			ans = max(ans, go(n_i + 1, m_i, skip, 0)); //고르지 않거나
		}
		//만약 m봉지를 다 고르지 않은상태일때
		if (m_i + skip < m) {
			ans = max(ans, go(n_i, m_i + 1, skip, 1) + vb[m_i]); //고르거나
			ans = max(ans, go(n_i, m_i, skip + 1, 0)); //고르지 않거나
		}
	}
	// 이미 고른 경우, n을 스킵하거나 m을 스킵하거나
	else {
		//만약 n봉지를 다 고르지 않은상태일때
		if (n_i < n) {
			ans = max(ans, go(n_i + 1, m_i, skip, 0)); //고르지 않거나
		}
		//만약 m봉지를 다 고르지 않은상태일때
		if (m_i + skip < m) {
			ans = max(ans, go(n_i, m_i, skip + 1, 0)); //고르지 않거나
		}
	}
	return ans;
}




int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		//1. memset은 - 1, 0으로 채울 거 아니면 쓰지 말자.아니면 빠르게 채워야 할 때나 쓰자.
		//2. fill은 느리지만 안전하다.
		//3. 정말 많은 테스트 케이스가 있는 거 아니면 fill 쓰자.
		memset(dp, -1, sizeof(dp));
		vector<int>().swap(va);
		vector<int>().swap(vb);
		cin >> n;
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			va.push_back(a);
		}
		cin >> m;
		for (int i = 0; i < m; i++) {
			int b;
			cin >> b;
			vb.push_back(b);
		}
		vb.push_back(-987654321);
		sort(vb.begin(), vb.end(), greater<int>());

		cout << "#" << t << " " << go(0, 0, 0, 0) << '\n';
	}

}