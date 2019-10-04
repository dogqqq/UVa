#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "Uva00167"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int arr[10][10], queen[10], ans;

bool isValid(int c, int r){
	for (int i = 1; i < c; ++i){
		if (queen[i] == r || abs(c - i) == abs(r - queen[i])){
			return false;
		}
	}
	return true;
}

void dfs(int c){
	if (c == 9){
		int total = 0;
		for (int i = 1; i <= 8; ++i){
			total += arr[i][queen[i]];
		}
		ans = max(total, ans);
		return;
	}
	for (int i = 1; i <= 8; ++i){
		if (isValid(c, i)){
			queen[c] = i;
			dfs(c + 1);
		}
	}
}

int main(int argc, char const *argv[]){
	#ifdef DBG
	freopen(PROBLEM ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int cases;

	cin >> cases;
	while(cases--){
		ans = 0;
		for (int i = 1; i <= 8; ++i){
			for (int j = 1; j <= 8; ++j){
				cin >> arr[i][j];
			}
		}

		dfs(1);

		printf("%5d\n", ans);
	}

	return 0;
}