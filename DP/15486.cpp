#include <iostream>
#include <algorithm>

using namespace std;
int n;
typedef long long ll;
int T[1500005], P[1500005];
ll d[1500005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> T[i] >> P[i];
    }
    for (int i = 1; i <= n; i++) {
        d[i] = max(d[i], d[i - 1]); //d[i]값 확정

        if (i + T[i] - 1 <= n) {
            d[i + T[i] - 1] = max(d[i - 1] + P[i], d[i + T[i] - 1]);
        }

    }
    cout << d[n];


}

//D[i] = i일까지 상담을 했을 때 최대 수익 
