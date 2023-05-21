#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, A[1005], d[1005], pre[1005]; //역추적
vector<int> ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    fill(d, d + n, 1);
    fill(pre, pre + n, -1);
    int check = -1, flag = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (A[i] > A[j]) {
                if (d[j] + 1 > d[i]) {
                    pre[i] = j;
                }
                d[i] = max(d[i], d[j] + 1);
            }
        }
        if (d[i] > check) flag = i;
        check = max(check, d[i]);

    }
    ans.push_back(A[flag]);
    while (flag >= 0) {
        int k = pre[flag];
        if (A[k] > 0)
            ans.push_back(A[k]);
        flag = k;
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto c : ans) {
        cout << c << ' ';
    }
    return 0;
}