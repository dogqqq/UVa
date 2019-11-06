#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "UVa686"
#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define N 35000

bool p[N];

void make_p(){
	for (int i = 0; i < N; ++i)
		p[i] = true;
	p[0] = p[1] = false; 
	for (int i = 2; i < N; ++i){
		if (p[i])
			for (int j = i*i; j < N; j+=i)
				p[j] = false;
	}
}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen(PROBLEM ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int in, tmp, ans;
	vector<int > v;

	make_p();
	for (int i = 2; i < N; ++i)
		if (p[i])	v.push_back(i);	

	while(cin >> in){
		if (in == 0)	break;
		ans = 0;
		for (int i = 0; i < in; ++i){
			if (v[i] > in ){
				tmp = i - 1;
				break;
			}
			else if(v[i] == in){
				tmp = i;
				break;
			}
		}

		for (int i = 0, j = tmp; ; ){
			if(j < i)	break;
			if (v[i] + v[j] == in){
				ans++ ;
				j--;
			}
			else if(v[i] + v[j] > in){
				j--;
			}
			else if(v[i] + v[j] < in){
				i++;
			}
		}
		cout << ans << endl;

	}
	return 0;
	
}