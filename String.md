# 문자열

```
int main(){
  string s = "hello";
  s += " BKD!"; // hello BKD!
  cout << s.size() << '\n'; // 10
  cout << s.substr(2, 3) << '\n'; // llo
  cout << s[1] << '\n'; // e
  s.replace(6, 4, "guys"); // hello guys
  cout << s << '\n';
  int it = s.find("guys"); // 6
  s.replace(it, 4, "everyone"); // hello everyone
  cout << s << '\n';
  s.erase(7, 6); // hello ee
  cout << s << '\n';
  s[6] = 'm'; // hello me
  cout << s << '\n';
  s.insert(0, "say ");// say hello me
  cout << s << '\n';
  if(s.find("to") == string::npos) // string::npos == -1
    cout << "'to' is not in string 's'\n";
  vector<string> chunks1 = split("welcome to the black parade", " ");
  // welcome/to/the/black/parade/
  for(auto chunk : chunks1) cout << chunk << '/';
  cout << '\n';
  vector<string> chunks2 = split("b*!*ac*!**!*e*!*y*!*", "*!*");
  // b/ac/a/y/
  for(auto chunk : chunks2) cout << chunk << '/';
}
```
split함수
```
vector<string> split(string& s, string& sep){
	vector<string> ret;
	int pos = 0;
	while(pos < s.size()){
		int nxt_pos = s.find(sep, pos);
        //pos 번째 부터 find
		if(nxt_pos == -1) nxt_pos = s.size();
		if(nxt_pos - pos > 0)
			ret.push_back(s.substr(pos, nxt_pos - pos));
		pos = nxt_pos + sep.size();
	}
	return ret;
}
```
주의사항

아래 코드의 시간복잡도는?
```
int main(){
	string s;
	for(int i = 0; i < 1000000; i++)
		s = s + 'a';
}
```
O(N^2), s + 'a'라는 새 객체를 만든 후 이를 s에 다시 대입하기 때문에
매 덧셈이 s의 길이에 비례한 시간을 필요로 함
```
int main(){
	string s;
	for(int i = 0; i < 1000000; i++)
		s += 'a';
}
```
O(N), += 연산자를 이용하면 시간복잡도가 더해지는 길이에만 영향을 받음

BOJ 1543 : 문서 검색

find를 이용해 특정 문자열의 처음 등장 위치를 찾을 수 있고 pos 인자를 통해
위치 pos 이후의 등장 위치를 찾도록 할 수 있다.
T.find(P,pos) : 문자열 T에서 pos 이후로 단어 P가 등장하는 최초 위치를 반환,
pos 이후로는 P가 등장하지 않을 경우 string::npos를 반환

"abcabc".find("abc",1) = 3
"abababa".find("aba",2) = 2

문자열 T에서 단어 P가 등장하는 횟수를 세려고 하는데 중복되어 세는 것은
빼야한다는 조건을 어떻게 처리할 것인가? 
-> find를 통해 단어를 찾은 이후 그 위치에서 P.size()만큼 더한 값을 pos의
인자로 넘김

```
#include<bits/stdc++.h>
using namespace std;

int main(void){
	ios::sync_stdio(0);
	cin.tie(0);
	string t, p;
	getline(cin, t);
	getline(cin, p);
	int cnt = 0;
	int f = t.find(p);
	while(f != string::npos){
		cnt++;
		f = t.find(p, f + p.size());
	}
	cout << cnt;
}
```
BOJ 2941 : 크로아티아 알파벳

각 크로아티아 알파벳들을 전부 찾아 #이나 1과 같은 문자로 변환한 뒤 단어
의 글자수를 세면 됨(replace를 이용)

만약 크로아티아 알파벳을 찾아 지워버리는 방식으로 구현을 하면 어떤 문제가
있는가?

-> "nnjj"는 n/nj/j로 이루어진 3글자의 단어이지만 찾아서 지우는 방식으로 구현
할 경우 먼저 nj를 찾아 지운 후 그 다음으로 생긴 nj를 한 알파벳으로 착각해
답이 2라고 생각할 수 있음

```
#include <bits/stdc++.h>
using namespace std;

vector<string> alphas = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string w;
  cin >> w;
  for(auto alpha : alphas){
    while(true){
      int pos = w.find(alpha);
      if(pos == string::npos) break;
      w.replace(pos, alpha.size(), "1");
    }
  }
  cout << w.size();
}
```