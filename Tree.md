# 트리   
____   
<바킹독>   
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
      if(p[cur] == nxt) continue;   
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

<큰돌>   
>* 자식노드와 부모노드로 이루어진 계층적인 구조를 가지며 __무방향__ 그래프(undirected graph)의 일종이자 사이클이 없는 자료구조를 의미   
>* 그래프의 하위 집합
>* V - 1 = E
>* 임의의 두 노드 사이의 경로는 '유일무이'하게 존재함.
>* 즉, 트리 내의 어떤 노드와 어떤 노드까지의 경로는 반드시 있으며 하나밖에 없음.
>* 루트노드부터 탐색하는게 좋다.
>* 루트노드/ 내부노드/ 리프노드
>* 깊이 : 트리에서의 깊이는 각각의 노드마다 다르며 루트 노드에서 특정 노드까지 최단거리로 갔을 때의 거리를 말함.
>* 높이 : 트리의 높이는 루트 노드부터 리프 노드까지의 거리 중 가장 긴 거리를 의미
>* 레벨 : 트리의 레벨은 주어지는 문제마다 조금씩 다르지만 보통 깊이와 같은 의미를 지님.
>* 서브트리 : 트리 내의 하위 집합.
   
   
   
>* 이진트리 : 각각의 노드의 자식노드의 수가 2개 이하로 구성되어 있는 트리   
>* 완전 이진 트리(complete binary tree) : 왼쪽에서부터 채워져 있는 이진트리. 마지막 레벨을 제외하고는 모든 레벨이 완전히 채워져 있으며 마지막 레벨의 경우 왼쪽부터 채워져 있음.
>* 포화 이진 트리(perfect binary tree) : 모든 노드가 꽉 차 있는 이진트리
>* 균형 이진 트리(balanced binary tree) : 모든 노드의 왼쪽 하위트리와 오른쪽 하위 트리의 차이가 1이하인 트리. map, set을 구성하는 레드블랙트리는 균형이진트리 중 하나임.
>* 정 이진 트리(full binary tree)_ : 자식 노드가 0 또는 2개인 이진트리
>* 변질 이진 트리(degenerate binary tree) : 자식 노드가 하나밖에 없는 이진트리
   
>* 이진탐색트리(BST, Binary Search Tree)
>* 이진트리의 일종. 오른쪽 하위 트리에는 "노드의 값보다 큰 값"이 있는 노드만 포함되고, 왼쪽 하위 트리에는 "노드의 값보다 작은값"이 들어있는 트리
>* 이렇게 두면 "검색"을 하기에 용이함.
>* 시간복잡도 : 균형잡히게 분포가 되었다면 탐색,삽입,삭제,수정 모두 O(logN)
>* 그러나 이는 삽입 순서에 따라 달라짐. 예를 들어 1,2,3 이렇게 삽입이 되어 이진탐색트리가 완성이 되었다면, "선형적"인 자료구조가 되어버림.   
      
>* 그러나 삽입순서가 어떻게 되든 트리의 노드들을 회전시키는 등의 방법을 통해서 "균형잡히게 만든" 이진탐색트리에서 발전된 트리로는 AVL트리, 레드블랙트리가 있음. 예를 들어 map이라는 자료구조는 삽입, 탐색, 삭제, 수정의 시간복잡도가 모두 O(logN)임을 보장받는데 그 이유가 균형잡힌 트리인 레드블랙트리를 기반으로 구현되어있기 때문.   



   

 

| 문제 번호 | 정답 코드 |  중요한 문제(아이디어) | 
| :--: | :--: |:--: |
| __[Baekjoon 11725번](https://www.acmicpc.net/problem/11725)__   | [Solution](https://github.com/jhmin-kk99/Algorithm-Study/blob/main/Tree/11725.cpp)    | |
| __[Baekjoon 1991번](https://www.acmicpc.net/problem/1991)__   | [Solution](https://github.com/jhmin-kk99/Algorithm-Study/blob/main/Tree/1991.cpp)    |_입력받을때 주의_|
| __[Baekjoon 25516번](https://www.acmicpc.net/problem/25516)__   | [Solution](https://github.com/jhmin-kk99/Algorithm-Study/blob/main/Tree/25516.cpp)    | |
| __[SW Expert 1231번](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV140YnqAIECFAYD&categoryId=AV140YnqAIECFAYD&categoryType=CODE&problemTitle=1231&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=&pageSize=10&pageIndex=1)__   | [Solution](https://github.com/jhmin-kk99/Algorithm-Study/blob/main/Tree/1231.cpp)    |split함수, 문자열|
| __[SW Expert 1233번](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV140YnqAIECFAYD&categoryId=AV140YnqAIECFAYD&categoryType=CODE&problemTitle=1233&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=&pageSize=10&pageIndex=1)__   | [Solution](https://github.com/jhmin-kk99/Algorithm-Study/blob/main/Tree/1233.cpp)    ||
| __[SW Expert 1232번](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV140YnqAIECFAYD&categoryId=AV140YnqAIECFAYD&categoryType=CODE&problemTitle=1232&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=&pageSize=10&pageIndex=1)__   | [Solution](https://github.com/jhmin-kk99/Algorithm-Study/blob/main/Tree/1232.cpp)    ||
| __[SW Expert 1248번](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV140YnqAIECFAYD&categoryId=AV140YnqAIECFAYD&categoryType=CODE&problemTitle=1248&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=&pageSize=10&pageIndex=1)__   | [Solution](https://github.com/jhmin-kk99/Algorithm-Study/blob/main/Tree/1248.cpp)    ||
