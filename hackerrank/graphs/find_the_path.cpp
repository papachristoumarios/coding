#include<bits/stdc++.h>
#include <cassert>
using namespace std;
# define INF 0x3f3f3f3f

template <typename T>
class Estimator {
	public:
		T estimate; int i, j;
		Estimator(T e, int v, int w) : estimate(e), i(v), j(w) {};
		bool operator < (const Estimator& other) { return estimate > other.estimate;}
};

template <typename T> using Edge = pair<int, T>;
template <typename T> using MinHeap = priority_queue<Estimator<T> , vector<Estimator<T>> >;

template <typename T>
class Graph
{
	public:
		vector<vector<T>> C;
	    int V,M;  
	    map<pair<int,int>,vector<vector<T>>> distances;  
	    
		Graph(int v, int m) {
			V = v, M = m;
			C = vector<vector<T>> (V, vector<T>(M, 0));	
		}
	    
	    vector<vector<T>> shortestPath(int i, int j) {
			if (distances.find(make_pair(i,j)) != distances.end()) return distances[make_pair(i,j)];
			MinHeap<T> pq;
		    vector<vector<T>> dist(V, vector<T>(M,INF));
		    pq.push(*new Estimator<T>(0,i,j));
		    dist[i][j] = C[i][j];	 
		    while (!pq.empty())
		    {
		        int u = pq.top().i;
		        int v = pq.top().j;
		        pq.pop();
				if (u - 1 > 0) relax (u,v, u-1, j, pq, dist);
		        if (u + 1 < V) relax (u,v, u+1, v, pq, dist);
		        if (v + 1 < M) relax (u,v, u, v+1, pq, dist);
		        if (v - 1 > 0) relax (u,v, u, v-1, pq, dist);
		        
		    }
		    
		    distances[make_pair(i,j)] = dist;
			return dist;
		}
			
	    void relax(int i, int j, int u, int v, MinHeap<T> &pq, vector<vector<T>>& dist) {	
			if (dist[u][v] > dist[i][j] + C[u][v])	{
				dist[u][v] = dist[i][j] + C[u][v];
				pq.push(*new Estimator<T> (dist[u][v], u, v));
 			}
		}
	
}; 

int main()
{
    int n,m;
    cin >> n >> m;
    Graph<int> G(n,m);
    
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> G.C[i][j];		
		}	
	}
	
	int q,i,j,u,v;
	cin >> q;
	for (int l = 0; l < q; l++) {
		cin >> i >> j >> u >> v;
		cout << (G.shortestPath(i,j))[u][v] << endl;
		
	}
    
}
