#include <iostream>
using namespace std;
int n;
int d[1005];
int mod = 10007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    d[1] = 1;
    d[2] = 3;
    for (int i = 3; i <= n; i++) {
        d[i] = (d[i - 1] + d[i - 2] * 2) % mod;
    }

    cout << d[n];
}



//D[i] = 2*i 직사각형을 채우는 방법의 수
//D[i] = D[i-1] + D[i-2]*2
//D[1] = 1, D[2] = 3


