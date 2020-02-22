#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "UVa10300"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen(PROBLEM ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int cases, line, ani;
	long long int farm, ecofr, sum;

	cin >> cases;
	for (int i = 0; i < cases; ++i){
		sum = 0;
		cin >> line;
		for (int j = 0; j < line; ++j){
			cin >> farm >> ani >> ecofr;
			sum += farm * ecofr;
		}
		cout << sum << endl;
	}
	return 0;
}