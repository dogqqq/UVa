#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "UVa10055"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen(PROBLEM ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	long long int a, b, ans;

	while(cin >> a >> b){
		ans = b - a;
		if(ans < 0)	ans = llabs(ans);
		cout << ans << endl;
	}

	return 0;
}