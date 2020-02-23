#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "UVa445"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

bool isOut(char in){
	if(in >= 'A' && in <= 'Z')	return true;
	if(in == '*' || in == 'b') return true;
	return false;
}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen(PROBLEM ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int cnt;
	string in;

	while(getline(cin, in)){
		cnt = 0;
		if(in[0] == '\n'){
			cout << endl;
			continue;
		}
		for (int i = 0; i < in.size(); ++i){
			if(in[i] == '!'){
				cout << endl;
				continue;
			}
			if(!isOut(in[i])){
				cnt += (in[i] - '0');
			}
			else{
				if(in[i] == 'b'){
					while(cnt--){
						cout << " " ;
					}
				}
				else{
					while(cnt--){
						cout << in[i];
					}
				}
				cnt = 0;
			}
		}
		cout << endl;
	}

	return 0;
}