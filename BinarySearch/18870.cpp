#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
int x[10000005];
vector<int> tmp, uni;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	//for (int i = 0; i < n; i++) {
	//	cin >> x[i];
	//	tmp.push_back(x[i]);
	//}
	//sort(tmp.begin(), tmp.end()); //정렬
	//for (int i = 0; i < n; i++) {
	//	if (i == 0 || tmp[i - 1] != tmp[i])
	//		uni.push_back(tmp[i]); //중복 제거
	//}

	//for (int i = 0; i < n; i++)
	//	cout << lower_bound(uni.begin(), uni.end(), x[i]) - uni.begin() << ' ';
	//

	//중복제거 STL사용
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		uni.push_back(x[i]);
	}
	sort(uni.begin(), uni.end());
	uni.erase(unique(uni.begin(), uni.end()), uni.end());
	//STL unique : 정렬된 상태에서 중복제거를 해주고 쓰레기 값의 시작 주소를 반환
	for (int i = 0; i < n; i++)
		cout << lower_bound(uni.begin(), uni.end(), x[i]) - uni.begin() << ' ';
}