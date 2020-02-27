#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "UVa280"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

bool ver[105][105], visit[105];
int ans, arr[105];

void dfs(int check, int n){
	for (int i = 1; i <= n; ++i){
		if(!visit[i] && ver[check][i]){
			visit[i] = true;
			dfs(i, n);
		}
	}
}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen(PROBLEM ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int n, tmp;
	int start, to, cases, check;

	while(cin >> n && n){
		memset(ver, false, sizeof(ver));
		memset(visit, false, sizeof(visit));
		memset(arr, 0, sizeof(arr));
		while(cin >> start && start){
			while(cin >> to && to){
				ver[start][to] = true;
			}
		}
		cin >> cases;
		for (int i = 0; i < cases; ++i){
			cin >> check;
			ans = 0;
			memset(visit, false, sizeof(visit));
			memset(arr, 0, sizeof(arr));
			dfs(check, n);
			for (int j = 1; j <= n; ++j){
				if(!visit[j]){
					arr[ans] = j;
					ans++;
				}	
			}
			cout << ans ;
			tmp = 0;
			while(arr[tmp]){
				cout << ' ' << arr[tmp]; 
				tmp++;
			}
			cout << endl;
		}
	}
	return 0;
}