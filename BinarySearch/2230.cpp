#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int a[100005];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int ans = 0x7fffffff;
    for (int i = 0; i < n; i++) {
        int x = a[lower_bound(a, a + n, a[i] + m) - a] - a[i];
        if (x >= m) {
            ans = min(ans, x);
        }
    }
    cout << ans;
}