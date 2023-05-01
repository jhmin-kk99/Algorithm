#include <iostream>
#include <algorithm>

using namespace std;
int n;
int d[1005], f[1005];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> f[i];
    }

    fill(d, d + n, 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (f[i] > f[j])
            {
                d[i] = max(d[i], d[j] + 1);
            }
        }
    }

    cout << *max_element(d, d + n);
}



//1 <= N <= 1000 이므로 O(N^2)도 고려해볼 수 있음
//D[i] = i까지의 수열에서 f[i]가 가장 클 때의 증가하는 부분 수열의 최대 길이



