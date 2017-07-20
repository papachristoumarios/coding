#include<bits/stdc++.h>
#include <cassert>
using namespace std;
# define INF 0x3f3f3f3f

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
	    list< Edge<T> > *adj;
		Graph(int v, bool d = false) : V(v), directed(d), adj(new list<Edge<T>> [V]) {};
	    void addEdge(int u, int v, T w) {
			assert (w >= 0);
			adj[u].push_back(make_pair(v, w));
			if (!directed) adj[v].push_back(make_pair(u, w));
		}
	    T shortestPath(int src, int term) {
			MinHeap<T> pq;
		    vector<bool> visited(V, false);
		    
		    vector<T> dist(V, INF);
		    pq.push(*new Estimator<T>(0,src));
		    dist[src] = 0;
		    visited[src] = true;	 
		    while (!pq.empty())
		    {
		        int u = pq.top().vertex;
		        if (u == term) return dist[term]; 
		        pq.pop();
		        visited[u] = true;
		        for (Edge<T> e: adj[u]) relax(u,e,pq,dist,visited);  
		    }
			return dist[term];
		}
			
	    void relax(int u, Edge<T>& i, MinHeap<T> &pq, vector<T> &dist, vector<bool> &visited) {	
		    int v = i.first;
		    T weight = i.second;
		    T d = weight - dist[u];
		    if (d < 0) d = 0;
		    d += dist[u];
		    if (!visited[v] && d < dist[v]) {
				dist[v] = d;
				pq.push(*new Estimator<T>(dist[v], v));
			} 
		}
	
}; 

template<typename T> T in() {
	T n; char c;
    n = getchar_unlocked() - '0';
    while (isdigit((c = getchar_unlocked())))
        n = 10*n + c-'0';
    return n;	
}

int main()
{
    int N,M,x,y;
    cin >> N >> M;
    long w;
    Graph<long> G(N);
    for (int i = 0; i < M; i++) {
		cin >> x >> y >> w;
		G.addEdge(x-1,y-1,w);
	}
    
    long dist = G.shortestPath(0, N-1);
    cout << dist << endl;
}
