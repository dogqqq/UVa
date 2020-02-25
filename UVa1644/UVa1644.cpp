#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "UVa1644"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define N 1300000

bool p[N];

void mkP(){
	p[0] = p[1] = false;
	for (int i = 2; i < sqrt(N); ++i){
		if(p[i]){
			for (int j = i*i; j < N; j+=i){
				p[j] = false;
			}
		}
	} 
}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen(PROBLEM ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int in, small, big;
	memset(p, true, sizeof(p));
	mkP();

	while(cin >> in){
		if(!in)	break;
		if(p[in]){
			cout << '0' << endl;
		}
		else{
			small = in - 1;
			big = in + 1;
			while(!p[small]){
				small--;
			}	
			while(!p[big]){
				big++;
			}	
			cout << big - small << endl;
		}
	}

	return 0;
}