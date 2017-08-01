#include <iostream>
#include <vector>

#define INF  1001001001
#define INFLL  1001001001001001001LL

typedef long long llint;

using namespace std;

inline bool isdigit (char x) {return x >= '0' && x <= '9';}

template <typename T> T read() {
	int c; 
	T n;
    n = getchar_unlocked() - '0';
    while (isdigit((c = getchar_unlocked())))
        n = 10*n + c-'0';
    return n;	
}

template <typename T> void min (T &a, T b) {
	a = (a > b) ? b : a;	
}

template <typename T> void floydWarshall(vector<vector<T>> &D, int &N) {
	//Floyd Warshall (all pair shortest paths)
	for (int k = 0; k < N; k++) 
		for (int i = 0; i < N; i++) 
			for (int j = 0; j < N; j++) 
				min(D[i][j], D[i][k] + D[k][j]);

}

void solve(void)
{
	int N, Q;
	N = read<int>();
	Q = read<int>();
	vector<vector<llint>> D(N, vector<llint>(N));
	vector<vector<double>> Y(N, vector<double>(N,0));

	vector<int> E, S;
	for (int i = 0; i < N; i++) {
		E.push_back(read<int>());
		S.push_back(read<int>());
	}	
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			D[i][j] = read<llint>();
			if (D[i][j] == -1) D[i][j] = (i == j ? 0 : INFLL);
		}
	}
	
	floydWarshall(D,N);
	
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			if (i != j) 
				Y[i][j] = (D[i][j] > E[i]) ? INFLL : D[i][j] / (S[i]*1.0);
	
	floydWarshall(Y,N);
							
	while(Q--) {
		int u = read<llint>() - 1;
		int v = read<llint>() - 1;
		cout << Y[u][v] << endl;
	}
	
}

int main(void) {
	int T = read<int>();
	while (T--) {
		cout << "Case #" << T << ": ";
		solve();
	}
}
