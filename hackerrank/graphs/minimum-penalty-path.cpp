#include<bits/stdc++.h>
#include <cassert>
using namespace std;
#define INF 0x3f3f3f3f
#define MAXM 1024

template <typename T>
class Estimator {
	public:
		T estimate; int vertex;
		Estimator(T e, int v) : estimate(e), vertex(v) {};
		bool operator < (const Estimator& other) const { return estimate > other.estimate;}
};

template <typename T> using Edge = pair<int, T>;
template <typename T> using MinHeap = priority_queue<Estimator<T> , vector<Estimator<T>> >;

template <typename T>
class Graph
{
	public:
	
	    int V; bool directed; 
	    map<int,vector<T>> distances;  
	    list< Edge<T> > *adj;
		Graph(int v, bool d = false) : V(v), directed(d), adj(new list<Edge<T>> [V]) {};
	    void addEdge(int u, int v, T w) {
			assert (w >= 0);
			adj[u].push_back(make_pair(v, w));
			if (!directed) adj[v].push_back(make_pair(u, w));
		}
	    T minPenaltyPath(int src, int t) {
			queue<T> P,Q;
			vector<vector<bool>> visited(V, vector<bool>(MAXM,false));
			visited[src][0] = true;
			Q.push(src);
			P.push(0);
			while (!Q.empty()) {
				int q = Q.front();
				int p = P.front();
				Q.pop(); P.pop();
				for (Edge<T> e: adj[q]) {
					if (!visited[e.first][p | e.second]) {
						visited[e.first][p | e.second] = true;
						Q.push(e.first);
						P.push(p | e.second);
					}
				}
			}
			for (int i = 0; i < MAXM; i++) if (visited[t][i]) return i;
			return -1;		
		}
		
		
		T bellmanFord(int s, int t) {
			vector<T> dist(V,INF);
			dist[s] = 0;
			
			for (int i = 0; i < V; i++) {
				for (Edge<T> e: adj[i]) 
					relax(i,e,dist);
			}
			
			return dist[t] == INF ? -1 : dist[t];
		}
		
		void relax(int u, Edge<T>& i, vector<T> &dist ) {	
		    int v = i.first;
		    T weight = i.second;       
		    if (dist[u] != INF && dist[v] > (dist[u] | weight)) {
				dist[v] = (dist[u] | weight);
			}
		}
	
}; 

int readInt() {
	int c, n;
    n = getchar_unlocked() - '0';
    while (isdigit((c = getchar_unlocked())))
        n = 10*n + c-'0';
    return n;	
}

int main()
{
    int N = readInt();
    int M = readInt();
    int x, y, w;
    Graph<int> G(N);
    for (int i = 0; i < M; i++) {
		x = readInt() -1, y = readInt() - 1, w = readInt();
		G.addEdge(x,y,w);
	}
    int a = readInt() - 1;
    int b = readInt() - 1;
    printf("%d\n", G.bellmanFord(a,b));
    
}
