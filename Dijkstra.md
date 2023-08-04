# 다익스트라 알고리즘

다익스트라 알고리즘 = 하나의 시작점으로부터 다른 모든 정점까지의 최단 거리를 
구하는 알고리즘

우선순위 큐를 이용한 다익스트라 알고리즘

1. 우선순위 큐에 (0, 시작점)을 추가
2. 우선순위 큐에서 거리가 가장 작은 원소를 선택, 해당 거리가 최단 거리 테이블에
있는 값과 다를 경우 넘어감
3. 원소가 가리키는 정점을 v라고 할 때, v와 이웃한 정점들에 대해 최단 거리 테이블 값
보다 v를 거쳐가는 것이 더 작은 값을 가질 경우 최단 거리 테이블의 값을 갱신하고 우선
순위 큐에 (거리, 이웃한 정점의 번호)를 추가
4. 우선순위 큐가 빌 때 까지 2,3번 과정을 반복


```
#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int v,e,st,en;

// {비용, 정점 번호}
vector<pair<int,int>> adj[1005];
const int INF = 0x3f3f3f3f;
int d[1005]; // 최단 거리 테이블
int pre[1005];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> v >> e;
  fill(d,d+v+1,INF);
  while(e--){
    int u,v,w;
    cin >> u >> v >> w;
    adj[u].push_back({w,v});
  }
  cin >> st >> en;

  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
  d[st] = 0;
  // 우선순위 큐에 (0, 시작점) 추가
  pq.push({d[st],st});
  while(!pq.empty()){
    auto cur = pq.top(); pq.pop(); // {비용, 정점 번호}    
    // 거리가 d에 있는 값과 다를 경우 넘어감
    if(d[cur.Y] != cur.X) continue;
    for(auto nxt : adj[cur.Y]){
      if(d[nxt.Y] <= d[cur.Y]+nxt.X) continue;
      // cur를 거쳐가는 것이 더 작은 값을 가질 경우
      // d[nxt.Y]을 갱신하고 우선순위 큐에 (거리, nxt.Y)를 추가
      d[nxt.Y] = d[cur.Y]+nxt.X;
      pq.push({d[nxt.Y],nxt.Y});
      pre[nxt.Y] = cur.Y;
    }
  }

  cout << d[en] << '\n';
  vector<int> path;
  int cur = en;
  while(cur != st){
    path.push_back(cur);
    cur = pre[cur];
  }
  path.push_back(cur);
  reverse(path.begin(), path.end());
  cout << path.size() << '\n';
  for(auto x : path) cout << x << ' ';
}
```


```
#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int v,e,st;

// {비용, 정점 번호}
vector<pair<int,int>> adj[20005];
const int INF = 0x3f3f3f3f;
int d[20005]; // 최단 거리 테이블
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> v >> e >> st;
  fill(d,d+v+1,INF);
  while(e--){
    int u,v,w;
    cin >> u >> v >> w;
    adj[u].push_back({w,v});
  }

  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
  d[st] = 0;
  // 우선순위 큐에 (0, 시작점) 추가
  pq.push({d[st],st});
  while(!pq.empty()){
    auto cur = pq.top(); pq.pop(); // {비용, 정점 번호}    
    // 거리가 d에 있는 값과 다를 경우 넘어감
    if(d[cur.Y] != cur.X) continue;
    for(auto nxt : adj[cur.Y]){
      if(d[nxt.Y] <= d[cur.Y]+nxt.X) continue;
      // cur를 거쳐가는 것이 더 작은 값을 가질 경우
      // d[nxt.Y]을 갱신하고 우선순위 큐에 (거리, nxt.Y)를 추가
      d[nxt.Y] = d[cur.Y]+nxt.X;
      pq.push({d[nxt.Y],nxt.Y});
    }
  }

  for(int i = 1; i <= v; i++){
    if(d[i] == INF) cout << "INF\n";
    else cout << d[i] << "\n";
  }
}
```
