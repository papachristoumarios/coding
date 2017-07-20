#include<bits/stdc++.h>
using namespace std;
#define NIL 0
#define INF INT_MAX
typedef long long llint; 
 
class BipGraph
{
    int m, n;
    list<int> *adj;
    int *pairU, *pairV, *dist;
 
public:
    BipGraph(int M, int N) {
		m = M, n = N;
		adj = new list<int>[M+1];	
	}

    void addEdge(int u, int v) {
		adj[u].push_back(v);
	}
	
    bool bfs() {
		queue<int> Q; 
	    for (int u=1; u <= m; u++)
	    {
	        if (pairU[u]==NIL)
	        {
	            dist[u] = 0;
	            Q.push(u);
	        }
	        else dist[u] = INF;
	    }
	
	    dist[NIL] = INF;
	    while (!Q.empty())
	    {
	        int u = Q.front();
	        Q.pop();
	
	        if (dist[u] < dist[NIL])
	        {
	            list<int>::iterator i;
	            for (i=adj[u].begin(); i!=adj[u].end(); ++i)
	            {
	                int v = *i;
	                if (dist[pairV[v]] == INF)
	                {
	                    dist[pairV[v]] = dist[u] + 1;
	                    Q.push(pairV[v]);
	                }
	            }
	        }
	    } 
	    return (dist[NIL] != INF);	
	}
	
    bool dfs(int u) {
	    if (u != NIL)
	    {
	        list<int>::iterator i;
	        for (i=adj[u].begin(); i!=adj[u].end(); ++i)
	        {
	            int v = *i;
	            if (dist[pairV[v]] == dist[u]+1)
	            {
	
	                if (dfs(pairV[v]) == true)
	                {
	                    pairV[v] = u;
	                    pairU[u] = v;
	                    return true;
	                }
	            }
	        } 
	        dist[u] = INF;
	        return false;
	    }
	    return true;
	}
    
    int hopcroftKarp() {
		pairU = new int[m+1];
	    pairV = new int[n+1];
	    dist = new int[m+1];
	    for (int u=0; u<m; u++)
	        pairU[u] = NIL;
	    for (int v=0; v<n; v++)
	        pairV[v] = NIL;
	    int result = 0;
	
	    while (bfs())
	    {
	    for (int u=1; u<=m; u++)
	            if (pairU[u]==NIL && dfs(u))
	                result++;
	    }
	    return result;
	}
};
 

class House {
    public:
        llint area, price;
        House(llint a, llint p) : area(a), price(p) {};
};

int main(void) {
   int n,m;
   cin >> n >> m;
   BipGraph G(n,m);
   vector<House> X(n+1,House(0,0));
   vector<House> Y(m+1,House(0,0));
   for (int i = 1; i <= n; i++) cin >> X[i].area >> X[i].price;
   for (int i = 1; i <= m; i++) cin >> Y[i].area >> Y[i].price;
    
   for (int i = 1; i <= n; i++) 
       for (int j = 1; j <= m; j++) 
           if (Y[j].area > X[i].area && Y[j].price <= X[i].price) 
               G.addEdge(i,j);   
   cout << G.hopcroftKarp() << endl; 
}
