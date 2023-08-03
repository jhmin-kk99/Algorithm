#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
const int MX = 5000005;
const int root = 1;
int unused = 2;
bool chk[MX];
int nxt[MX][26];
int n, m;

int c2i(char c) {
	return c - 'a';
}

void insert(string& s) {
	int cur = root;
	for (auto e : s) {
		if (nxt[cur][c2i(e)] == -1)
			nxt[cur][c2i(e)] = unused++;
		cur = nxt[cur][c2i(e)];
	}
	chk[cur] = true;
}

bool find(string& s) {
	int cur = root;
	for (auto e : s) {
		if (nxt[cur][c2i(e)] == -1)
			return false;
		cur = nxt[cur][c2i(e)];
	}
	return chk[cur];
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	int ans = 0;
	for (int i = 0; i < MX; i++)
		fill(nxt[i], nxt[i] + 26, -1);
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		insert(s);
	}
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		if (find(s)) ans++;
	}
	cout << ans;
}