# 수학   
__소수, 최대공약수, 연립합동방정식, 이항계수__   
>*  _소수_
>> = 1과 자기 자신으로만 나누어지는 수 = 약수가 2개인 수
>> = 2부터 N-1까지의 수로 나누어지지 않는 수
```
bool isprime(int n){
  if(n == 1) return 0;
  for(int i = 2; i < n; i++){
    if(n % i == 0) return 0;
  }
  return 1;
}
//O(n)
```
>> <소수판정법>   
>> : 합성수 N에서 1을 제외한 가장 작은 약수는 √N 이하이다.   
>> ->   
>> 합성수 N에서 1을 제외한 가장 작은 약수를 x라고 하자.   
>> N/x 또한 1이 아닌 N의 약수이기 때문에 x<= (N/x)이다.   
>> 우변의 분모 x를 좌변으로 옮기면 x^2 <= N이므로 x <= √N.   
>> ->   
>> 2부터 √N 까지의 수로 나누어지지 않으면 소수이다.   
```
bool isprime(int n){
  if(n == 1) return 0;
  for(int i = 2; i*i <= n; i++){
    if(n % i == 0) return 0;
  }
  return 1;
}
// O(√N)
```
>> <범위 내에서의 소수판정법>   
>> 2부터 √N 사이의 소수로만 나누어서 확인하면 됨   
>> 각 수의 1이 아닌 가장 작은 약수는 소수이기 때문
```
vector<int> primelist(int n){
  vector<int> primes;
  for(int i = 2; i <= n; i++){
    bool isprime = 1;
    for(int p : primes){
      if(p*p > i) break;
      if(i % p == 0){
        isprime = 0;
        break;
       }
    }
    if(isprime) primes.push_back(i);
  }
  return primes;
}
```
>> <범위 내에서의 소수판정법 - 에라토스테네스의 체>   
```
vector<int> sieve(int n){
  vector<int> primes;
  vector<bool> state(n+1, true);
  //1. 각 bool 한 칸이 1 byte가 아니라 1 bit만 차지하도록 최적화가 이루어짐.  
  //2. cache hit rate이 올라가서 시간도 빨라짐.
  state[1] = false;
  for(int i = 2; i*i <= n; i++){
     if(!state[i]) continue;
     for(int j = i*i; j<=n; j+=i) // i*i보다 작은 합성수는 이미 걸러짐
        state[j] = false;
   }
  for(int i = 2; i <= n; i++){
    if(state[i]) primes.push_back(i);
  }
  return primes;
}
```
>> <소인수분해>   
>> : 1100 = 2 * 2 * 5 * 5 * 11
```
	for (int i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			cout << i << '\n';
			n /= i;
		}
	}
	if (n != 1) cout << n;
```
>*  _최대공약수_
>>  <약수>
>>  약수 = 어떤 수를 나누어떨어지게 하는 수
```
vector<int> divisor(int n) {
	vector<int> div;
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0)div.push_back(i);
	}
	for (int j = (int)div.size() - 1; j >= 0; j--) {
//vector의 size() 멤버함수는 unsigned를 반환함, 0일때 overflow 방지를 위해 형변환해줌
		if (div[j] * div[j] == n) continue;
		div.push_back(n / div[j]);
	}
	return div;
}
```
>> <최대공약수>
>> 최대공약수(Greatest Common Divisor) = 두 자연수의 공통된 약수 중 가장 큰 약수
>> 20의 약수 = 1,2,4,5,10,20 / 12의 약수 = 1,2,3,4,6,12 ... GCD(20,12) = 4
>> <유클리드 호제법>
>> 두 수 A,B에 대해 A를 B로 나눈 나머지를 r이라고 하면 GCD(A,B) = GCD(B,r)이다.
>> GCD(20,12) = GCD(12,8) = GCD(8,4) = GCD(4,0) = 4
```
int gcd(int a, int b){
  if(a == 0) return b;
  return gcd(b%a, a);
}
O(log(max(a,b)))
```
>> <최소공배수>
>> A X B = GCD(A,B) X LCM(A,B) 관계 성립
```
int lcm(int a, int b){
  return a / gcd(a, b) * b; // (a*b) / gcd(a,b)가 아닌 이유는, int overflow방지를 위해서임.
}
```
>*  _연립합동방정식_
Q)
- 6명씩 조를 짰을 때 3명이 남았다.
- 5명씩 조를 짰을 때 2명이 남았다.
- 학생은 30명 미만이다.
```
먼저 6으로 나눈 나머지가 3인 목록을 구하고
그 목록을 이용해서 5로 나눈 나머지가 2인 수를 구함
int chk(){
  for(int i = 3; i< 30; i += 6){
    if(i % 5 == 2)
      return i;
}
  return -1;
}
```
>*  _이항계수_   
- 조합 : 순서를 고려하지 않고 5개에서 3개를 뽑는다 : 5! / (3!2!) = 10   
- 순열 : 순서를 고려해 5개에서 3개를 뽑는다 : 5! / 2! = 60   
  >> nCk = n-1Ck + n-1Ck-1 (내가 임의로 하나를 찍었을 때 경우가 2가지 생김)   
  >> 이 식으로 dp를 하면 됨 (수가 클 경우)   
  >> d[i][j] = iCj , d[i][j] = d[i-1][j-1] + d[i-1][j] (int overflow 주의)   

| 문제 번호 | 정답 코드 |  중요한 문제(아이디어) | 
| :--: | :--: |:--: |
| __[Baekjoon 1978번](https://www.acmicpc.net/problem/1978)__   | [Solution](https://github.com/jhmin-kk99/Algorithm-Study/blob/main/Math/1978.cpp)    | |
| __[Baekjoon 1929번](https://www.acmicpc.net/problem/1929)__   | [Solution](https://github.com/jhmin-kk99/Algorithm-Study/blob/main/Math/1929.cpp)    |_범위 내에서의 소수판정법 - 에라토스테네스의 체_|
 
