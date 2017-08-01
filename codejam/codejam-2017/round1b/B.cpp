//#include <bits/stdc++.h>

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <string.h>

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

class colour {
	public:
		char id;
		int V;
		colour(char c, int x) : id(c), V(x) {};
	
};


int main(void) {
	int T;
	int R,Y,B,G,O,V,N;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N >> R >> O >> Y >> G >> B >> V;
		vector<char> output(N);
		vector<colour*> colours(7,NULL);
		colours[0] = new colour('R',R);
		colours[1] = new colour('O',O);
		colours[2] = new colour('Y',Y);
		colours[3] = new colour('G',G);
		colours[4] = new colour('B',B);
		colours[5] = new colour('V',V);
		cout << "Case #" << t+1 << ": ";	
	
		sort(colours.begin(), colours.end(), [](colour *x, colour *y) {
			return (x->V < y-> V && x->V != 0);
		});	
		
		if (G == 0 && V == 0 && O == 0) {
			if (colours[3]->V == 0 && colours[2]->V == 0) {cout << "IMPOSSIBLE" << endl; continue;}
			else if (colours[3]->V == 0 && ! ( (N%2 == 0 && colours[1] == colours[2])) || (N%2 == 1 && colours[2] - colours[1] == 1)) {cout << "IMPOSSIBLE" << endl; continue;} 
			else if (!( ((N - 3*colours[0]->V) % 2 == 0) && (colours[1]->V == colours[2]->V) || ( (N-3*colours[0]->V) % 2 == 1  && (colours[2] - colours[1]) ))) cout << "IMPOSSIBLE" << endl; continue;}
			else {
				int i = 0;
				while( i < N && i < colours[0]->V) {
					output[i] = colours[0]->id;	
					output[i+1] = colours[1]->id;	
					output[i+2] = colours[2]->id;	
					i += 3;				
				}
				colours[1]->V -= colours[0]->V;
				colours[2]->V -= colours[0]->V;	
				while ( i < N && i - 3*colours[0]->V < colours[1]->V) {
					output[i] = colours[1]->id;
					output[i+1] = colours[2]->id;
					i += 2;
				}
		}	
		
		
		
		
	}	

}
