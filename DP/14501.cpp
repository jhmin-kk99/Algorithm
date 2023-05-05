#include <iostream>
#include <algorithm>

using namespace std;
int n;
int d[21], T[21], P[21];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> T[i] >> P[i];
    }
    for (int i = 1; i <= n; i++) {
        d[i] = max(d[i], d[i - 1]); //d[i]값 확정
        for (int j = 1; j <= i; j++) {
            if (i == j + T[j] - 1) {
                d[i] = max(d[i], d[j - 1] + P[j]); //d[i]값 갱신
            }
        }
    }
    cout << d[n];

    //d[i] : i-1번째 날까지 상담을 했을 때 벌 수 있는 최대 금액
    //for (int i = 1; i <= n; ++i) {
    //    // d[i]값 확정
    //    d[i] = max(d[i], d[i - 1]);

    //    // i번째 날 상담을 할 경우 i+T[i]-1은 상담이 종료되는 날
    //    if (i + T[i] - 1 <= n) // 상담이 n일 이전에 종료될 경우
    //        d[i + T[i]] = max(d[i + T[i]], d[i] + P[i]); // d[i+T[i]] 갱신
    //}
    //cout << max(d[n], d[n + 1]);
}

//D[i] = i일까지 상담을 했을 때 최대 수익 
