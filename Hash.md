# 해시  
> 해시함수 : 임의의 길이의 데이터를 고정된 길이의 데이터로 대응시키는 함수   

> 충돌 회피1 - Chaining : 각 인덱스마다 연결리스트를 하나씩 두어서 충돌을 회피함   
>> 해시값이 같은 최악의 상황에서는 O(N) -> 각 키의 해시값이 최대한 균등하게 퍼지도록 해시함수   
>> 설정이 중요

> 충돌 회피2 - Open Addressing : 인덱스에 (키, 값)쌍을 씀
>> 인덱스가 비어있지 않으면 다음 칸에 (키, 값)쌍을 쓰며 충돌을 회피함(빈 칸 or dummy값)   
>> 찾다가 빈 칸을 만나게 되면 찾는 값은 존재x (erase를 할 때는 해당 칸에 dummy값을 넣음)   

Linear Probing = 충돌 발생 시 오른쪽으로 1칸씩 이동하는 방식
장점 - Cache hit rate가 높다
단점 - Clustering(군집)이 생겨 성능에 영향을 줄 수 있다

Quadratic Probing = 충돌 발생 시 오른쪽으로 1,3,5,...칸씩 이동하는 방식   
장점 - Cache hit rate가 나쁘지 않다, Clustering을 어느 정도 회피할 수 있다.   
단점 - 해시 값이 같을 경우 여전히 Clustering이 발생한다.

Double Hashing = 충돌 발생 시 이동할 칸의 수를 새로운 해시 함수로 계산하는 방식   
장점 - Clustering을 효과적으로 회피할 수 있다.
단점 - Cache hit rate가 낮다.

```
void unordered_set_example() {
    unordered_set<int> s;
    s.insert(-10); s.insert(100); s.insert(15); // (-10, 100, 15)
    s.insert(-10); // (-10, 100, 15)
    cout << s.erase(100) << '\n'; // (-10, 15), 1
    cout << s.erase(20) << '\n'; // (-10, 15), 0
    if (s.find(15) != s.end()) cout << "15 in s\n";
    //.end() 메소드는 자료의 마지막값의 다음값인 빈iterator의 메모리를 반환
    else cout << "15 not in s\n";
    cout << s.size() << '\n'; // 2
    cout << s.count(50) << '\n'; // 0
    for (auto e : s) cout << e << ' ';
    cout << '\n';

}
```
```
void unordered_multiset_example() {
    unordered_multiset<int> ms;
    ms.insert(-10); ms.insert(100); ms.insert(15); // (-10, 100, 15)
    ms.insert(-10); ms.insert(15); // (-10, -10, 100, 15, 15)
    cout << ms.size() << '\n'; // 5
    for (auto e : ms) cout << e << ' ';
    cout << '\n';
    cout << ms.erase(15) << '\n'; // (-10, -10, 100) , 2 
    ms.erase(ms.find(-10)); // (-10, 100)
    ms.insert(100);
    cout << ms.count(100) << '\n'; // 2
}
```
```
void unordered_map_example() {
    unordered_map<string, int> m;
    m["hi"] = 123;
    m["bkd"] = 1000;
    m["gogo"] = 165; //{"hi", 123}, {"bkd", 1000}, {"gogo", 165}
    cout << m.size() << '\n'; // 3
    m["hi"] = -7; //{"hi", -7}, { "bkd", 1000 }, { "gogo", 165 }
    if (m.find("hi") != m.end()) cout << "hi in m\n";
    else cout << "hi not in m\n";
    m.erase("bkd"); // {"hi", -7}, {"gogo", 165}
    for (auto e : m)
        cout << e.first << ' ' << e.second << '\n';
}
}
```
> 구현   
<해시 테이블 크기, 해시 함수>
Load factor = 원소의 개수 / 테이블의 크기
Load factor <= 1(Chaining), Load factor <= 0.75(Open addressing)

```
정수에 대한 해시 함수
const int M = 1000003;
int my_hash(int x){
    return (M + x % M) % M; //음수도 고려
}

문자열에 대한 해시 함수
const int M = 1000003;
int hash(string& s){
    int h = 0;
    for(auto x : s) h += x;
    return h % M;
} // 충돌이 빈번하게 발생해서 좋지 않은 해시 함수

//my_hash("abc") = ('a' * 1000^2 + 'b' * 1000^1 + 'c' * 1000^0) % M

const int M = 1000003;
const int a = 1000;
// int overflow 주의
int my_hash(string& s){
    int h = 0;
    for(auto x : s)
        h = (h * a + x) % M;
    return h;
}
```
```
<Chaining>


```


| 문제 번호 | 정답 코드 |  중요한 문제(아이디어) |    
| :--: | :--: |:--: |   
| __[Baekjoon 7785번](https://www.acmicpc.net/problem/7785)__   | [Solution](https://github.com/jhmin-kk99/Algorithm-Study/blob/main/Greedy/7785.cpp)    | |
| __[Baekjoon 1620번](https://www.acmicpc.net/problem/1620)__   | [Solution](https://github.com/jhmin-kk99/Algorithm-Study/blob/main/Greedy/1620.cpp)    | |
