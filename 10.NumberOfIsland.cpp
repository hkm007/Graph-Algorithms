#include <bits/stdc++.h>
using namespace std;
#define N 4
#define pi pair<int, int>

int vis[N][N];

bool valid(int i, int j) {
	return (i < N && i >= 0 && j < N && j >= 0);
}

int main() {
	int graph[N][N] = { { 1, 0, 0, 1 }, 
					    { 0, 1, 0, 1 }, 
					    { 0, 0, 0, 0 }, 
					    { 1, 0, 1, 1 } };
 
	int count = 0;

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(graph[i][j] && !vis[i][j]) {
				++count;
				queue<pi> q;
				q.push({i, j});
				vis[i][j] = 1;

				while(!q.empty()) {
					pi curr = q.front();
					q.pop();
					int x = curr.first, y = curr.second;

					if(valid(x-1, y) && graph[x-1][y] && !vis[x-1][y]) {
						q.push({x-1, y});
						vis[x-1][y] = 1;
					}

					if(valid(x+1, y) && graph[x+1][y] && !vis[x+1][y]) {
						q.push({x+1, y});
						vis[x+1][y] = 1;
					}

					if(valid(x, y-1) && graph[x][y-1] && !vis[x][y-1]) {
						q.push({x, y-1});
						vis[x][y-1] = 1;
					}

					if(valid(x, y+1) && graph[x][y+1] && !vis[x][y+1]) {
						q.push({x, y+1});
						vis[x][y+1] = 1;
					}
				}
			}
		}
	}

	cout << count << "\n";

	return 0;
}