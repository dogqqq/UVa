#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "UVa101"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

vector<int> v[30];
int n;

void find(int x, int &px, int &hx){
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < v[i].size(); ++j){
			if(v[i][j] == x){
				px = i;
				hx = j;
				return;
			}
		}
	}
}

void restore(int px, int hx){
	int tmp;
	for(int i = hx+1; i < v[px].size(); ++i) {
		tmp = v[px][i];
		v[tmp].push_back(tmp);
	}

	tmp = v[px].size() - hx - 1;
	while(tmp--)
		v[px].pop_back();
}

void move(int pa, int ha, int pb){
	int tmp;
	for (int i = ha; i < v[pa].size(); ++i)
		v[pb].push_back(v[pa][i]);
	
	tmp = v[pa].size() - ha;
	while(tmp--)
		v[pa].pop_back();
}

int main(int argc, char const *argv[]){
	#ifdef DBG
	freopen(PROBLEM ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int a, b;
	int pa, ha, pb, hb;
	string s1, s2;

	while(cin >> n){
		for (int i = 0; i < 30; ++i)
			v[i].clear();
		
		for (int i = 0; i < n; ++i)
			v[i].push_back(i);

		while(cin >> s1 && s1 != "quit"){
			cin >> a >> s2 >> b;
			find(a, pa, ha);
			find(b, pb, hb);
			if(pa == pb)	continue;
			if(s1 == "move")	restore(pa, ha);
			if(s2 == "onto")	restore(pb, hb);
			move(pa, ha, pb);
		}
		for (int i = 0; i < n; ++i){
			printf("%d:", i);
			for (int j = 0; j < v[i].size(); ++j){
				printf(" %d", v[i][j]);
			}
			puts("");
		}		
	}
	return 0;
}