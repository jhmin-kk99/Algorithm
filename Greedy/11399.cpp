#include<iostream>
#include<algorithm>
using namespace std;
int N;
int s[1005], d[1005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> s[i];

    sort(s, s + N);
    d[0] = s[0];
    for (int i = 1; i < N; i++)
        d[i] = d[i - 1] + s[i];

    int sum = 0;
    for (int i = 0; i < N; i++)
        sum += d[i];

    cout << sum;

}
