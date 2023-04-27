#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int num[100005];
int d[100005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;

    d[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
        d[i] = d[i - 1] + num[i];
    }

    while (m--)
    {
        int i, j;
        cin >> i >> j;
        cout << d[j] - d[i - 1] << '\n';

    }
}

//바킹독 실전 알고리즘 강의 참고
//Prefix sum(구간합) (시간복잡도를 줄이는 데 종종 사용)
//1. 테이블 정의하기
//D[i] = 1번째 수부터 i번째 수 까지의 합
//
//2. 점화식 찾기
//
//D[k] = D[k-1]+num[k]
//
//3. 초기값 정의하기  
//D[0] = 0

