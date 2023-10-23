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

 



| 문제 번호 | 정답 코드 |  중요한 문제(아이디어) | 
| :--: | :--: |:--: |
| __[Baekjoon 11724번](https://www.acmicpc.net/problem/11724)__   | [Solution](https://github.com/jhmin-kk99/Algorithm-Study/blob/main/Graph/11724.cpp)    | |
| __[Baekjoon 1260번](https://www.acmicpc.net/problem/1260)__   | [Solution](https://github.com/jhmin-kk99/Algorithm-Study/blob/main/Graph/1260.cpp)    |_재귀,비재귀 DFS_|
| __[SW Expert 1868번](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5LwsHaD1MDFAXc&categoryId=AV5LwsHaD1MDFAXc&categoryType=CODE&problemTitle=%EC%A7%80%EB%A2%B0&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=&pageSize=10&pageIndex=1)__| [Solution](https://github.com/jhmin-kk99/Algorithm-Study/blob/main/Graph/s1868.cpp)    | |
| __[SW Expert 1855번](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5LnipaDvwDFAXc&categoryId=AV5LnipaDvwDFAXc&categoryType=CODE&problemTitle=%EC%98%81%EC%A4%80%EC%9D%B4&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=&pageSize=10&pageIndex=1)__| [Solution](https://github.com/jhmin-kk99/Algorithm-Study/blob/main/Graph/s1855.cpp)    | |
