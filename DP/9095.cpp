#include <iostream>
#include <algorithm>
using namespace std;
int d[12];
int n, t;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        d[1] = 1;
        d[2] = 2;
        d[3] = 4;

        for (int i = 4; i <= n; i++)
        {
            d[i] = d[i - 1] + d[i - 2] + d[i - 3];
        }
        cout << d[n] << '\n';
    }

}
//바킹독 실전 알고리즘 강의 참고
//1. 테이블 정의하기
//D[i] = i를 1,2,3의 합으로 나타내는 방법의 수
//
//2. 점화식 찾기
//D[4] = ?
//1+1+1+1 , 3+1, 2+1+1, 1+2+1   (D[3])
//1+1+2, 2+2    (D[2])    
//1+3    (D[1])
//D[i] = D[i-1] + D[i-2] + D[i-3]
//
//3. 초기값 정의하기  
//D[1]=1
//D[2]=2
//D[3]=4