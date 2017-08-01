#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

typedef queue<unsigned int> Queue;

inline char min(char a, char b) {
	if (a == '?' && b != '?') return b;
	if (b == '?' && a != '?') return a;
	else return a <= b ? a : b;
}

inline void subtract(string &y) {
	unsigned int i = y.size() -1;
	
	while (i >= 1) {
		if (y[i] != '0') {y[i]--; break;}
		y[i] = '9'; y[i-1]--; i--;
	}	
}

int main (void) {
	int T;
	string x,y;
	cin >> T;
	char tmp;
	bool flag = false;
	for (int t = 1; t <= T; t++) {
		cin >> x >> y;
		Queue q,r;
		flag = false;
		unsigned int j = 0;
		while (x[j] == '?' && y[j] == '?' && j < x.size()) {
			x[j] = y[j] = '0'; j++;
		}
		unsigned int i = j;
		
		while (i < x.size()) {	
			if (x[i] != '?' && y[i] == '?') {y[i] = x[i]; tmp = x[i]; if (flag == true) {r.push(i); flag = false;} }
			else if (x[i] == '?' && y[i] != '?') {x[i] = y[i]; tmp = y[i]; if (flag == true) {r.push(i); flag = false;}}
			else if (x[i] != '?' && y[i] != '?') {tmp = min(x[i],y[i]); q.push(i); flag = true; i++; continue;}
			x[i] = min(tmp, x[i]);
			y[i] = min(tmp, y[i]);		
			i++;
		}
		
		while (!q.empty()) {
			i = q.front(), j = r.front();
			if (x[i]  < y[i] && i != 0) x[i-1]++;
			for (unsigned int k = i +1; k < j; k++) x[k] = '0', y[k] = '9';	
			q.pop(); r.pop();
	
			
		}
		

	cout << "Case #" << t << ": " << x << " " << y << endl;
	}
}
