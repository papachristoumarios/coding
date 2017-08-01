#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int main(void) {
	int T; cin >> T	;
	string line;
	int K;	
	int flips = 0;	
	for (int t = 0; t < T; t++) {
		flips = 0;
		cin >> line;
		cin >> K;
		bool change = false;
		bool impossible = false;
		queue<int> q;	
		
		for (int i = 0; i <= (int)line.length() - K; i++) {
				if (! q.empty() && q.front() == i) {
					change = !change;
					
					q.pop();
				}
				if ((line[i] == '+' && change) || (line[i] == '-' && !change)) 
				{
					flips++;
					q.push (i + K);
					change = !change;
				}
					
			
		}
		
		for (int j = (int)line.length() - K + 1; j < (int)line.length(); j++) {
			if (!q.empty() && q.front() == j) {
				change = !change;
				q.pop();				
			}
			if ((line[j] == '+' && change) || (line[j] == '-' && !change)) {
				impossible = true;
				break;
			}
			
			
		}
		if (impossible) cout << "Case #" << t+1 << ": IMPOSSIBLE" << endl; 
		else cout << "Case #" << t+1 << ": " << flips << endl;
 	}
	
}
