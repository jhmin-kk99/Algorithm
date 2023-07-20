#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int par[10002];

int vis[10002];
int cnt = 1;

void dfs(int cur, vector<int> adj[]) { //부모배열 채우기
    for (int nxt : adj[cur]) {
        par[nxt] = cur;
        cnt++;
        dfs(nxt, adj);
    }
}

int find_par(int a) {
    if (vis[a]) return a;
    if (a == 0) return 0;
    vis[a] = 1;
    find_par(par[a]);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        int v, e, a, b;
        cin >> v >> e >> a >> b;
        fill(par, par + 10002, 0);
        fill(vis, vis + 10002, 0);
        vector<int> adj[10002];
        for (int i = 0; i < e; i++) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
        }
        dfs(1, adj);
        find_par(a);
        int p = find_par(b);
        cnt = 1;
        dfs(p, adj);
        cout << "#" << tc << ' ' << p << ' ' << cnt << '\n';
    }

}