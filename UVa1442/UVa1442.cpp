#include <bits/stdc++.h>
#define N 1000010
using namespace std;

#define PROBLEM "UVa1442"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int ceilings[N], floors[N], RL, LR[N], tmp;

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen(PROBLEM ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int cases, num, ans;

	cin >> cases;
	while(cases--){
		cin >> num;
		ans = 0;
		for (int i = 0; i < num; ++i)
			cin >> floors[i];
		for (int i = 0; i < num; ++i)
			cin >> ceilings[i];

		LR[0] = tmp = ceilings[0];
		for (int i = 1; i < num; ++i){
			if (tmp > ceilings[i]){
				LR[i] = ceilings[i];
				tmp = LR[i];
			}
			else if(tmp <= ceilings[i] && tmp >= floors[i]){
				LR[i] = tmp;
			}
			else{
				LR[i] = floors[i];
				tmp = LR[i];
			}
		}

		RL = tmp = ceilings[num-1];
		for (int i = num - 1; i >= 0; --i){
			if (tmp > ceilings[i]){
				RL = ceilings[i];
				tmp = RL;
			}
			else if(tmp <= ceilings[i] && tmp >= floors[i]){
				RL = tmp;
			}
			else{
				RL = floors[i];
				tmp = RL;
			}
			ans += min(RL, LR[i]) - floors[i];
		}

		cout << ans << endl;

	}

	return 0;
}