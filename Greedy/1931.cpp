#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n; //1~100000
vector <vector<int>> v;
//pair<int, int> s[100005]; //[end time , st time] (바킹독 풀이)

//task scheduling problem

bool cmp(vector<int>& v1, vector<int>& v2) {
    if (v1[1] == v2[1])
        return v1[0] < v2[0];
    else return v1[1] < v2[1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    /*for (int i = 0; i < n; i++)
        cin >> s[i].second >> s[i].first;
    sort(s, s + n);
    int ans = 0;
    int t = 0;
    for (int i = 0; i < n; i++) {
        if (t > s[i].second) continue;
        ans++;
        t = s[i].first;
    }
    cout << ans;
    (바킹독 풀이)
    */

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({ a,b });
    }
    sort(v.begin(), v.end(), cmp);
    /*  for (auto c : v)
      {
          cout << c[0] << ' ' << c[1] << '\n';
      }*/
    int t = v[0][1];
    int count = 1;
    for (int i = 1; i < n; i++) {
        if (v[i][0] >= t)
        {
            t = v[i][1];
            count++;
        }
    }
    cout << count;

}


//1. O(2^n)
//모든 가능한 배정 방법을 확인
//
//2. DP (O(N^2))
//회의를 끝나는 시간이 빠른 순으로, 끝나는 시간이 같다면 시작 시간이 빠른 순으로 정렬
//d[i] : i번째 회의를 마지막으로 진행했을 때 최대 회의의 수
//d[i] = max(d[j]) + 1 (j번째 회의의 끝나는 시간이  i번째 회의의 시작 시간 이하인 모든 j)
//
//3. 그리디
//가능한 회의 중에서 가장 먼저 끝나는 회의 고르기
//
//명제 : 현재 시간이 t라고 할 때, 시작 시간이 t 이상인 모든 회의 중에서 가장 먼저 끝나는 회의를 택하는 것이
//최적해이다.
//
//증명 : 회의 A(시작 시간이 t이상 , 가장 먼저 끝나는 회의)
//대신 회의 B를 택했을 때 더 많은 회의를 배정할 수 있다고 가정
//
//회의 B를 택한 후 그 뒤의 최대 개수를 골랐다고 했을 때, 회의 A를 골랐을 때도
//적어도 그 회의들은 모두 고를 수 있음 + A가 끝난시간과 B가 끝난 시간 사이에 회의가
//있다면 추가로 고를 수 있음 (모순)
//
//매 순간 남아 있는 회의 중에서 가장 먼저 끝나는 회의를 찾으려고 하기보다
//회의를 적절하게 정렬해둔 후에 하나씩 보면서 이 회의를 현재 상황에서 스케쥴에
//넣을 수 있는가를 생각


