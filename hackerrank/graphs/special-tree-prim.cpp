#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
inline bool isdigit (char x) {return x >= '0' && x <= '9';}

int readInt() {
	int c, n;
    n = getchar_unlocked() - '0';
    while (isdigit((c = getchar_unlocked())))
        n = 10*n + c-'0';
    return n;	
}

class Edge {
	public:
		int v,w;
		Edge(int V, int W) : v(V), w(W) {};
		bool operator < (const Edge& other) {return w > other.w;}
};

int prim(vector<Edge> *adj, int src, int n) {
	priority_queue<Edge, vector<Edge>> min_heap;	
	vector<bool> visited(n,false);
	min_heap.push(Edge(src,0));
	int weight = 0;
	while (!min_heap.empty()) {
		Edge e = min_heap.top();
		min_heap.pop();
		if (visited[e.v]) continue;
		weight += e.w;
		visited[e.v] = true;
		for (Edge q: adj[e.v]) {
			if (!visited[q.v]) min_heap.push(q);
		}
	}
	return weight;
}

int main(void) {
	int n = readInt();
	int m = readInt();
	vector<Edge> *adj = new vector<Edge> [n];	
	int x,y,w;
	for (int i = 0; i < m; i++) {
		x = readInt()-1; y = readInt()-1; w = readInt();
		adj[x].push_back(Edge(y,w));
		adj[y].push_back(Edge(x,w));
	}
	int src = readInt() - 1;
	printf("%d\n", prim(adj, src, n));
}

