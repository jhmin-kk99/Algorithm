#include<iostream>
#include<algorithm>
using namespace std;
int n, A[10005], d[10005][3];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    d[0][0] = 0;
    d[0][1] = A[0];
    for (int i = 1; i < n; ++i) {
        d[i][0] = max({ d[i - 1][0], d[i - 1][1], d[i - 1][2] });
        d[i][1] = d[i - 1][0] + A[i];
        d[i][2] = d[i - 1][1] + A[i];
    }
    cout << *max_element(d[n - 1], d[n - 1] + 3);

    return 0;
}

//포도주 잔을 선택하면 그 잔에 들어있는 포도주는 모두 마셔야 하고, 
//마신 후에는 원래 위치에 다시 놓아야 한다.
//연속으로 놓여 있는 3잔을 모두 마실 수는 없다.
//d[i][j] = i번째 포도주를 마셨을 때 포도주의 최대 양, j는 연속으로 마신 포도주 수
//안마시면 0이고, 2 다음에 마실 수 없음