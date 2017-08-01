#include <cstdio>
#include <vector>
#include <set>
#include <iostream>

typedef long long number;
using namespace std;

class horse {
	public:
		number K,S; float t;
		horse(number k, number s, int &D) {
			K = k; S = s; t = ((D - K)*1.0) / (S*1.0);
		}
};

int main(void) {
	int T,D,N;
	cin >> T;
	number x,y;
	for (int t = 0; t < T; t++) {
		scanf("%d %d", &D, &N);
		vector<horse*> H;
		for (int i = 0; i < N; i++) {
			scanf("%lld %lld", &x, &y);
			H.push_back(new horse(x,y,D)); 
		}
		int max_ind = 0;
		for (int i = 1; i < N; i++) if (max_ind == -1 || H[max_ind]->t < H[i]->t) max_ind = i;	
		printf("Case #%d: %.7f\n", t+1 , (1.0*D) / H[max_ind]->t );	
	}	
}
