#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#define tc 10
using namespace std;

string root[202] = {};
string lc[202] = {};
string rc[202] = {};
bool valid = true;

vector<string> split(string& s, string& sep) {
    vector<string> ret;
    int pos = 0;
    while (pos < s.size()) {
        int nxt_pos = s.find(sep, pos);
        if (nxt_pos == -1) nxt_pos = s.size();
        if (nxt_pos - pos > 0)
            ret.push_back(s.substr(pos, nxt_pos - pos));
        pos = nxt_pos + sep.size();
    }
    return ret;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 1; i <= tc; i++) {
        valid = true;
        int n;
        cin >> n; // cin은 버퍼가 남아있음
        cin.ignore(); // 입력 버퍼 지우기
        fill(root, root + 202, " ");
        fill(lc, lc + 202, " ");
        fill(rc, rc + 202, " ");
        for (int j = 1; j <= n; j++) {
            string s;
            string sep = " ";
            getline(cin, s);
            vector<string> result = split(s, sep);
            if (!isdigit(result[1][0])) { //숫자인지 기호인지 확인
                if (result.size() < 4) valid = false;
                //기호인 경우 , 사칙연산을 위해 자식이 둘이어야함
            }

        }
        cout << "#" << i << ' ';
        if (valid) cout << 1 << '\n';
        else cout << 0 << '\n';
    }

}