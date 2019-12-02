#include <stack>
#include <iostream>

using namespace std;

#define PROBLEM "UVa673"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen(PROBLEM ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int cases, i;
	string str;
	stack<char> s;

	cin >> cases;
	getline(cin, str);		//for storing garbage
	while(cases--){
		while(!s.empty())	s.pop();
		getline(cin, str);

		for (i = 0; i < str.size(); ++i){
			if(str[i] == '(' || str[i] == '['){
				s.push(str[i]);
			}
			else{
				if(s.empty())	break;
				if( (s.top() == '(' && str[i] == ')') || (s.top() == '[' && str[i] == ']') ){
					s.pop();
					continue;
				}
				break;
			}
		}
		if(s.empty() && i == str.size())	printf("Yes\n");
		else	printf("No\n");

	}

	return 0;
}