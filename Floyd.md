# 플로이드 알고리즘

플로이드 알고리즘 = 모든 정점 쌍 사이의 최단 거리를 구하는 알고리즘

```
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f; 
//무한, 알고리즘의 계산과정에서 INF + INF 를 할 수 있음, overflow 막기 위함
int d[105][105];
int n, m;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i = 1; i <= n; i++)
    fill(d[i], d[i]+1+n, INF);
  while(m--){
    int a,b,c;
    cin >> a >> b >> c;
    d[a][b] = min(d[a][b], c);
  }
  for(int i = 1; i <= n; i++) d[i][i] = 0;

  for(int k = 1; k <= n; k++) //중간에 거쳐가야 할 원소
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++)
        d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
  // if(d[i][j] > d[i][k] + d[k][j]) d[i][j] = d[i][k] + d[k][j]; 
  // 를 하게 되면 조금 더 빠를 수 있음 (연산보다 대입이 느림)
  // 3중 for문이지만, 단순 사칙연산이 주를 이루기 때문에, 정점 1000개까지는 고려할만함
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      if(d[i][j] == INF) cout << "0 ";
      else cout << d[i][j] << ' ';
    }
    cout << '\n';
  }
}
```

경로 복원 방법

```
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int d[105][105];
int nxt[105][105];
int n, m;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n >> m;
  for(int i = 1; i <= n; i++)
    fill(d[i], d[i]+1+n, INF);
  while(m--){
    int a,b,c;
    cin >> a >> b >> c;
    d[a][b] = min(d[a][b], c);
    nxt[a][b] = b;
  }
  for(int i = 1; i <= n; i++) d[i][i] = 0;

  for(int k = 1; k <= n; k++)
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++)
        if(d[i][k] + d[k][j] < d[i][j]){
          d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
          nxt[i][j] = nxt[i][k];
        }
  
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      if(d[i][j] == INF) cout << "0 ";
      else cout << d[i][j] << ' ';
    }
    cout << '\n';
  }

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      if(d[i][j] == 0 || d[i][j] == INF){
        cout << "0\n";
        continue;
      }
      vector<int> path;
      int st = i;
      while(st != j){
        path.push_back(st);
        st = nxt[st][j];
      }
      path.push_back(j);
      cout << path.size() << ' ';
      for(auto x : path) cout << x << ' ';
      cout << '\n';
    }
  }
}
```