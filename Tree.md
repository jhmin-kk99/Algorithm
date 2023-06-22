# 트리   
____   
>*  _트리 : 무방향이면서 사이클이 없는 연결그래프(Undirected Acyclic Connected Graph)_
>*  _= 연결 그래프이면서 임의의 간선을 제거하면 연결 그래프가 아니게 되는 그래프_
>*  _= 임의의 두 점을 연결하는 simple path(정점이 중복해서 나오지 않는 경로)가 유일한 그래프_
>*  _= V개의 정점을 가지고 V-1개의 간선을 가지는 연결 그래프_
>*  _= 사이클이 없는 연결 그래프이면서 임의의 간선을 추가하면 사이클이 생기는 그래프_
>*  _= V개의 정점을 가지고 V-1개의 간선을 가지는 Achclic(=사이클이 없는) 그래프_
>*  _BFS/DFS_
<BFS 예시 코드 1 - 부모 배열 채우기>
vector<int> adj[10]   
int p[10];   
void bfs(int root){
  queue<int> q;
  q.push(root);
  while(!q.empty()){
    int cur = q.front();
    q.pop();
    cout << cur << ' ';
    for(auto nxt : adj[cur]){
      if(p[cur] ==nxt) continue;
      q.push(nxt);
      p[nxt] = cur;
    }
  }
}
