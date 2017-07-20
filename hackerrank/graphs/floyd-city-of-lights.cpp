#include <climits>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;
typedef vector<vector<int>> adj;

inline void relax (adj &graph, int *dist, int u, int v) {
	
	if (dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) dist[v] = dist[u] + graph[u][v];
	
}

inline int min(int a, int b) {
	return a <= b ? a : b;
}

int minDistance(int dist[], bool sptSet[], const int& V)
{
   // Initialize min value
   int min = INT_MAX, min_index;
  
   for (int v = 0; v < V; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;
  
   return min_index;
}

int* dijkstra(adj &graph, int src,const int& V)
{
     int *dist = new int[V];  
     bool sptSet[V];
     for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
     dist[src] = 0;
  
     for (int count = 0; count < V-1; count++)
     {
       int u = minDistance(dist, sptSet, V);
       sptSet[u] = true;
	   for (int v = 0; v < V; v++)
  
     if (!sptSet[v] && graph[u][v]) relax(graph,dist,u,v);
     }
  
	return dist;
}

int main() {
    //ios::sync_with_stdio(false);
	map<int,int*> h;
	 int N,M;
	 int x,y,r;
	 scanf("%d %d", &N, &M);
	 int Q;
	 adj graph;
	for (int i = 0; i < N; i++) {
		vector<int> tmp(N);
		graph.push_back(tmp);
		h[i] = NULL;
	}
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &x, &y, &r);
		graph[x-1][y-1] = r;
	}
	scanf("%d", &Q);
	for (int q = 0; q < Q; q++) {
		scanf("%d %d", &x, &y);
		x--;
		y--;
		if (!h[x]) h[x] = dijkstra(graph, x, N); 
		printf("%d\n", h[x][y] != INT_MAX ? h[x][y]: -1);
		
		
		
	}
}
