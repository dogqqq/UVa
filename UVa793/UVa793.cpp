#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "UVa793"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define N 100005

int pa[N];

int find(int x){
	return pa[x] < 0 ? x : pa[x] = find(pa[x]);
}

void Union(int x, int y){
	x = find(x);
	y = find(y);

	if(x == y)	return;	
	if(pa[x] <= pa[y]){
		pa[x] += pa[y];
		pa[y] = x;
	}
	else{
		pa[y] += pa[x];
		pa[x] = y;
	}
}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen(PROBLEM ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	char ch, gar;
	int cases, num, x, y, suA, faA;
	string s;

	cin >> cases;
	getchar();

	for (int i = 0; i < cases; ++i){
		if(i)	cout << endl;
		
		cin >> num;
		suA = faA = 0;
		memset(pa, -1, sizeof(pa));
		getchar();

		while(getline(cin, s) && s != ""){
			stringstream ss(s);
			ss >> ch >> x >> y;
			// printf("ch:%c, x:%d, y:%d\n", ch, x, y);

			if(ch == 'c'){
				Union(x, y);
			}
			else{
				if(find(x) == find(y))	suA++;
				else	faA++;
			}
		}
		printf("%d,%d\n", suA, faA);
	}


	return 0;
}