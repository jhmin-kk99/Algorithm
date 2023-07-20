#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
vector<int> adj[32005];
int deg[32005];
queue<int> q;
vector<int> result;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        deg[b]++;
    }
    for (int i = 1; i <= n; i++) {
        if (!deg[i]) q.push(i);
    }
    while (!q.empty()) {
        result.push_back(q.front());
        auto res = q.front();
        q.pop();
        for (auto p : adj[res]) {
            deg[p]--;
            if (!deg[p]) q.push(p);
        }
    }
    for (auto ans : result) cout << ans << ' ';
}