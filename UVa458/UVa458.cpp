#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "UVa458"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen(PROBLEM ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	string in;

	while(getline(cin, in)){
		for (int i = 0; i < in.size(); ++i){
			in[i] -= ('J' - 'C');
		}
		cout << in << endl;
	}

	return 0;
}