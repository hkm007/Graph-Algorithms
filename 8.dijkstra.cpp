#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> iPair;

vector<iPair> graph[10];
int dis[10];

void addEdge(int a, int b, int w);
void dijkstra(int s);

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

	for(int i = 0; i < 10; i++) dis[i] = INT_MAX;
	dijkstra(1);

	return 0;
}

void addEdge(int a, int b, int w) {
	graph[a].push_back({b, w});
	graph[b].push_back({a, w});
}

void dijkstra(int s) {
	priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
	pq.push({0, s});
	dis[s] = 0;

	while(!pq.empty()) {
		int node = pq.top().second, node_dis = pq.top().first;
		pq.pop();

		for(iPair c : graph[node]) {
			int v = c.first, wt = c.second;
			if(dis[v] > node_dis+wt) {
				dis[v] = node_dis+wt;
				pq.push({dis[v], v});
			}
		}
	}

	for(int i = 1; i < 7; i++) cout << dis[i] << " ";
}
