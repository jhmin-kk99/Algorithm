#include <iostream>
using namespace std;

typedef long long ll;
int k, n;
int arr[10005];

bool solve(ll x) {
    ll cur = 0;
    // 랜선이 10000개이고, 길이가 전부 2^31-1일 때 solve(1)과 같은 것이 호출되면
    // cur의 값이 int 범위를 넘어설 수 있음
    for (int i = 0; i < k; i++) cur += arr[i] / x;
    return cur >= n;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> k >> n;
    for (int i = 0; i < k; i++) cin >> arr[i];
    ll st = 1;
    ll en = 0x7fffffff; // 2^31 - 1
    while (st < en) {
        ll mid = (st + en + 1) / 2; //무한루프 주의, st + en 이 int 범위를 넘길 수 있음
        if (solve(mid)) st = mid;
        else en = mid - 1;
    }
    cout << st;
}