#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int T,N,P,x = 0;
	int max = 0;
	int zeros = 0;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		max = 0;
		cin >> N >> P;
		vector<int> R(N,0);
		for (int i = 0; i < N; i++) {
			cin >> R[i]; R[i] = 90*R[i]/100;
			
		}
		for (int i = 0; i < N; i++) {
			zeros = 0;
			for (int j = 0; j < P; j++) {
				cin >> x;
				if (x / R[i] == 0) zeros++;
			}
			if (zeros > max) max = zeros;
		}
		cout << (P - max) << endl;	
	}	

}

