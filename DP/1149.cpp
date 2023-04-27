#include <iostream>
#include <algorithm>
using namespace std;
int s[1005][3], d[1005][3], n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 3; j++)
            cin >> s[i][j];
    d[1][0] = s[1][0]; d[1][1] = s[1][1]; d[1][2] = s[1][2];
    for (int i = 2; i <= n; i++)
    {
        d[i][0] = min(d[i - 1][1], d[i - 1][2]) + s[i][0];
        d[i][1] = min(d[i - 1][0], d[i - 1][2]) + s[i][1];
        d[i][2] = min(d[i - 1][0], d[i - 1][1]) + s[i][2];
    }
    // cout << min(d[n][0], min(d[n][1], d[n][2]));
    cout << *min_element(d[n], d[n] + 3);
    //값을 참조하려면 * 연산자를 붙여야함 *min_element(arr,arr+size) 
    //끝주소 포함 x 
}

//바킹독 실전 알고리즘 강의 참고
//1. 테이블 정의하기
//D[i][0] = i번째 집까지 칠할 때 비용의 최솟값, 단 i번째 집은 빨강
//D[i][1] = i번째 집까지 칠할 때 비용의 최솟값, 단 i번째 집은 초록
//D[i][2] = i번째 집까지 칠할 때 비용의 최솟값, 단 i번째 집은 파랑
//
//2. 점화식 찾기
//D[k][0] = min(D[k - 1][1], D[k - 1][2]) + s[k][0];
//D[k][1] = min(D[k - 1][0], D[k - 1][2]) + s[k][1];
//D[k][2] = min(D[k - 1][0], D[k - 1][1]) + s[k][2];
//
//3. 초기값 정의하기  
//D[1][0], D[1][1], D[1][2]

