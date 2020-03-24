#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "UVa12100"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen(PROBLEM ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int cases, n, m, tmp, ans;
	queue<pair<int, int>> q;
	priority_queue<int> pq;
	cin >> cases;
	while(cases--){

		ans = 0;
		while(!q.empty())	q.pop();
		while(!pq.empty())	pq.pop();

		cin >> n >> m;
		for (int i = 0; i < n; ++i){
			cin >> tmp;
			pq.push(tmp);
			q.push(make_pair(i, tmp));
		}

		while(1){
			if(pq.top() == q.front().second){
				if(q.front().first == m){
					ans++;
					cout << ans << endl;
					break;	
				}
				else{
					q.pop();
					pq.pop();
					ans++;
				}
			}
			else{
				q.push(q.front());
				q.pop();
			}
		}
	}

	return 0;
}