#include <bits/stdc++.h>
using namespace std;

struct edge { int a, b, w; };
edge graph[10];
int par[10];

bool cmp(edge a, edge b) {
	return a.w < b.w;
}

int find(int a);
void merge(int a, int b);
int kruskal(void);

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

	memset(par, -1, sizeof(par));
	cout << kruskal() << endl;

	return 0;
}

int kruskal() {
	int sum = 0;
	sort(graph, graph+9, cmp);

	for(int i = 0; i < 9; i++) {
		int a = find(graph[i].a);
		int b = find(graph[i].b);

		if(a != b) {
			sum += graph[i].w;
			merge(a, b);
		}
	}

	return sum;
}

int find(int a) {
	if(par[a] == -1) return a;
	return par[a] = find(par[a]);
}

void merge(int a, int b) {
	par[a] = b;
}