#include <climits>
#include <cstdio>
#include <vector>

using namespace std;
typedef vector<vector<vector<int>>> adj;

inline void relax (adj &graph, int *dist, int u, int v) {
	for (unsigned int w = 0; w < graph[u][v].size(); w++) {
	if (dist[u] != INT_MAX && dist[u] + graph[u][v][w] < dist[v]) dist[v] = dist[u] + graph[u][v][w];
	}
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
  
     if (!sptSet[v] && graph[u][v].size() > 0) relax(graph,dist,u,v);
     }
  
	return dist;
}

int main() {
    //ios::sync_with_stdio(false);

	 int V, E,T,S;
	 int x,y,r;
	 scanf("%d", &T);
	 for (int t = 0; t < T; t++) {	
		scanf("%d %d", &V, &E);
		adj graph;
		//cout << "mooo";
		for (int i = 0; i < V; i++) {
			vector<vector<int>> tmp(V);
			graph.push_back(tmp);
			//cout << "goooo";
		}	
		for (int i = 0; i < E; i++) {
			scanf("%d %d %d", &x, &y, &r);
			graph[x-1][y-1].push_back(r);
			graph[y-1][x-1].push_back(r);
		}
		scanf("%d", &S); S--;
		int *dist = dijkstra(graph, S, V);
		for (int i = 0; i < V; i++) {
			if (i == S) continue;
			if (dist[i] == INT_MAX) printf("-1");
			else printf("%d", dist[i]);
			if (i < V-1) printf(" ");
		}
		printf("\n");	
	} 
}
