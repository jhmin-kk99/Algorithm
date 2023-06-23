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
>*  _최대공약수_
>>  
>*  _연립합동방정식_
>>
>*  _이항계수_
>>  
| 문제 번호 | 정답 코드 |  중요한 문제(아이디어) | 
| :--: | :--: |:--: |
| __[Baekjoon 1978번](https://www.acmicpc.net/problem/1978)__   | [Solution](https://github.com/jhmin-kk99/Algorithm-Study/blob/main/Math/1978.cpp)    | |
| __[Baekjoon 1929번](https://www.acmicpc.net/problem/1929)__   | [Solution](https://github.com/jhmin-kk99/Algorithm-Study/blob/main/Math/1929.cpp)    |_범위 내에서의 소수판정법 - 에라토스테네스의 체_|
