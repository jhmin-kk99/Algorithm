#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long ans = 0;
vector<int> seqP, seqN;
int n, t;

void seqSum(vector<int> v) {
    while (v.size() > 1) {
        ans += *(v.end() - 1) * *(v.end() - 2);
        v.pop_back();
        v.pop_back();
    }
    if (v.size()) {
        ans += v[0];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        if (t == 1) {
            ans++;
        }
        else if (t > 0) {
            seqP.push_back(t);
        }
        else {
            seqN.push_back(t);
        }
    }
    sort(seqP.begin(), seqP.end());
    sort(seqN.begin(), seqN.end(), greater<int>());
    seqSum(seqP);
    seqSum(seqN);
    cout << ans;
    return 0;
}

