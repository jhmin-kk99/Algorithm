#include <iostream>
#include <algorithm>
using namespace std;
string s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    int num = 0;
    int ans = 0;
    int flag = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            if (flag == 0) {
                ans *= 10;
                ans += (s[i] - '0');
            }
            else {
                num *= 10;
                num += (s[i] - '0');
            }
        }
        else {
            if (flag == 1) {
                ans += num;
                num = 0;
            }
            else if (flag == 2) {
                ans -= num;
                num = 0;
                continue;
            }

            if (s[i] == '+') {
                flag = 1;
            }
            else {
                flag = 2;
            }
        }
    }
    if (flag == 1) {
        ans += num;
    }
    else if (flag == 2) {
        ans -= num;
    }
    cout << ans;

}

// - 가 등장하면 그 순간부터 모든 수를 빼면 됨