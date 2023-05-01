#include <iostream>
using namespace std;
int n;
long long d[92][2];


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    // n자리 이친수의 개수

    d[1][1] = 1;
    d[2][0] = 1;
    for (int i = 3; i <= n; i++) {
        d[i][0] = d[i - 1][0] + d[i - 1][1];
        d[i][1] = d[i - 1][0];
    }
    long long ans = d[n][0] + d[n][1];
    cout << ans;

}



//overflow 확인을 하는 습관을 들이자
//개수가 점차 늘어나는 경우 최댓값 넣어보기


//D[i][j] = i자리 이친수의 개수 j는 마지막 자리 수 0 또는 1
//D[i][0] = D[i-1][0] + D[i-1][1]
//D[i][1] = D[i-1][0]
//D[1][1] = 1, D[2][0] = 1, D[3][0] = 1, D[3][1] = 1

