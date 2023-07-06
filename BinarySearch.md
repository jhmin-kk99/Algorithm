# 이분탐색    
>> 이분탐색 = 정렬되어 있는 배열에서 특정 데이터를 찾기 위해 모든 데이터를 순차적으로
>> 확인하는 대신 탐색 범위를 절반으로 줄여가며 찾는 탐색 방법 O(logN)

<STL정리>
- binary_search(시작, 끝, target) : true/false 반환
- upper_bound(시작, 끝, target) , lower_bound(시작, 끝, target)   
: target보다 큰 바로 다음 idx 반환 , target과 같은 가장 작은 idx 반환   
- equal_range(시작, 끝, target) : lower_bound와 upper_bound를 pair로 묶어서 반환

<주의사항>   
1. 이분탐색을 하고자 한다면 주어진 배열은 정렬되어 있어야 한다.   
2. 무한 루프에 빠지지 않게 mid 값을 정해야 한다.   
(직접 구현할 때, st와 en이 1 차이나는 경우를 주의 깊게 살펴보면 된다.)

<좌표압축>
- 입력 값이 10^9 처럼 클 때, 이것을 배열 인덱스로 사용하고 싶은 경우
- 크기 순으로 번호를 0번부터 매기고 싶을 때 사용
- 중복을 제외하고, 나보다 작은 수가 몇개 있는지를 물어보는 것
- ex) 2 4 -10 4 -9 -> 2 3 0 3 1

정렬되지 않은 배열 : int x[]
1. 리스트 정렬 (tmp)
2. 중복 제거(크기 같은 수는 인접하다는 성질을 이용해 tmp로 부터 uni에 중복x인 수만 넣음) 
3. lower_bound(uni.begin(), uni.end(), x[i]) - uni.begin()

| 문제 번호 | 정답 코드 |  중요한 문제(아이디어) | 
| :--: | :--: |:--: |
| __[Baekjoon 1920번](https://www.acmicpc.net/problem/1920)__   | [Solution](https://github.com/jhmin-kk99/Algorithm-Study/blob/main/Math/1920.cpp)    | |
