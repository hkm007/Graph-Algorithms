#include <bits/stdc++.h>
using namespace std;
#define N 3
#define M 5

int fun(int mat[N][M]) {
	int c = 0, p = 0, q = 0;

	queue<pair<int, int>> pq;

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			if(mat[i][j] == 2) {
				pq.push({i, j});
				p++;
			}
		}
	}

	while(p--) {
		int x = pq.front().first, y = pq.front().second;
		pq.pop();

		if(mat[x-1][y] == 1 && x != 0) {
			mat[x-1][y] = 2;
			pq.push({x-1, y});
			q++;
		}

		if(mat[x+1][y] == 1 && x != N) {
			mat[x+1][y] = 2;
			pq.push({x+1, y});
			q++;
		}

		if(mat[x][y-1] == 1 && y != 0) {
			mat[x][y-1] = 2;
			pq.push({x, y-1});
			q++;
		}

		if(mat[x][y+1] == 1 && y != M) {
			mat[x][y+1] = 2;
			pq.push({x, y+1});
			q++;
		}

		if(p == 0 && q != 0) {
			p = q;
			q = 0;
			c++;
		}
	}

	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++) if(mat[i][j] == 1) return -1;
	return c;
}

int main() {
	int mat[N][M] = { { 2, 1, 0, 2, 1 }, 
					  { 1, 0, 1, 2, 1 }, 
					  { 1, 0, 0, 2, 1 } };

	cout << fun(mat) << endl;

	return 0;
}