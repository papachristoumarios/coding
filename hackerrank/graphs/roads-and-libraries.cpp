#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef unsigned long long llint;

llint explore(vector<bool> &accesible, map<llint, vector<llint>> &orig, map<llint, vector<llint>> &dest, llint start, llint &croad, llint &clib, bool init) {
	llint res = 0;
	if (!accesible[start]) {
		accesible[start] = true;
		res = init ? clib : croad;
		if (orig.find(start) != orig.end()) {
			for (llint i : orig[start]) if (!accesible[i]) res += explore(accesible, orig, dest, i, clib, croad, false);	
		}
		if (dest.find(start) != dest.end()) {
			for (llint i : dest[start]) if (!accesible[i]) res += explore(accesible, orig, dest, i, clib, croad, false);	
		}
		return res; 
	}
	else return 0;	
		
}

void solve() {
	llint n,m,clib,croad;
	cin >> n >> m >> clib >> croad;
	if (croad > clib) {
		cout << clib*n << endl; return;
	}
	else {
	map<llint,vector<llint>> orig;
	map<llint,vector<llint>> dest;
	vector<bool> accesible(n,false);
	llint result = 0;
	llint x,y;
	
	for (llint j = 1; j <= m; j++)	{
		cin >> x >> y;
		x--; y--;
		orig[x].push_back(y);
		dest[y].push_back(x);
	}
	for (llint i = 0; i < n; i++) if (!accesible[i]) result += explore(accesible, orig, dest, i, clib, croad, true);
	cout << result << endl;
	orig.clear(); dest.clear();
	cin.clear();
	}
}

int main(void) {
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		solve();
	}	
}
