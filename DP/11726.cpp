#include <iostream>
#include <algorithm>
using namespace std;
int d[1005], n;
int mod = 10007;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    d[1] = 1; d[2] = 2;
    if (n == 1 || n == 2) {
        cout << d[n];
        return 0;
    }
    /* for (int i = 3; i <= n; i++)
         d[i] = d[i - 1] + d[i - 2];
     cout << (d[n] % mod);*/
     //중간에 int overflow가 생김

    for (int i = 3; i <= n; i++)
        d[i] = (d[i - 1] + d[i - 2]) % mod;
    cout << d[n];

}

//바킹독 실전 알고리즘 강의 참고
//1. 테이블 정의하기
//D[i]=2*i크기의 직사각형을 1*2, 2*1 타일로 채우는 방법의 수
//
//2. 점화식 찾기
//
//D[k] = D[k-1] + D[k-2]
//
//3. 초기값 정의하기  
//D[1] = 1, D[2] = 2

