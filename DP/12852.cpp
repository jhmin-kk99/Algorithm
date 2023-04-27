#include <iostream>
#include <algorithm>
using namespace std;
int d[1000005], pre[1000005], n;
//pre : 경로 추적 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    d[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        d[i] = d[i - 1] + 1;
        pre[i] = i - 1;
        if (i % 2 == 0 && d[i] > d[i / 2] + 1) {
            d[i] = d[i / 2] + 1;
            pre[i] = i / 2;
        }
        if (i % 3 == 0 && d[i] > d[i / 3] + 1) {
            d[i] = d[i / 3] + 1;
            pre[i] = i / 3;
        }
    }
    cout << d[n] << '\n';
    int cur = n;
    while (true)
    {
        cout << cur << ' ';
        if (cur == 1) break;
        cur = pre[cur];
    }

}

//바킹독 실전 알고리즘 강의 참고
//1. 테이블 정의하기
//D[i] = i를 1로 만드는 연산 횟수의 최솟값
//
//2. 점화식 찾기
//
//D[k]=min(D[k/3],D[k/2],D[k-1])+1
//
//3. 초기값 정의하기  
//D[1] = 0

