#include <iostream>
#include <algorithm>
using namespace std;
int n;
int d[505][505], s[505][505];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> s[i][j];
        }
    }

    d[1][1] = s[1][1];

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + s[i][j];
        }
    }

    cout << *max_element(d[n] + 1, d[n] + n + 1);
}



//1. 테이블 정하기
//D[i][j] = i층에서 j번째 인덱스를 취했을 때 합의 최댓값 
//j번째 인덱스의 값은 포함한다.
//2. 점화식 찾기
//D[i][j] = max(D[i-1][j-1]+s[i][j] , D[i-1][j]+s[i][j])
//이차원 배열에서 두 인덱스 모두 1-indexed로 하면
//점화식을 깔끔하게 정리가능함
//3. 초기값 정하기
//D[1][1] = s[1][1] 



