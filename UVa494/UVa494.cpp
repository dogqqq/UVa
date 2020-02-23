#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "UVa494"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

bool isChar(char check){
	if(check >= 'a' && check <= 'z')	return true;
	if(check >= 'A' && check <= 'Z')	return true;
	return false;
}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen(PROBLEM ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	string in;
	int ans;

	while(getline(cin, in)){
		ans = 0;
		for (int i = 1; i < in.size(); ++i){
			if(isChar(in[i-1]) && !(isChar(in[i]))){
				ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}