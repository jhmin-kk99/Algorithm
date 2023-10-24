# 그래프   
<바킹독>
__인접 행렬, 인접 리스트로 구현 가능__   
>*  _두 점의 연결여부를 자주 확인할 때, E가 V^2에 가까울 때 : 인접 행렬_
>*  _특정 정점에 연결된 모든 정점을 자주 확인할 때, E가 V^2보다 훨씬 작을 때 : 인접 리스트_    
>*  _BFS/DFS_
>>*  _주의) DFS의 경우_
>>* _스택 메모리가 작을 경우, 재귀로 구현하는 데 깊이가 깊어지면 문제가 생길 수 있음을 인지_

<큰돌>   
>* 정점(vertex)과 간선(Edge)(정점과 정점을 잇는 선/ 사람과 사람과의 관계가될 수 있음)        
>* __indegree, outdegree__      
>* u(from),v(to) 많이씀    
>* u->v 개수 6개, v->u 개수 7개 일 때,   
>* u : outdegree(나가는 간선) = 6, indegree(오는 간선) = 7      
>* 정점과 간선으로 이루어진 집합 : Graph   
>* 가중치 : 정점과 정점 사이에 드는 비용(시간, 비용 등)
      
>* __인접행렬 / 인접리스트__
>* 인접행렬 : 그래프에서 정점과 간선의 관계를 나타내는 bool 타입의 정사각형 행렬을 의미. 정사각형 행렬의 각 요소가 0 또는 1이라는 값으로 가짐을 의미. 0은 두 정점 사이의 경로가 없음을 의미하며 1은 두 정점 사이의 경로가 있음을 의미.(무방향 그래프 .. 양방향으로 해석)   

   

Q. 인접행렬을 기반으로 탐색하기   
1번. 정점은 0번부터 9번까지 10개의 노드가 있다. 1-2 / 1-3 / 3-4 /5-6 라는 경로가 있다. 이를 인접행렬로 표현한다면?   
2번 . 0번부터 방문안한 노드를 찾고 해당 노드부터 방문, 연결된 노드를 이어서 방문해서 출력하는 재귀함수를 만들고 싶다면 어떻게 해야할까? 또한, 정점을 방문하고 다시 방문하지 않게 만드려면 어떻게 해야할까?   

   
```
#include <bits/stdc++.h>
using namespace std;

const int V = 10;
bool a[V][V] = {};
bool vis[V] = {};

void dfs(int x){
vis[x] = 1;
cout<<x<<" - ";
for(int i=0;i<V;++i){
 if(a[x][i]==1 && vis[i]==0) {
 	dfs(i);
 }
}
return;
}

void input(){
	a[1][2] = a[2][1] = 1;
	a[1][3] = a[3][1] = 1;
	a[3][4] = a[4][3] = 1;
	
	a[5][6] = a[6][5] = 1;
}
int main(){

	input();
	for(int i=0;i<V;++i){
		for(int j=0;j<V;++j){
			if(a[i][j]==1 && vis[i]==0) {
			dfs(i);
			cout<<'\n';
		}
	  }	
	}
}
```     

 



| 문제 번호 | 정답 코드 |  중요한 문제(아이디어) | 
| :--: | :--: |:--: |
| __[Baekjoon 11724번](https://www.acmicpc.net/problem/11724)__   | [Solution](https://github.com/jhmin-kk99/Algorithm-Study/blob/main/Graph/11724.cpp)    | |
| __[Baekjoon 1260번](https://www.acmicpc.net/problem/1260)__   | [Solution](https://github.com/jhmin-kk99/Algorithm-Study/blob/main/Graph/1260.cpp)    |_재귀,비재귀 DFS_|
| __[SW Expert 1868번](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5LwsHaD1MDFAXc&categoryId=AV5LwsHaD1MDFAXc&categoryType=CODE&problemTitle=%EC%A7%80%EB%A2%B0&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=&pageSize=10&pageIndex=1)__| [Solution](https://github.com/jhmin-kk99/Algorithm-Study/blob/main/Graph/s1868.cpp)    | |
| __[SW Expert 1855번](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5LnipaDvwDFAXc&categoryId=AV5LnipaDvwDFAXc&categoryType=CODE&problemTitle=%EC%98%81%EC%A4%80%EC%9D%B4&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=&pageSize=10&pageIndex=1)__| [Solution](https://github.com/jhmin-kk99/Algorithm-Study/blob/main/Graph/s1855.cpp)    | |
