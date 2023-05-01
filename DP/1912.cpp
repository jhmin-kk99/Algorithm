#include <iostream>
#include <algorithm>

using namespace std;
int n;
int d[100005], f[100005];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> f[i];
    }

    for (int i = 1; i <= n; i++) {
        d[i] = max(f[i], d[i - 1] + f[i]); // 새로 시작하거나 , 연속으로 이어붙이거나
    }

    cout << *max_element(d + 1, d + n + 1);

}



//D[i] = i까지 연속합의 최댓값 
//D[i] = max(f[i], D[i-1] + f[i])


