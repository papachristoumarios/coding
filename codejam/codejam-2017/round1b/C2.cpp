#include<bits/stdc++.h>
using namespace std;

const float INF = numeric_limits<float>::max();

template <typename T>
class Estimator {
	public:
		T estimate; int vertex;
		Estimator(T e, int v) : estimate(e), vertex(v) {};
		bool operator < (const Estimator& other) { return estimate > other.estimate;}
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
		Graph(int v, bool d = true) : V(v), directed(d), adj(new list<Edge<T>> [V]) {};
	    void addEdge(int u, int v, T w) {
			adj[u].push_back(make_pair(v, w));
			if (!directed) adj[v].push_back(make_pair(u, w));
		}
	    vector<T> shortestPath(int src) {
			if (distances.find(src) != distances.end()) return distances[src];
			MinHeap<T> pq;
		    vector<T> dist(V, INF);
		    pq.push(*new Estimator<T>(0,src));
		    dist[src] = 0;	 
		    while (!pq.empty())
		    {
		        int u = pq.top().vertex;
		        pq.pop();
		        for (Edge<T> e: adj[u]) relax(u,e,pq,dist);  
		    }
		    distances[src] = dist;
			return dist;
		}
			
	    void relax(int u, Edge<T>& i, MinHeap<T> &pq, vector<T> &dist ) {	
		    int v = i.first;
		    T weight = i.second;       
		    if (dist[v] > dist[u] + weight) {
				dist[v] = dist[u] + weight;
				pq.push(* new Estimator<T>(dist[v], v));
			}
		}	
	
}; 

int main()
{
	
	int T; cin >> T;
	int N,Q;
	float x;
	
	for (int t = 1; t <= T; t++) {
		cin >> N >> Q;
		Graph<float> G(N);
		vector<float> E(N,0);	
		vector<float> S(N,0);	
		map<int, vector<float> > distances;
		for (int i = 0; i < N; i++) cin >> E[i] >> S[i];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> x;
				if (x != -1.0) G.addEdge(i,j,x);
			}
		}
		for (int i = 0; i < N; i++) distances[i] = G.shortestPath(i);
		Graph<float> H(N);
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i == j) continue;
				if (distances[i][j] != INF && E[i] >= distances[i][j]) H.addEdge(i,j,distances[i][j] / S[i]);	
				if (distances[i][j] == INF) H.addEdge(i,j,INF);				
			}	
		}
		int i,j;
		cout << "Case #" << t << ": ";
		distances.clear();
		for (int q = 0; q < Q; q++) {
			cin >> i >> j; i--; j--;
			if (distances.find(i) == distances.end()) distances[i] = H.shortestPath(i);
			cout << distances[i][j] << " ";  
		}
		cout << endl;
	}	
}
