#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node {
public:	
	int index;
	bool colour = false;			
	vector <Node*> *adj;
	Node (int ind = -1) {
		colour = false;
		adj = new vector<Node*>;
		index = ind;
	}
};

class Edge {
	public:
		Node *in, *out;
		int weight;
		Edge (Node *u, Node *v, int w) {
			in = u;
			out = v;
			weight = w;
			in->adj->push_back(out);
			out->adj->push_back(in);	
		}
		bool operator >= (const Edge &e) {
			return weight >= e.weight;
		} 
		bool operator <= (const Edge &e) {
			return weight < e.weight;
		}
		friend ostream& operator << (ostream &out, const Edge &e) {
			out << e.in->index << " " << e.out->index << " "<< e.weight;
			return out;
		}		
};

typedef vector<Edge*> Graph;

int findParent(int i,vector<int> &parent) {
	if (parent[i] != i) i = findParent(parent[i], parent);
	return i;
}


void union_p (int src, int dest,vector<int> &parent) {
	int p1 = findParent(src, parent);
	int p2 = findParent(dest,parent);
	parent[p1] = p2;
}

Graph kruskal (Graph &E, int N, long &weight) {
	weight = 0;
	Graph mst;
	vector<int> parent(N+1);
	for (int i = 0; i < N; i++) parent[i] = i;
	sort(E.begin(), E.end(), [](Edge *a, Edge *b) {
		if (a->weight < b->weight) return true;
		else if (a->weight == b->weight) return a->in->index + a->out->index < b->in->index + b->out->index;
		else return false;
	});
	
	for (int i = 0; i < (int)E.size(); i++) {
		if (findParent(E[i]->in->index, parent) != findParent(E[i]->out->index, parent)) {
			union_p(E[i]->in->index, E[i]->out->index, parent);
			weight += E[i]->weight;
		}
	}
	
	return mst;
}

int main(void) {
	int M,N;
	int x,y,r;
	cin >> N >> M;
	vector<Node*> V;
	Graph G;
	for (int i = 0; i < N; i++) {
		Node *x = new Node(i);
		V.push_back(x);
	}
	for (int m = 0; m < M; m++) {
		cin >> x >> y >> r;
		Edge *e = new Edge(V[x-1],V[y-1], r);
		G.push_back(e);
	}
	
	long w = 0;
	Graph T;
	T = kruskal(G, N, w);
	cout << w << endl;
}
