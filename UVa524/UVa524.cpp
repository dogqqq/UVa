#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "UVa524"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int arr[20];
bool visit[20], p[1000];

void mkP(){
	p[0] = p[1] = false;
	for (int i = 2; i < 1000; ++i)
		if(p[i])
			for (int j = i*i; j < 1000; j+=i)
				p[j] = false;	
}

bool isValid(int checkNum, int place, int size){
	if(place == (size-1)){
		if(p[arr[place-1]+checkNum] && p[checkNum+1])
			return true;
	}
	else{
		if(p[arr[place-1]+checkNum])
			return true;
	}
	return false;
}

void dfs(int size, int block){
	if(block == size){
		for (int i = 0; i < size - 1; ++i){
			cout << arr[i] << " ";
		}
		cout << arr[size-1] << endl;
		return;
	}
	for (int i = 2; i <= size; ++i){
		if(isValid(i, block, size) && !(visit[i])){
			arr[block] = i;
			// printf("i:%d, block:%d\n", i, block);
			visit[i] = true;
			dfs(size, block+1);
			visit[i] = false;
		}		
	}
}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen(PROBLEM ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int in, cases = 0;
	memset(p, true, sizeof(p));
	mkP();

	while(cin >> in){
		arr[0] = 1;
		memset(visit, false, sizeof(visit));
		if(cases>=1)	cout << endl;
		printf("Case %d:\n", ++cases);
		dfs(in, 1);
	}

	return 0;
}