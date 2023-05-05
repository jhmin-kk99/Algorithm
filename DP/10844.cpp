#include<iostream>
using namespace std;
#define  mod 1000000000
typedef long long ll;
int n;
ll d[105][10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    fill(d[1] + 1, d[1] + 10, 1);
    //n=1 , 1 2 3 4 5 6 7 8 9  => 9
    //n=2 , 10 12 21 23 32 34 43 45 54 56 65 67 76 78 87 89 98  => 17

    //d[i][0] = d[i-1][1]
    // d[i][1] = (d[i-1][0] + d[i-1][2])
    //...
    //d[i][9] = d[i-1][8]

    //d[i][j] = i자리 수 중 j로 끝나는 계단 수의 개수

    for (int i = 2; i <= n; i++) {
        d[i][0] = d[i - 1][1];
        d[i][9] = d[i - 1][8];
        for (int j = 1; j <= 8; j++) {
            d[i][j] = (d[i - 1][j - 1] + d[i - 1][j + 1]) % mod;
        }
    }
    ll sum = 0;
    for (int i = 0; i <= 9; i++) {
        sum += d[n][i];
    }
    sum %= mod;
    cout << sum;
}




