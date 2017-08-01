#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
	int T; 
	cin >> T;
	int j = 0;
	int check = 0;
	int k = 0;
	string N;
	
	for (int t = 0; t < T; t++) {
		cin >> N;
		j = -1;
		k = 0;
		check = 0;
		if (N.size() == 2) {
			cout << "Case #" << t+1 << ": ";
			if (N == "10") cout << "9";
			else if (N[1] >= N[0]) cout << N;
			else cout << (char)(N[0] -1) << "9";	
			
		}
		else {
		for (unsigned int i = 0; i < N.size() - 1; i++) {
			if (N[i] != N[i+1] && N[i] <= N[i+1]) k = i+1;
			else if ((char)N[i+1] < (char)N[i]) {
				N[k]--;
				j = i+1;
				if (i == 0 && N[i] == '0') check++;
				break;
			}
			else continue;		
		}
		//cout << j << " " << k << endl;
		cout << "Case #" << t+1 << ": ";

		

		
		for (unsigned int i = 0 + check; i < N.size(); i++) {
			if (N[i] == '0' && i == 0) continue;
			else if ((int)i <= k || j == -1 ) cout << (char)N[i];
			else cout << '9';
			
		
		}
		}
		cout << endl;
	}		
}
