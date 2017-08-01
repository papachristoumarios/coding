#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
typedef long lint;

class Graph {
	public:
		vector<lint> *adj;
		vector<bool> visited;
		lint N;
		Graph(lint n) {
			N = n; adj = new vector<lint> [N];
			visited = *new vector<bool> (N, false);
		}
		void addEdge(int i, int j) {
			adj[i].push_back(j);
			adj[j].push_back(i);
		}
		
		lint astronauts() {
			int result = 0;
            for (lint i = 0; i < N; i++) if (visited[i] == false) {result += bfs(i);}
			return (N * (N-1)) / 2; // Number of pairs C(n,2)
			 
        }
		
		lint bfs(lint root) {
			queue<lint> Q;
			int count = 0;
			Q.push(root);
			lint current = Q.front();
			while (!Q.empty()) {
				current = Q.front();
				Q.pop();
				if (!visited[current]) {
					count++;
					visited[current] = true;
					for (lint v : adj[current]) {
						if (!visited[v]) Q.push(v);
					}	
				}
			}
			return ((count)*(count - 1))/2;
		}
	
};

int main() {
	lint N,M,x,y;
	scanf("%ld %ld", &N, &M);
    Graph G(N);
	for (lint i = 0; i < M; i++) {
		scanf("%ld %ld", &x, &y);
		G.addEdge(x,y);
	}
		printf("%ld\n", G.astronauts());	
}
