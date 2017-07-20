#include <vector>
#include <iostream>
using namespace std;
int result = 0;

class Node {
	public:
		bool visited = false;
		vector<Node*> adj; 	
		Node() {};
		int count() {
			if (!this) return 0;
			int cnt = 0; 
			visited = true;
			for (Node *tmp : adj)  
					cnt += tmp->count();	
			if (cnt % 2) result++;
			return 1 + cnt;
		}	
};

int main(void) {
	int N,M,x,y;
	cin >> N >> M;
	vector<Node*> V;
	for (int i = 0; i < N; i++) V.push_back(new Node());
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		V[x-1]->adj.push_back(V[y-1]);
	}
	V[0]->count();
	cout <<  result - 1 << endl;
}


