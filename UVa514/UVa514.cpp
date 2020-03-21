#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "UVa514"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[]){

	#ifdef DBG
	freopen(PROBLEM ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int N, tmp, j;
	bool f, ok;
	stack<int> s;

	while(cin >> N && N){
		while(1){
			j = 2;
			f = false;
			ok = false;
			while(!s.empty())	s.pop();

			s.push(1);
			for (int i = 0; i < N; ++i){
				cin >> tmp;

				if(!tmp){
					cout << endl;
					f = true;
					break;
				}

				while(j <= N && (s.empty() || s.top() != tmp)){
					s.push(j);
					j++;
				}

				if(!s.empty() && (s.top() == tmp))
						s.pop();
				if(j >= N+1 && s.empty())	ok = true;

			}
			
			if(f)	break;
			if(ok)	cout << "Yes" << endl;
			else	cout << "No" << endl;
		}
	}
	return 0;
}