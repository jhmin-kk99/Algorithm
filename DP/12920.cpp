#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m;
#define MAX 10005
//n: 물건 종류의 수 , m: 가방 최대 무게
vector<pair<int, int>> d;
int v[MAX], c[MAX], k[MAX];
int D[2005][MAX];
//v : 무게, c : 만족도, k: 물건 개수

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i] >> c[i] >> k[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = k[i]; j > 0; j >>= 1) {
            int num = j - (j >> 1); // right shift하면서 가장 적은 연산을 함(비트 자릿수만큼)
            d.push_back({ v[i] * num, c[i] * num });
        } //비트마스킹으로 부분묶음으로 나눔 (묶음을 하나의 개수로 봄)
          //사용할 수 있는 물건의 개수를 2의 제곱수의 합으로 분리 시키는 것
    }

    for (int i = 0; i < d.size(); i++) { //i를 d.size()보다 작게 (안그러면 에러남)
        for (int j = 1; j <= m; j++) {
            if (j < d[i].first)
                D[i + 1][j] = D[i][j]; //i가 0부터 시작하므로 살짝 변형을 줌
            else
            {
                D[i + 1][j] = max(D[i][j], (D[i][j - (d[i].first)] + d[i].second));
            }
        }
    }

    cout << D[d.size()][m];

}
