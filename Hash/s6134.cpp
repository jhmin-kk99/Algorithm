#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

typedef enum
{
	NAME,
	NUMBER,
	BIRTHDAY,
	EMAIL,
	MEMO
} FIELD;

typedef struct
{
	int count;
	char str[20];
} RESULT;


struct Record {
	char* attr[5];
};

Record recpool[50001]; int cnt = 0;
unordered_multimap<string, int> fd[5];

void InitDB()
{
	cnt = 0;
	memset(recpool, 0, sizeof(recpool));
	for (int i = 0; i < 5; i++) unordered_multimap<string, int>().swap(fd[i]);
}

void Add(char* name, char* number, char* birthday, char* email, char* memo)
{
	Record r;
	r.attr[0] = strdup(name);
	r.attr[1] = strdup(number);
	r.attr[2] = strdup(birthday);
	r.attr[3] = strdup(email);
	r.attr[4] = strdup(memo);
	// 구조체 초기화

	for (int i = 0; i < 5; i++) {
		fd[i].insert({ r.attr[i], cnt });
	}
	recpool[cnt++] = r;
}

int Delete(FIELD field, char* str)
{
	int num = 0;
	auto range = fd[field].equal_range(str);
	if (range.first != range.second) {
		for (auto it = range.first; it != range.second;) {
			int idx = it->second;
			for (int i = 0; i < 5; i++) {
				if (i == field) continue;
				auto r = fd[i].equal_range(recpool[idx].attr[i]);
				if (r.first != r.second) {
					for (auto itr = r.first; itr != r.second;) {
						if (itr->second == idx) itr = fd[i].erase(itr);
						else ++itr;
					}
				}
			}
			// 현재 필드 제외 제거

			it = fd[field].erase(it); num++;
			//현재 힐드 제거
		}
	}
	return num;
}

int Change(FIELD field, char* str, FIELD changefield, char* changestr)
{
	int num = 0;
	vector<Record> add;
	auto range = fd[field].equal_range(str);
	if (range.first != range.second) {
		for (auto it = range.first; it != range.second;) {
			int idx = it->second;
			for (int i = 0; i < 5; i++) {
				if (i == field) continue;
				auto r = fd[i].equal_range(recpool[idx].attr[i]);
				if (r.first != r.second) {
					for (auto itr = r.first; itr != r.second;) {
						if (itr->second == idx) itr = fd[i].erase(itr);
						else ++itr;
					}
				}
			}
			// 현재 필드 제외 제거

			it = fd[field].erase(it); num++;
			//현재 필드 제거

			Record r;
			for (int i = 0; i < 5; i++)
			{
				if (i == changefield) {
					r.attr[i] = strdup(changestr);
				}
				else {
					r.attr[i] = strdup(recpool[idx].attr[i]);
				}
			}
			// r 초기화

			add.push_back(r);
			// r 추가


		}
	}

	for (auto e : add) {
		for (int i = 0; i < 5; i++) {
			fd[i].insert({ e.attr[i],cnt });
		}
		recpool[cnt++] = e;
	}
	return num;
}

RESULT Search(FIELD field, char* str, FIELD ret_field)
{
	RESULT result;

	int num = 0;
	auto range = fd[field].equal_range(str);
	int cur = -1;
	if (range.first != range.second) {
		for (auto it = range.first; it != range.second; ++it) {
			int idx = it->second;
			num++;
			if (num == 1) cur = idx;
		}
	}
	if (num == 1) {
		char* s = recpool[cur].attr[ret_field];
		strcpy(result.str, s);
			
		
		
		/*
			string s = recpool[cur].attr[ret_field];
			for (int i = 0; i < s.length(); i++) {
				result.str[i] = s[i];
			}
			result.str[s.length()] = '\0';

			-> result.str[s.length()] = '\0';
			이 줄을 삽입하지 않았을 때,
			s가 01011111234일 때, result.str의 값이 0101111123401011111234가 되는 문제가 발생함

			문제가 발생하는 이유는 RESULT 구조체의 str 배열의 크기가 20인데,
			문자열의 끝을 나타내는 NULL 문자('\0')을 추가하지 않아서이다.

			먼저, RESULT 구조체의 정의를 살펴보면
			typedef struct
			{
				int count;
				char str[20];
			} RESULT;

			RESULT 구조체는 문자열의 개수를 나타내는 count와 최대 20개의 문자를 저장할 수 있는 str 배열
			로 이루어져있다.
			그리고 Search 함수에서 RESULT 구조체를 반환할 때,
			다음과 같이 문자열의 길이만큼만 복사하고 있다.

			RESULT Search(FIELD field, char* str, FIELD ret_field)
			{
				// ...

				if (num == 1) {
					string s = recpool[cur].attr[ret_field];
					for (int i = 0; i < s.length(); i++) {
						result.str[i] = s[i];
					}
				}

				// ...
			}

			이 때, s.length()는 문자열의 길이를 반환하므로
			result.str 배열에 문자열을 복사할 때 NULL 문자('\0')는 포함되지 않는다.
			이로 인해 result.str이 NULL로 끝나지 않은 문자열이 되어, 이후 출력 시
			NULL 문자가 없는 쓰레기 값을 함께 출력하는 문제가 발생한다.
			문자열을 C 스타일로 다루기 위해서는 문자열의 끝에 NULL 문자('\0')를 추가해야 한다.
			수정 방법은 간단한다.
			Search 함수에서 result.str 배열의 마지막에 NULL 문자를 추가해주면 된다.

			<방법>
			string s = "hello"; 를
			1. string a 에 복사
			2. char* b 에 복사
			3. char[len] c에 복사
			-----------------------------
			1.
			string a = s;
			2.
			char* b = new char[s.length() + 1]; // 'b'에 충분한 공간을 할당
			std::strcpy(b, s.c_str()); // 's'의 내용을 'b'에 복사
			// 메모리 누수를 피하기 위해 메모리 해제
			delete[] b;
			3.
			char c[len]; // 충분한 공간이 있는 문자 배열을 선언
			std::strncpy(b, s.c_str(), sizeof(c) - 1); // 's'의 내용을 'c'에 복사
			b[sizeof(b) - 1] = '\0'; // 문자 배열에 널 종료 문자를 추가

			*/

	}
	result.count = num;

	return result;
}