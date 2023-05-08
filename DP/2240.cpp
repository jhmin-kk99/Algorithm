#include<iostream>
#include<algorithm>
using namespace std;
int t, w;
int s[1005], d[1005][32];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t >> w;
    for (int i = 1; i <= t; i++)
        cin >> s[i];

    // 자두가 한 번도 움직이지 않았을 때
    int cnt = 0;
    for (int i = 1; i <= t; i++) {
        if (s[i] == 1) cnt++;
        d[i][0] = cnt;
    }

    for (int i = 2; i <= t; i++) {
        for (int j = 1; j <= w; j++) {
            // 자두가 움직인 횟수가 홀수일 경우 2번 나무, 짝수일 경우 1번 나무에 가게 된다.
            d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + (1 + j % 2 == s[i]);
        }
    }
    cout << *max_element(d[t], d[t] + w + 1);
}
