#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "UVa732"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

string in, tar;
vector<char> ans;
stack<char> s;

void init(){
	ans.clear();
	while(!s.empty())
		s.pop();
	return;
}

void dfs(int pushRe, int popRe){
	if(popRe == tar.size()){
		cout << ans[0];
		for (int i = 1; i < ans.size(); ++i){
			cout << " " << ans[i];
		}
		cout << endl;
	}

	if(pushRe < tar.size()){
		s.push(in[pushRe]);
		ans.push_back('i');
		dfs(pushRe+1, popRe);
		s.pop();
		ans.pop_back();
	}

	if(popRe < tar.size() && !s.empty()){
		if(s.top() == tar[popRe]){
			char tmp = s.top();
			s.pop();
			ans.push_back('o');
			dfs(pushRe, popRe+1);
			s.push(tmp);
			ans.pop_back();
		}
	}
	return;
}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen(PROBLEM ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	while(cin >> in >> tar){
		init();
		cout << "[" << endl;
		if(in.size() != tar.size()){
			cout << "]" << endl;
			continue;
		}
		dfs(0, 0);
		cout << "]" << endl;
	}

	return 0;
}