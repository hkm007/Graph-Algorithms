#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> iPair;

vector<iPair> graph[10];
int vis[10], mst[10], par[10], key[10];

void addEdge(int a, int b, int w);
int prims(int s);

int main() {
	addEdge(1, 2, 1);
	addEdge(1, 3, 1);
	addEdge(2, 3, 2);
	addEdge(2, 4, 3);
	addEdge(2, 5, 4);
	addEdge(3, 5, 3);
	addEdge(4, 5, 2);
	addEdge(4, 6, 1);
	addEdge(5, 6, 1);

	for(int i = 0; i < 10; i++) key[i] = INT_MAX, par[i] = -1;
	key[1] = 0;
	cout << prims(1) << endl;

	return 0;
}

void addEdge(int a, int b, int w) {
	graph[a].push_back({b, w});
	graph[b].push_back({a, w});
}

int prims(int s) {
	priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
	pq.push({0, s});
	key[s] = 0;

	while(!pq.empty()) {
		int node = pq.top().second;
		pq.pop();

		mst[node] = 1;

		for(iPair c : graph[node]) {
			int v = c.first, wt = c.second;

			if(!mst[v] && key[v] > wt) {
				key[v] = wt;
				pq.push({key[v], v});
				par[v] = node;
			}
		}
	}

	int sum = 0;
	for(int i = 1; i < 7; i++) sum += key[i];
	return sum;
}
