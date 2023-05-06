#include<iostream>
#include<algorithm>
using namespace std;
int n;
int A[52], B[52];

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }
    sort(A, A + n, cmp);
    sort(B, B + n);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += A[i] * B[i];
    }
    cout << ans;
}





