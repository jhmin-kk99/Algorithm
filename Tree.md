# 트리   
____   
>*  _트리 : 무방향이면서 사이클이 없는 연결그래프(Undirected Acyclic Connected Graph)_
>*  _= 연결 그래프이면서 임의의 간선을 제거하면 연결 그래프가 아니게 되는 그래프_
>*  _= 임의의 두 점을 연결하는 simple path(정점이 중복해서 나오지 않는 경로)가 유일한 그래프_
>*  _= V개의 정점을 가지고 V-1개의 간선을 가지는 연결 그래프_
>*  _= 사이클이 없는 연결 그래프이면서 임의의 간선을 추가하면 사이클이 생기는 그래프_
>*  _= V개의 정점을 가지고 V-1개의 간선을 가지는 Achclic(=사이클이 없는) 그래프_
>*  _BFS/DFS_
```
<BFS 예시 코드 - 부모와 depth 배열 채우기>   
vector<int> adj[10]      
int depth[10];     
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
      depth[nxt] = depth[cur] + 1;   
    }   
  }   
}   
```
```
<DFS 예시 코드 1 - 부모와 depth 배열 채우기, 비재귀>   
vector<int> adj[10]      
int p[10];  
int depth[10];
void dfs(int root){   
  stack<int> s;   
  s.push(root);   
  while(!s.empty()){   
    int cur = s.top();   
    s.pop();   
    cout << cur << ' ';   
    for(auto nxt : adj[cur]){   
      if(p[cur] ==nxt) continue;   
      s.push(nxt);   
      p[nxt] = cur;
      depth[nxt] = depth[cur] + 1;   
    }   
  }   
}   
```
```
<DFS 예시 코드 2 - 부모와 depth 배열 채우기, 재귀>   
vector<int> adj[10]      
int p[10];     
void dfs(int cur){   
   cout << cur << ' ';
   for(auto nxt : adj[cur]){
    if(p[cur] == nxt) continue;
    p[nxt] = cur;
    depth[nxt] = depth[cur] + 1;
    dfs(nxt);
   }  
}   
```
```
<DFS 예시 코드 3 - 단순 순회, 재귀>   
vector<int> adj[10]      
void dfs(int cur, int par){   
   cout << cur << ' ';
   for(auto nxt : adj[cur]){
    dfs(nxt, cur);
   }  
}   
// call dfs(1, 0);
```
>*  _이진 트리의 순회_
>*  _왼쪽 자식과 오른쪽 자식을 저장하게끔 코드 구성_
>*  _레벨 순회(Level-order Traversal) : 루트를 시작점으로 BFS_
>*  _전위 순회(Preorder Traversal) : DFS와 방문 순서가 동일(재귀로 구현)_
>> 1. 현재 정점을 방문한다.    
>> 2. 왼쪽 서브트리를 전위 순회한다.   
>> 3. 오른쪽 서브 트리를 전위 순회한다.
>*  _중위 순회(Inorder Traversal) : 재귀로 구현_
>> 1. 왼쪽 서브트리를 중위 순회한다.    
>> 2. 현재 정점을 방문한다.   
>> 3. 오른쪽 서브 트리를 중위 순회한다.
>*  _후위 순회(Postorder Traversal) : 재귀로 구현_
>> 1. 왼쪽 서브트리를 후위 순회한다.    
>> 2. 오른쪽 서브 트리를 후위 순회한다.   
>> 3. 현재 정점을 방문한다.

| 문제 번호 | 정답 코드 |  중요한 문제(아이디어) | 
| :--: | :--: |:--: |
| __[Baekjoon 11725번](https://www.acmicpc.net/problem/11725)__   | [Solution](https://github.com/jhmin-kk99/Algorithm-Study/blob/main/Tree/11725.cpp)    | |
| __[Baekjoon 1991번](https://www.acmicpc.net/problem/1991)__   | [Solution](https://github.com/jhmin-kk99/Algorithm-Study/blob/main/Tree/1991.cpp)    |_입력받을때 주의_|
| __[Baekjoon 25516번](https://www.acmicpc.net/problem/25516)__   | [Solution](https://github.com/jhmin-kk99/Algorithm-Study/blob/main/Tree/25516.cpp)    | |
