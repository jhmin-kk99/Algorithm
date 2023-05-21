#include<iostream>
#include<algorithm>
using namespace std;
int t;
int a[1000005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        int n;
        long long ans = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int max_value = a[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (a[i] > max_value) max_value = a[i];
            ans += max_value - a[i];
        }
        cout << ans << '\n';
        fill(a, a + n, 0);
    }

    return 0;
}