#include <cstdio>
#include <vector>
#include <queue>
#include <map>

using namespace std;
#define COST 1 //unweighted

inline int min(int a, int b) {return a <= b ? a : b;}

class Node {
	public:
		int index;
		vector<Node*> adj;
		Node(int i) : index(i), distance(-1) {};
		int distance;
};

class Graph {
	public:
		int n,m;
		vector<Node*> V; 
		map<int,bool> visited;
		Graph (int v) {
			n = v;
			for (int i = 0; i < n; i++) V.push_back(new Node(i));
		
		}

		void add_edge(int u, int v) {
			V[u-1]->adj.push_back(V[v-1]);
			V[v-1]->adj.push_back(V[u-1]);
			m++;
			
		}

		void bfs(int root, int &count) {
			count = 0; //visited nodes in equivalence class
			queue<Node*> Q;
			V[root]->distance = 0;
            Q.push(V[root]);
            visited[root] = true;
            Node *current;
			while (!Q.empty()) {
				current = Q.front();
				Q.pop();
				for (Node *v : current->adj) {
					if (visited.find(v->index) == visited.end()) {
						Q.push(v);
						visited[v->index] = true;
                        if (v->distance == -1) v->distance++;
						v->distance = current->distance + COST;
						count++;
					}	
					
				}
				
				}	
			
			for (int i = 0; i < n; i++) {
				if (i != root) printf("%d ", V[i]->distance);
			}	
			printf("\n");
			}
		
};

int main(void) {
	int Q,n,m,x,y,r,count;
	scanf("%d", &Q);
	for (int q = 0; q < Q; q++) {
		scanf("%d %d", &n, &m);
		Graph G(n);
		for (int j = 0; j < m; j++) {
			scanf("%d %d", &x, &y);
			G.add_edge(x,y);
		}
		scanf("%d", &r); r--;
		G.bfs(r,count);
		
		
	}	
}
