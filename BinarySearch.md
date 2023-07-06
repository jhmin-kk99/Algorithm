# 이분탐색    
>> 이분탐색 = 정렬되어 있는 배열에서 특정 데이터를 찾기 위해 모든 데이터를 순차적으로
>> 확인하는 대신 탐색 범위를 절반으로 줄여가며 찾는 탐색 방법 O(logN)

<STL정리>
- binary_search(시작, 끝, target) : true/false 반환
- upper_bound(시작, 끝, target) : 배열에서 처음으로 value값을 초과하는 원소의 주소를 반환
- lower_bound(시작, 끝, target) : 배열에서 범위 내의 원소들 중 value값 보다 크거나 같은 첫 번째  원소의 주소를 리턴   
- equal_range(시작, 끝, target) : lower_bound와 upper_bound를 pair로 묶어서 반환
- unique(시작, 끝) : 정렬된 상태에서 중복제거를 해주고 쓰레기 값의 시작 주소를 반환
  ```
  sort(uni.begin(), uni.end());
  uni.erase(unique(uni.begin(), uni.end()), uni.end());
  ```

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
1. 리스트 정렬 
2. 중복 제거 (unique이용)
3. lower_bound(uni.begin(), uni.end(), x[i]) - uni.begin()

<시간복잡도 줄이기(응용)> 
예를 들어, 한 집합 a에서 a[i]+a[j]+a[k] = a[l] 인 l을 찾아야 할 때,
two[m] = a[i] + a[j]인 배열을 만들어, a[l]-a[k] = two[m]을 이용한다.

<Parametric Search>
Parametric Search = 조건을 만족하는 최소/최댓값을 구하는 문제(최적화 문제)를
결정 문제로 변환해 이분탐색을 수행하는 방법

BOJ 1654 : 랜선 자르기
(최적화 문제) N개를 만들 수 있는 랜선의 최대 길이
(결정 문제) 랜선의 길이가 X일 때 랜선이 N개 이상인가 아닌가?

Parametric Search를 할 때에는, 최적화 문제를 결정 문제로 바꿀 수 있는지
생각하고, 그 결정 문제로 얻어낸 함수가 감소 혹은 증가함수인지를 따져야함.
문제에서 최소 혹은 최대 얘기가 있고, 범위가 무지막지하게 크거나 시간
복잡도에서 값 하나를 log로 잘 떨구면 될 것 같을 때 고려해볼 수 있음 

무한루프에 빠지는 것을 주의해야하는데, 이는 l+h이 홀수여서 반으로 나누면 0.5
가 남는 경우, 버림을 해줄 지 올림을 해줄 지에 대한 것이다.
```
while(l < h) {
    m = (l + h + 1) / 2; //(m = (l + h) / 2의 경우 무한루프에 빠짐)

    if( condition(m) ) {
        l = m;
    } else {
        h = m - 1;
    }
}
```

| 문제 번호 | 정답 코드 |  중요한 문제(아이디어) | 
| :--: | :--: |:--: |
| __[Baekjoon 1920번](https://www.acmicpc.net/problem/1920)__   | [Solution](https://github.com/jhmin-kk99/Algorithm-Study/blob/main/Math/1920.cpp)    | |
| __[Baekjoon 10816번](https://www.acmicpc.net/problem/10816)__   | [Solution](https://github.com/jhmin-kk99/Algorithm-Study/blob/main/Math/10816.cpp)    | |
| __[Baekjoon 18870번](https://www.acmicpc.net/problem/18870)__   | [Solution](https://github.com/jhmin-kk99/Algorithm-Study/blob/main/Math/18870.cpp)    |_좌표압축_|
| __[Baekjoon 2295번](https://www.acmicpc.net/problem/2295)__   | [Solution](https://github.com/jhmin-kk99/Algorithm-Study/blob/main/Math/2295.cpp)    |_시간복잡도 줄이기_|
| __[Baekjoon 1654번](https://www.acmicpc.net/problem/1654)__   | [Solution](https://github.com/jhmin-kk99/Algorithm-Study/blob/main/Math/1654.cpp)    |_무한루프, overflow 주의_|

