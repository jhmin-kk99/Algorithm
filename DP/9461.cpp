//9461

#include <iostream>

using namespace std;

#define num 101

int t;

long long d[101] = {};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    d[1] = 1; d[2] = 1; d[3] = 1; d[4] = 2; d[5] = 2; d[6] = 3; d[7] = 4; d[8] = 5;

    for (int i = 9; i <= num; i++) {

        d[i] = d[i - 1] + d[i - 5];

    }

    cin >> t;

    while (t--) {

        int n;
        cin >> n;
        cout << d[n] << '\n';

    }

}
//6 2 7 흰

//7 1 8 색

//------------------규칙------------------

//8 4 9 흰

//9 5 10 색

//10 6 11 흰

//11 7 12 색

//12 8 13 흰


//D[i] = i번째 정삼각형의 변의 길이
//D[i] = D[i-1] + D[i-5]
//D[8]까지 초기값
