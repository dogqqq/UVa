#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "UVa1160"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define N 100005
int parent[N];

int find(int x){
	return x == parent[x] ? x : parent[x] = find(parent[x]);
}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen(PROBLEM ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int inx, iny;
	int x, y, ans;

	while(cin >> inx){
		ans = 0;
		for (int i = 0; i < N; ++i){
			parent[i] = i;
		}
		while(inx != -1){
			cin >> iny;

			x = find(inx);
			y = find(iny);
			// printf("x:%d, y:%d\n", x, y);
			if(x == y)	ans++;
			else	parent[x] = y;

			cin >> inx;
		}
		cout << ans << endl;
		
	}

	return 0;
}