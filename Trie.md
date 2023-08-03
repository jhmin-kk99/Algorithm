# 트라이

트라이(Trie) = 문자열을 효울적으로 처리하기 위한 트리 자료구조

+ 단어 S를 삽입/탐색/삭제할 때 O(|S|)
- 문자열을 그냥 배열에 저장하는 것 보다 최대 '4 x 글자의 종류'배 만큼
더 사용(예를 들어 각 단어가 알파벳 대문자로만 구성되어 있을 경우 104배)

이론적인 시간복잡도와는 별개로 실제로는 트라이가 해시, 이진 검색 트리에 비해
훨씰 느림. 일반적인 상황에서는 해시나 이진 검색 트리를 사용하는게 좋으나
트라이의 성질을 사용해야 하는 문제가 여럿 존재

```
#include <bits/stdc++.h>
using namespace std;

const int ROOT = 1;
int unused = 2;
const int MX = 10000 * 500 + 5; // 최대 등장 가능한 글자의 수
bool chk[MX];
int nxt[MX][26];

int c2i(char c){
  return c - 'a'; //인덱스로 변환
}

void insert(string& s){
  int cur = ROOT;
  for(auto c : s){
    if(nxt[cur][c2i(c)] == -1)
      nxt[cur][c2i(c)] = unused++;
    cur = nxt[cur][c2i(c)];
  }
  chk[cur] = true;
}

bool find(string& s){
  int cur = ROOT;
  for(auto c : s){
    if(nxt[cur][c2i(c)] == -1)
      return false;
    cur = nxt[cur][c2i(c)];
  }
  return chk[cur];
}

void erase(string& s){
  int cur = ROOT;
  for(auto c : s){
    if(nxt[cur][c2i(c)] == -1)
      return ;
    cur = nxt[cur][c2i(c)];
  }
  chk[cur] = false;
}

void test(){
  string insert1 = "apple";
  insert(insert1);
  string insert2 = "apply";
  insert(insert2);
  string insert3 = "black";
  insert(insert3);
  string insert4 = "ban";
  insert(insert4);
  string insert5 = "banana";
  insert(insert5);

  string find1 = "ban";
  cout << find(find1) << '\n'; // 1
  string find2 = "base";
  cout << find(find2) << '\n'; // 0
  string find3 = "app";
  cout << find(find3) << '\n'; // 0
  
  string erase1 = "banana";
  erase(erase1);
  string erase2 = "talk";
  erase(erase2);
  string erase3 = "apply";
  erase(erase3);
  
  string find4 = "ban";
  cout << find(find4) << '\n'; // 1
  string find5 = "apply";
  cout << find(find5) << '\n'; // 0  
}

int main(void){
  for(int i = 0; i < MX; i++)
    fill(nxt[i], nxt[i]+26, -1);
  test();
}
```

대표적으로 많이 쓰이는 곳이 '자동완성기능'


| 문제 번호 | 정답 코드 |  중요한 문제(아이디어) |    
| :--: | :--: |:--: |   
| __[Baekjoon 14425번](https://www.acmicpc.net/problem/14425)__| [Solution](https://github.com/jhmin-kk99/Algorithm-Study/blob/main/Trie/14452.cpp)| |
| __[SW Expert 1256번](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV18GHd6IskCFAZN&categoryId=AV18GHd6IskCFAZN&categoryType=CODE&problemTitle=k%EB%B2%88%EC%A7%B8+%EC%A0%91%EB%AF%B8%EC%96%B4&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=&pageSize=10&pageIndex=1)__| [Solution](https://github.com/jhmin-kk99/Algorithm-Study/blob/main/Trie/s1256.cpp)| |
| __[SW Expert 1257번](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV18KWf6ItECFAZN&categoryId=AV18KWf6ItECFAZN&categoryType=CODE&problemTitle=k%EB%B2%88%EC%A7%B8+%EB%AC%B8%EC%9E%90%EC%97%B4&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=&pageSize=10&pageIndex=1__| [Solution](https://github.com/jhmin-kk99/Algorithm-Study/blob/main/Trie/s1257.cpp)| |
