#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "UVa10954"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen(PROBLEM ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int num, ans, tmp1, tmp2;
	priority_queue<int, vector<int>, greater<int> > pq;
	while(cin >> num){
		if(num == 0)	break;

		ans = 0;
		while(!pq.empty())	pq.pop();

		for (int i = 0; i < num; ++i){
			cin >> tmp1;
			pq.push(tmp1);
		}
		while(pq.size() != 1){
			tmp1 = pq.top();
			pq.pop();
			tmp2 = pq.top();
			pq.pop();
			ans += (tmp1 + tmp2);
			pq.push(tmp1 + tmp2);
		}
		printf("%d\n", ans);
	}
	return 0;
}