#include <bits/stdc++.h>
using namespace std;

vector<int> graph[10], res;
int in[10];

void addEdge(int a, int b);
void kahn(int n);

int main() {
	addEdge(1, 2);
	addEdge(1, 8);
	addEdge(2, 5);
	addEdge(2, 9);
	addEdge(3, 4);
	addEdge(4, 5);
	addEdge(4, 8);
	addEdge(5, 7);
	addEdge(5, 9);
	addEdge(6, 7);

	kahn(9);

	return 0;
}

void addEdge(int a, int b) {
	graph[a].push_back(b);
	in[b]++;
}

void kahn(int n) {
	queue<int> q;
	for(int i = 1; i <= n; i++) if(in[i] == 0) q.push(i);

	while(!q.empty()) {
		int curr = q.front();
		q.pop();
		res.push_back(curr);

		for(int c : graph[curr]) {
			in[c]--;
			if(in[c] == 0) q.push(c);
		}
	}

	for(int i : res) cout << i << " ";
}