# 최소 신장 트리
> 신장 트리 : 주어진 방향성이 없는 그래프의 부분그래프(Subgraph)들 중에서   
> 모든 정점을 포함하는 트리를 의미       
> 트리의 성질로부터 주어진 그래프의 정점이 v개일 때, 간선은 v-1개   
> 최소 신장 트리 : 신장 트리 중 간선의 합이 최소인 트리   

   
<크루스칼 알고리즘>   
1. 간선을 크기의 오름차순으로 정렬하고 제일 낮은 비용의 간선을 선택   
2. 현재 선택한 간선이 정점 u,v를 연결하는 간선이라고 할 때 만약 u와 v가 같은 그룹이라면   
아무 것도 하지 않고 넘어감, u와 v거 다른 그룹이라면 같은 그룹으로 만들고 현재 선택한 간선을   
최소 신장 트리에 추가   
3. 최소 신장 트리에 v-1개의 간선을 추가시켰다면 과정을 종료, 그렇지 않다면 그 다음으로 비용이   
작은 간선을 선택한 후 2번 과정을 반복   
union find를 알고 있어야 효울적으로 구현 가능   
[Unionfind](https://maetdori.tistory.com/entry/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-Kruskal-Algorithm-Union-Find-%ED%81%AC%EB%A3%A8%EC%8A%A4%EC%B9%BC-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EC%9C%A0%EB%8B%88%EC%98%A8-%ED%8C%8C%EC%9D%B8%EB%93%9C)

```
ex) BOJ 1197 中

vector<int> p(10005, -1);

int find(int x){
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool is_diff_group(int u, int v){
    u = find(u); v = find(v);
    if(u == v) return 0; //부모가 같으면
    if(p[u] == p[v]) p[u]--; // 부모로 만듦
    if(p[u] < p[v]) p[v] = u; //연결
    else p[u] = v;
    return 1;
}

int v, e;
// {비용 , 정점 1, 정점 2}
tuple<int,int,int> edge[100005];

sort(edge, edge + e);
int cnt = 0;
int cost, a, b;
tie(cost, a, b) = edge[i];
if(!is_diff_group(a, b)) continue;
cout << cost << ' ' << a << ' ' << b;
cnt++;
if(cnt == v - 1) break;
}
```   

<프림 알고리즘>   
1. 임의의 정점을 선택해 최소 신장 트리에 추가, 해당 정점과 연결된 모든 간선을 우선순위 큐에 추가     
2. 우선순위 큐에서 비용이 가장 작은 간선을 선택       
3. 만약 해당 간선이 최소 신장 트리에 포함된 두 정점을 연결한다면 아무 것도 하지 않고 넘어감,   
해당 간선이 최소 신장 트리에 포함된 정점 u와 포함되지 않은 정점 v를 연결한다면 해당 간선과 정점 v   
를 최소 신장 트리에 추가 후 정정 v과 최소 신장 트리에 포함되지 않는 정점을 연결하는 모든 간선을 우선순위   
큐에 추가   
4. 최소 신장 트리에 v-1개의 간선이 추가될 때 까지 2,3번 과정을 반복
```
#define X first
#define Y second

int v,e;
         
vector<pair<int,int>> adj[10005]; //{비용, 정점 번호} 

bool chk[10005]; //chk[i] : i번째 정점이 최소 신장 트리에 속해있는가?
int cnt = 0; //현재 선택된 간선의 수
priority_queue< tuple<int,int,int>, // 자료형 (비용, 정점 1, 정점 2) 
                vector<tuple<int,int,int>>, // 구현체
                greater<tuple<int,int,int>> > pq; // 비교연산자(작은수부터)

                //가중치의 합만 필요한 경우, {비용 , 정점2}로 해결 가능

chk[1] = 1;
for(auto nxt : adj[1])
    pq.push({nxt.X, 1, nxt.Y});
while(cnt < v - 1){
    int cost, a, b;
    tie(cost, a, b) = pq.top(); pq.pop();
    if(chk[b]) continue;
    cout << cost << ' '<< a << ' '<< b << '\n';
    chk[b] = 1;
    cnt++;
    for(auto nxt : adj[b]){
     if(!chk[nxt.Y])
        pq.push({nxt.X, b, nxt.Y});
	}
}
```



| 문제 번호 | 정답 코드 |  중요한 문제(아이디어) |    
| :--: | :--: |:--: |   
| __[Baekjoon 1197번](https://www.acmicpc.net/problem/1197)__   | [Solution](https://github.com/jhmin-kk99/Algorithm-Study/blob/main/MST/1197.cpp)    | |
| __[SW Expert 1251번](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV15StKqAQkCFAYD)__   | [Solution](https://github.com/jhmin-kk99/Algorithm-Study/blob/main/MST/1251.cpp)    | |
| __[Baekjoon 1368번](https://www.acmicpc.net/problem/1368)__   | [Solution](https://github.com/jhmin-kk99/Algorithm-Study/blob/main/MST/1368.cpp)    |_가상의 정점_|
