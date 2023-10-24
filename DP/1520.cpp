#include <bits/stdc++.h>
using namespace std;
int m,n;
int s[505][505];
int dp[505][505];

int dx[4]={0,-1,0,1};
int dy[4]={1,0,-1,0};

void input(){
	cin>>m>>n;
	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j){
			cin>>s[i][j];
			dp[i][j]=-1;
		}
	}
}


int dfs(int x, int y){
	if(x==m-1 && y==n-1) return 1;
	if(dp[x][y]!=-1) return dp[x][y];
	
	dp[x][y]=0;
	
	for(int dir=0;dir<4;++dir){
		int nx = x+dx[dir];
		int ny = y+dy[dir];
		
		if(nx<0||nx>=m||ny<0||ny>=n) continue;
		if(s[x][y]<=s[nx][ny]) continue;
		
		dp[x][y]+=dfs(nx,ny);
	}
	
	return dp[x][y];
}


int main(void){

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	input();
	
	cout<<dfs(0,0);
	
	return 0;
}
