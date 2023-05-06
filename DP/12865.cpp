#include<iostream>
#include<algorithm>
using namespace std;
int n, k;
int d[102][100002];
int w[102], v[102];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        cin >> w[i] >> v[i];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (j < w[i]) //물건을 넣을 수 없을 때
                d[i][j] = d[i - 1][j]; //이 전의 최대가치를 가져옴
            else
            {
                d[i][j] = max(d[i - 1][j], d[i - 1][j - w[i]] + v[i]);
            }//물건을 넣지않을 때, 넣을 때를 비교
        }
    }
    cout << d[n][k];


}
//0-1 knapsack 문제
//d[i][j] = 처음부터 i번째까지의 물건을 살펴보고, 배낭의 총 무게가 j일 때 최대가치
//d[3][6]의 값을 구하는 상황
//용량이 6인 배낭에 i=3번째 물건을 넣지 않았을 때의 최댓값 : d[2][6]에 저장되어있음
//용량이 6인 배낭에 i=3번째 물건을 넣을 때의 값은 d[2][6-w[3]]+v[3] = d[2][3]+v[3]
//즉, 최대 가치합으로 물건이 들어가 있는 용량이 3인 배낭에, i=3번째 물건(무게가 3)을 새롭게 넣는 상황이 됨
//d에 저장되는 값은 가치의 합이므로 v[3] 을 더해준 것