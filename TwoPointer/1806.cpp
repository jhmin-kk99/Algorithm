#include <iostream>
#include <algorithm>
using namespace std;
int n, s;
int a[100005];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for (int i = 0; i < n; i++)cin >> a[i];
    int MN = 0x7fffffff; //길이
    int tot = a[0];
    int en = 0;
    for (int st = 0; st < n; st++) {
        while (en < n && tot < s) {
            en++;
            if (en != n) tot += a[en];
        }
        if (en == n)break;
        MN = min(MN, en - st + 1);
        tot -= a[st];
    }
    if (MN == 0x7fffffff) MN = 0;
    cout << MN;
}