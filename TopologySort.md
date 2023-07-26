# 위상정렬 

> 위상정렬 : 사이클이 없는 방향 그래프(Directed Acyclic Graph)에서 간선으로 주어진 정점 간 선후관계를
위배하지 않도록 나열하는 정렬   

> 구현의 편의를 위한 성질   
1. 정점과 간선을 실제로 지울 필요 없이 미리 indegree의 값을 저장했다가 매번
뻗어나가는 정점들의 indegree 값만 1 감소시켜도 과정을 수행 가능   
2. indegree가 0인 정점을 구하기 위해 매번 모든 정점들을 다 확인하는 대신 목록   
을 따로 저장하고 있다가 직전에 제거한 정점에서 연결된 정점들만 추가   

<위상 정렬 알고리즘>   
1. 맨 처음 모든 간선을 읽으며 indegree 테이블을 채움   
2. indegree가 0인 정점들을 모두 큐에 넣음   
3. 큐에서 정점을 꺼내어 위상 정렬 결과에 추가   
4. 해당 정점으로 부터 연결된 모든 정점의 indegree 값을 1 감소시킴 이 때   
indegree가 0이 되었다면 그 정점을 큐에 추가   
5. 큐가 빌 때 까지 3, 4번 과정을 반복

```
vector<int> adj[10];
int deg[10];
int n;

queue<int> q;
vector<int> result;
for(int i = 1; i <= n; i++){
	if(deg[i] == 0) q.push(i);
}
while(!q.empty()){
	int cur = q.front(); q.pop();
	result.push_back(cur);
	for(int nxt : adj[cur]){
		deg[nxt]--;
		if(deg[nxt] == 0) q.push(nxt);
	}
}
if(result.size() != n)
	cout << "cycle exists";
else{
	for(auto x : result)
		cout << x << ' ';
}
```

| 문제 번호 | 정답 코드 |  중요한 문제(아이디어) |    
| :--: | :--: |:--: |   
| __[Baekjoon 2252번](https://www.acmicpc.net/problem/2252)__| [Solution](https://github.com/jhmin-kk99/Algorithm-Study/blob/main/TopologySort/2252.cpp)| |
