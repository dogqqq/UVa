#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "UVa127"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

struct card{
	char ch[3];
};

bool isMatch(card c1, card c2){
	return (c1.ch[0] == c2.ch[0] || c1.ch[1] == c2.ch[1]);
}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen(PROBLEM ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	vector<stack<card>> v;
	card in;
	int cnt = 0;

	while(cin >> in.ch && in.ch != "#"){
		cnt++;
		stack<card> s;
		s.push(in);
		v.push_back(s);

		if(cnt == 52){
			while(1){
				int i;
				for (i = 0; i < v.size(); ++i){
					if(i >= 3){
						if(isMatch(v[i].top(), v[i-3].top())){
							v[i-3].push(v[i].top());
							v[i].pop();
							break;
						}
					}
					if(i >= 1){
						if(isMatch(v[i].top(), v[i-1].top())){
							v[i-1].push(v[i].top());
							v[i].pop();
							break;
						}
					}
				}
				if(i >= v.size()){
					// printf("i:%d, v.size:%d\n", i, v.size());
					break;
				}	
				if(v[i].empty())	v.erase(v.begin()+i);
			}

			if(v.size() == 1){
				printf("%d pile remaining: 52\n", v.size());
			}
			else{
				printf("%d piles remaining:", v.size());
				for (int i = 0; i < v.size(); ++i){
					cout << " " << v[i].size();
				}
				cout << endl;
			}
			
			cnt = 0;
			v.clear();
		}
	}
	return 0;
}