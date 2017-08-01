#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main(void) {
	int T;
	unordered_map<char,int> H;
	cin >> T;
	string s;
	string NUMS[10] = {"ZERO","ONE", "TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};
	int min = -1;
	int foo = 0;
		
	for (int t = 1; t <= T; t++) {
		for (char c = 'A'; c <= 'Z'; c++) H[c] = 0;	
		cout << "Case #" << t << ": ";
		cin >> s;
		for (unsigned int i = 0; i <= s.size(); i++) H[s[i]]++;
		foo = 0;	
		//for (char c = 'A'; c <= 'Z'; c++) cout << (char)c << H[c] << endl;
		for (string r : NUMS) {
			min = -1;
			for (unsigned int i = 0; i <= r.size(); i++)	
				if ((H[r[i]] > 0 && H[r[i]] < min) || min == -1) min = (int)H[r[i]];
			for (unsigned int i = 0; i <= r.size(); i++)	
				if (H[r[i]] < min || min == -1) H[r[i]] -= min;
			
			if ((foo != 3 && foo != 7 && foo != 9) || (foo == 3 && H['E'] >= 2) || (foo == 7 && H['E'] >= 2) || (foo == 9 && H['N'] >= 2) )
			for (int u = 0; u < min; u++) cout << foo; 
			foo++;
			
			}
			
		cout << endl;
	}	
	
}
