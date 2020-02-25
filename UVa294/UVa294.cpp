#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "UVa294"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define N 100000

bool p[N];

void mkP(){
	p[0] = false;
	for (int i = 2; i <= sqrt(N); ++i){
		if(p[i]){
			for (int j = i*i; j < N; j+=i){
				p[j] = false;
			}

		}
	}
}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen(PROBLEM ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	memset(p, true, sizeof(p));
	mkP();

	int cases, ans, tmpans, tmpdivi;
	long int in1, in2, ansA, tmp;

	cin >> cases;
	while(cases--){
		cin >> in1 >> in2;
		ans = ansA = 0;
		for (long int i = in1; i <= in2; ++i){
			tmpans = 1;
			tmp = i;
			for (int j = 2; j <= sqrtl(i); ++j){
				tmpdivi = 0;
				while(tmp % j == 0){
					tmp /= j;
					tmpdivi++;
				}
				if(tmpdivi > 0){
					tmpans *= (tmpdivi+1);
				}
			}
			if(tmp > 1) tmpans*=2;
			// printf("i:%ld, tmpans:%d\n", i, tmpans);
			if(tmpans > ans){
				ans = tmpans;
				ansA = i;
			}
		}
		printf("Between %ld and %ld, %ld has a maximum of %d divisors.\n", in1, in2, ansA, ans);
	}

	return 0;
}