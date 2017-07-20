#include <iostream>
#include <queue>
#include <map>

using namespace std;
int bfs(map<int,int>&);

int main(void) {
	int T,N,M,x,y;
	cin >> T;
	for (int t = 0;  t < T; t++) {
		map<int,int> board;
		cin >> N;
		for (int n = 0; n < N; n++) {
			cin >> x >> y;
			board[x] = y;
		}	
		cin >> M;
		for (int m = 0; m < M; m++) {
			cin >> x >> y; board[x] = y;
		}
		cout << bfs(board) << endl;
	}
}

int bfs(map<int,int> &board) {
	map<int,bool> visited;
	queue<pair<int,int>> Q;
	int turns = 0;
	int pos = 0;
	pair<int,int> init(1,0);
	Q.push(init);
	int current = 0;
	while (!Q.empty()) {
		current = Q.front().first;
		turns = Q.front().second;
		Q.pop();
		if (current == 100) return turns;
		for (int i = 1; i <= 6; i++) {
			pos = current + i;
			if (pos > 100) continue;
			if (board.find(pos) != board.end()) pos = board[pos];
			if (pos <= 100 && visited.find(pos) == visited.end()) {
				pair<int,int> P(pos,turns+1);
				Q.push(P);
				visited[pos] = true;	
			}
		}
		
	}
	return -1;
}
