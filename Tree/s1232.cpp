#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#define tc 10
using namespace std;

string root[1002] = {};
string lc[1002] = {};
string rc[1002] = {};
stack<string> st;
int res = 0;
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

void Postorder(int cur) {
    if (lc[cur] != " ")Postorder(stoi(lc[cur]));
    if (rc[cur] != " ")Postorder(stoi(rc[cur]));
    if (isdigit(root[cur][0])) st.push(root[cur]);
    else {
        string a, b;
        a = st.top();
        st.pop();
        b = st.top();
        st.pop();
        if (root[cur][0] == '+') res = (stoi(b) + stoi(a));
        else if (root[cur][0] == '-') res = (stoi(b) - stoi(a));
        else if (root[cur][0] == '/') res = (stoi(b) / stoi(a));
        else if (root[cur][0] == '*') res = (stoi(b) * stoi(a));
        st.push(to_string(res));


    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 1; i <= tc; i++) {
        int n;
        cin >> n; // cin은 버퍼가 남아있음
        cin.ignore(); // 입력 버퍼 지우기
        fill(root, root + 1002, " ");
        fill(lc, lc + 1002, " ");
        fill(rc, rc + 1002, " ");
        while (!st.empty())st.pop();
        res = 0;
        for (int j = 1; j <= n; j++) {
            string s;
            string sep = " ";
            getline(cin, s);
            vector<string> result = split(s, sep);
            int cnt = 0;
            for (auto res : result) {
                if (cnt == 1) root[j] = res;
                else if (cnt == 2)lc[j] = res;
                else if (cnt == 3) rc[j] = res;
                cnt++;
            }
        }
        cout << "#" << i << ' ';
        Postorder(1);
        cout << res << '\n';
    }

}