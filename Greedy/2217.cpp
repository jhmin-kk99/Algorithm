#include<iostream>
#include<algorithm>
using namespace std;
int n; //1~100000
int A[100002];

bool cmp(int a, int b) {
    return a > b;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    sort(A, A + n, cmp);

    //모든 로프 다 쓰면 (가장 작은 거 * 로프 수 ) 
    //가장 최대중량 큰 로프 부터...
    //20 15 14 13 12 5 3 1 이라면
    // max(20 , (15 * 2) , (14 * 3) (13 * 4) (12 * 5) (5 * 6) (3 * 7) (1 * 8))
    int ans = A[0];
    for (int i = 1; i < n; i++)
    {
        int t = A[i] * (i + 1);
        ans = max(ans, t);
    }
    cout << ans;

}





