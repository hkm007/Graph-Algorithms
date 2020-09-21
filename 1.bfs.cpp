#include <bits/stdc++.h>
using namespace std;

vector<int> graph[10];
int vis[10];

void addEdge(int a, int b);
void bfs(int s);

int main() {
	addEdge(1, 2);
	addEdge(1, 3);
	addEdge(2, 3);
	addEdge(2, 4);
	addEdge(2, 5);
	addEdge(3, 5);
	addEdge(4, 5);
	addEdge(4, 6);
	addEdge(5, 6);

	bfs(1);

	return 0;
}

void addEdge(int a, int b) {
	graph[a].push_back(b);
	graph[b].push_back(a);
}

void bfs(int s) {
	queue<int> q;
	q.push(s);
	vis[s] = 1;

	while(!q.empty()) {
		int curr = q.front();
		q.pop();

		cout << curr << " ";

		for(int c : graph[curr]) {
			if(!vis[c]) {
				vis[c] = 1;
				q.push(c);
			}
		}
	}
}