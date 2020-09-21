#include <bits/stdc++.h>
using namespace std;

struct edge { int a, b, w; };
edge graph[10];
int dis[10];

void bellman(int s);

int main() {
	graph[0].a = 1;
	graph[0].b = 2;
	graph[0].w = 1;

	graph[1].a = 1;
	graph[1].b = 3;
	graph[1].w = 1;

	graph[2].a = 2;
	graph[2].b = 3;
	graph[2].w = 2;

	graph[3].a = 2;
	graph[3].b = 4;
	graph[3].w = 3;

	graph[4].a = 2;
	graph[4].b = 5;
	graph[4].w = 4;

	graph[5].a = 3;
	graph[5].b = 5;
	graph[5].w = 3;

	graph[6].a = 4;
	graph[6].b = 5;
	graph[6].w = 2;

	graph[7].a = 4;
	graph[7].b = 6;
	graph[7].w = 1;

	graph[8].a = 5;
	graph[8].b = 6;
	graph[8].w = 1;

	for(int i = 0; i < 10; i++) dis[i] = INT_MAX;
	bellman(1);

	return 0;
}

void bellman(int s) {
	dis[s] = 0;
	
	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 9; j++) {
			int u = graph[j].a, v = graph[j].b, w = graph[j].w;
			if(dis[u] != INT_MAX && dis[u]+w < dis[v]) dis[v] = dis[u]+w;
		}
	}	

	for(int i = 1; i < 7; i++) cout << dis[i] << " ";
}