# BST   
> 이진 검색 트리(Binary Search Tree) : 왼쪽 서브트리의 모든 값은 부모의   
값보다 작고 오른쪽 서브트리의 모든 값은 부모의 값보다 큰 이진 트리
>> 원소가 크기 순으로 정렬되어 있음

> 자가 균형 트리(AVL트리, Red-Black트리) : 삽입, 검색, 삭제 -> O(logN)  
>> *set 
>> *multiset(set과 거의 동일, 중복O, find(아무거나 반환, lower_bound 사용), 
>> erase(전부 삭제), upper_bound(k가 들어갔을 때 오름차순이 유지되는 가장 오른쪽 위치 ...
>> 런타임 에러 조심(가리키는 원소가 없을 수 있음)))
>> *map
>> <팁>
>> 문제를 풀다가 set, map 느낌의 성질이 필요하면서 특히 lower_bound나 prev, next 등을
>> 시용해야만 풀리는 문제라면 꼭 STL set, map으로 해결을 해야함.
>> 또한 unordered_set/ unordered_map이 평균적으로는 속도가 빠를 수 있지만, 충돌이 얼마나
>> 빈번한가에 따라 속도의 저하가 발생할 수 있어 set, map을 사용하는 것을 사용하자.
>> 다만 조금 느리다는 것을 기억하자. N = 100만 같이 큰 상황에서 생각한 풀이 방법이 O(NlonN)이고,
>> set,map을 사용하게 되면 시간초과가 날 수 있음. 
>> 이때는 unordered set/map을 이용하거나 이분탐색이나 정렬, 배열의 인덱스를 이용한 다른 풀이를
>> 고민해보자.

```
void set_example(){
  set<int> s;
  s.insert(-10); s.insert(100); s.insert(15); // {-10, 15, 100}
  s.insert(-10); // {-10, 15, 100}
  cout << s.erase(100) << '\n'; // {-10, 15}, 1
  cout << s.erase(20) << '\n'; // {-10, 15}, 0
  if(s.find(15) != s.end()) cout << "15 in s\n";
  else cout << "15 not in s\n";
  cout << s.size() << '\n'; // 2
  cout << s.count(50) << '\n'; // 0
  for(auto e : s) cout << e << ' ';
  cout << '\n';
  s.insert(-40); // {-40, -10, 15}
  set<int>::iterator it1 = s.begin(); // {-40(<-it1), -10, 15}
  it1++; // {-40, -10(<-it1), 15}
  auto it2 = prev(it1); // {-40(<-it2), -10, 15}
  it2 = next(it1); // {-40, -10, 15(<-it2)}
  advance(it2, -2); // {-40(<-it2), -10, 15}
  auto it3 = s.lower_bound(-20); // {-40, -10(<-it3), 15}
  auto it4 = s.find(15); // {-40, -10, 15(<-it4)}
  cout << *it1 << '\n'; // -10
  cout << *it2 << '\n'; // -40
  cout << *it3 << '\n'; // -10
  cout << *it4 << '\n'; // 15
}

void multiset_example(){
  multiset<int> ms;
  // {-10, 15, 100}
  ms.insert(-10); ms.insert(100); ms.insert(15); // {-10, -10, 15, 15, 100}  
  ms.insert(-10); ms.insert(15);
  cout << ms.size() << '\n'; // 5
  for(auto e : ms) cout << e << ' ';
  cout << '\n';
  cout << ms.erase(15) << '\n'; // {-10, -10, 100}, 2
  ms.erase(ms.find(-10)); // {-10, 100}
  ms.insert(100); // {-10, 100, 100}
  cout << ms.count(100) << '\n'; // 2
  auto it1 = ms.begin(); // {-10(<-it1), 100, 100}
  auto it2 = ms.upper_bound(100); // {-10, 100, 100} (<-it2)
  auto it3 = ms.find(100); // {-10, 100(<-it3), 100}
  cout << *it1 << '\n'; // -10
  cout << (it2 == ms.end()) << '\n'; // 1
  cout << *it3 << '\n'; // 100
}

void map_example(){
  map<string, int> m;
  m["hi"] = 123;
  m["bkd"] = 1000;
  m["gogo"] = 165; // ("bkd", 1000), ("gogo", 165), ("hi", 123)
  cout << m.size() << '\n'; // 3
  m["hi"] = -7;  // ("bkd", 1000), ("gogo", 165), ("hi", -7)
  if(m.find("hi") != m.end()) cout << "hi in m\n";
  else cout << "hi not in m\n";
  m.erase("bkd"); // ("gogo", 165), ("hi", 123)
  for(auto e : m)
    cout << e.first << ' ' << e.second << '\n';
  auto it1 = m.find("gogo");
  cout << it1->first << ' ' << it1->second << '\n'; // gogo 165 (key, value)
}
}
```

| 문제 번호 | 정답 코드 |  중요한 문제(아이디어) | 
| :--: | :--: |:--: |
| __[Baekjoon 7662번](https://www.acmicpc.net/problem/7662)__   | [Solution](https://github.com/jhmin-kk99/Algorithm-Study/blob/main/BST/7662.cpp)    | |
| __[Baekjoon 1202번](https://www.acmicpc.net/problem/1202)__   | [Solution](https://github.com/jhmin-kk99/Algorithm-Study/blob/main/BST/1202.cpp)    | |
