#include <bits/stdc++.h>
using namespace std;

vector<int> graph[10];
int vis[10];

void addEdge(int a, int b);
bool cycle(int s, int p);

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

	bool res = cycle(1, -1);
	if(res == true) cout << "Cyclic\n";
	else cout << "Acyclic\n";

	return 0;
}

void addEdge(int a, int b) {
	graph[a].push_back(b);
	graph[b].push_back(a);
}

bool cycle(int s, int p) {
	vis[s] = 1;

	for(int c : graph[s]) {
		if(!vis[c] && cycle(c, s)) return true;
		else if(c != s) return true;
	}

	return false;
}