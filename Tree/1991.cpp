#include <iostream>
#include <algorithm>
using namespace std;
int N;
int lc[28] = {};
int rc[28] = {};

void Preorder(int cur) {
	cout << char(cur + 'A' - 1);
	if (lc[cur] != 0)Preorder(lc[cur]);
	if (rc[cur] != 0)Preorder(rc[cur]);

}
void Inorder(int cur) {
	if (lc[cur] != 0)Inorder(lc[cur]);
	cout << char(cur + 'A' - 1);
	if (rc[cur] != 0)Inorder(rc[cur]);
}
void Postorder(int cur) {
	if (lc[cur] != 0)Postorder(lc[cur]);
	if (rc[cur] != 0)Postorder(rc[cur]);
	cout << char(cur + 'A' - 1);
}




int main(void) {
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		char c, l, r;
		cin >> c >> l >> r;
		if (l != '.') lc[c - 'A' + 1] = l - 'A' + 1;
		if (r != '.')rc[c - 'A' + 1] = r - 'A' + 1;
	}
	Preorder(1);
	cout << '\n';
	Inorder(1);
	cout << '\n';
	Postorder(1);
	cout << '\n';
}