# KMP

<알고리즘 설명>   
s[a:b] = "s[a]s[a+1]...s[b-1]"
s = "ABCDEF"일 때 s[2:5] = "CDE", s[3:4] = "D", s[0:2] = "AB"    
|s|는 s의 길이, s = "ABCDEF"일 때 |s| = 6   
접두사 = 문자열의 첫 문자를 포함하는 연속한 문자열, s[0:x]    
접미사 = 문자열의 끝 문자를 포함하는 연속한 문자열, s[x:|s|]   
A,AB,ABC,ABCD,ABCDE,ABCDEF는 ABCDEF의 접두사     
F,EF,DEF,CDEF,BCDEF,ABCDEF는 ABCDEF의 접미사      
    
KMP : 패턴 매칭 문제를 O(|A| + |B|)에 해결할 수 있는 기적의 알고리즘      
굉장히 헷갈림       
먼저 KMP에서 쓰이는 실패 함수를 알면 KMP를 이해하는데 도움이 됨       
      
실패함수 F(x) : 문자열 s[0:x+1]에서 접두사와 접미사가 일치하는 최대 길이     
     
[블로그](https://bowbowbow.tistory.com/6)        
       
| 문제 번호 | 정답 코드 |  중요한 문제(아이디어) | 
| :--: | :--: |:--: |
| __[SW Expert 단어가 등장하는 횟수](https://jihongmin-99.tistory.com/76)__   | [Solution](https://github.com/jhmin-kk99/Algorithm-Study/blob/main/KMP/s단어가등장하는횟수.cpp)    | |
