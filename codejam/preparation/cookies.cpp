#include <cstdio>

using namespace std;

int main (void) {
	unsigned int T;
	double C, X, F, R = 2;
	double time = 0;	
	scanf("%d", &T);
	
	for (unsigned int t = 0; t < T; t++) {
		scanf("%lf %lf %lf", &C, &F, &X);
		time = 0;
		R = 2;
		printf("Case #%d: ", t+1);
	if (X <= C) time = X / R;
	else	
	while (true) {	
		time += C / R;	
			if ((X-C)/R <= X / (R+F)) { // do not buy
				time += (X-C) / R;
				break;
			}
			else R += F;
					
		}
		printf("%.7f\n", time);
	}

}


