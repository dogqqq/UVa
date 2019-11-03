#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "UVa1620"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

#define N 505

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen(PROBLEM ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int cases, num, arr[N], cnt;
	cin >> cases;
	while(cases --){
		cin >> num;
		cnt = 0;
		for (int i = 0; i < num; ++i){
			cin >> arr[i];
		}	
		for (int i = 0; i < num; ++i){
			for (int j = i + 1; j < num; ++j){
				if(arr[i] > arr[j]){
					cnt ++;
				}
			}
		}
		if (cnt % 2 == 1 && num % 2 == 1){
			printf("impossible\n");
		}
		else{
			printf("possible\n");
		}

	}
	return 0;
}