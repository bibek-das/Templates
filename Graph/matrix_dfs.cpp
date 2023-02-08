#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e3;

int n,m;
int grid[N][N];
bool vis[N][N];

int dx[] = {1,-1,0,0,-1,-1,1,1};
int dy[] = {0,0,1,-1,-1,1,1,-1};


bool valid(int x, int y){
	return (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y]);
}

void dfs(int x,int y){
	vis[x][y] = true;
	for(int i = 0;i < 4;i++){
		int next_x = x + dx[i];
		int next_y = y + dy[i];
		if(valid(next_x,next_y)){
			dfs(next_x,next_y);
		}
	}
}


int main(){
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			cin >> grid[i][j];
		}
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			if(!vis[i][j]){
				dfs(i,j);
			}
		}
	}
}