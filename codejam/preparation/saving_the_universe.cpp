#include <iostream>
#include <vector>
#include <string.h>
#include <map>

using namespace std;

int main(void) {
	
	int N;
	cin >> N;
	int S, Q;
	string line;
	int switches = 0;	
	for (int n = 0; n < N; n++) {
		cin >> S;
		switches = 0;
		map<string,bool> visited;
		
		
		 
		for (int i = 0; i < S; i++) {
			cin >> line;
			visited[line] = false;
		}
		cin >> Q;
		int x = 0;
		for (int i = 0; i < Q; i++) {
			cin >> line; 
			if (visited.find(line) == visited.end()) continue;
			
			visited[line] = true;
			x++;
			
			
			if (x == S) {
				for (auto &v : visited) v.second = false;
				visited[line] = true;
				switches++;
				x = 1;
			}
				
		}
			

			
		cout << "Case #" << n+1 << ": " << switches << endl;
	}
}

