#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "UVa10474"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen(PROBLEM ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	vector<int> v;
	vector<int>::iterator it;
	int n, q, tmp, cases = 0;
	while(cin >> n >> q && n && q){
		cases++;
		printf("CASE# %d:\n", cases);

		for (int i = 0; i < n; ++i){
			cin >> tmp;
			v.push_back(tmp);
		}
		sort(v.begin(), v.end());

		for (int i = 0; i < q; ++i){
			cin >> tmp;
			it = find(v.begin(), v.end(), tmp);
			if(it != v.end())
				printf("%d found at %d\n", tmp, it - v.begin()+1);
			else
				printf("%d not found\n", tmp);
		}
		v.clear();

	}


	return 0;
}