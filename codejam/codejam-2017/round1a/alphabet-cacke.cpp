#include <iostream>
#include <string> 
#include <queue>

using namespace std;

int main(void) {
	int T,R,C;
	cin >> T;
	string line, prev, next;
	int qm = 0;
	int x1 = -1, x2 = -1;
	int faulty = 0;
	
	for (int t = 0; t < T; t++) {
		cout << "Case #" << t+1 << ": " << endl;	
		cin >> R >> C;
		faulty = 0;
		for (int r = 0; r < R; r++) {
			qm = 0;
			cin >> line;
			queue<int> Q;
			for (int i = 0; i < C; i++) {
				if (line[i] == '?') {
					qm++;
					if ((i > 0 && line[i-1] != '?') || i == 0 || i == C-1) Q.push(i);
				}
				if (line[i] != '?' && i > 0 && line[i-1] == '?') {
					Q.push(i-1); 
				}			
			}
			
			if (qm == C) { // if line 1 has ? TODO
				if (r == faulty) faulty++;
				else {
					line = prev;
					cout << line << endl;
					continue;
				}
				
			}
			
			
			x1 = Q.front();
			Q.pop();
			x2 = Q.front();
			Q.pop();
			for (int i = 0; i < C; i++) {
				if ((i >= x1 && i <= x2) ||) {
					if (x2 == C-1) line[i] = line[x1 - 1];
					else line[i] = line[x2 + 1]; 
				}
				else {
					if (i < C-1 && i+1 == Q.front()) {
						x1 = Q.front(); Q.pop();
						x2 = Q.front(); Q.pop();
					}
					
				}
			}
			
			if (r == faulty && qm != C) {
				for (int k = 0; k <= faulty; k++) cout << line << endl;
				faulty = 0;
			}
			
			
			prev = line;
		}
	}	

}
