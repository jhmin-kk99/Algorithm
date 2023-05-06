#include<iostream>
using namespace std;
int n, k;
int A[12];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        ans += k / A[i];
        k %= A[i];
    }
    cout << ans;

}

// A[i] 가 A[i-1]의 배수이므로 가능함
// 500 50 10 1 로 계산하는 것을 생각해보면 됨


