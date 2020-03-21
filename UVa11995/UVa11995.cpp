#include <bits/stdc++.h>

using namespace std;

#define PROBLEM "UVa11995"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

stack<int> s;
queue<int> q;
priority_queue<int> pq;
bool b[5];
//b[0]-> s, b[1]-> q, b[2]-> pq

void init(){
	while(!s.empty())	s.pop();
	while(!q.empty())	q.pop();
	while(!pq.empty())	pq.pop();
	memset(b, true, sizeof(b));
}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen(PROBLEM ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int n, action, num;

	while(cin >> n){
		init();
		for (int i = 0; i < n; ++i){
			cin >> action >> num;
			if(action == 1){
				s.push(num);
				q.push(num);
				pq.push(num);
			}
			else{
				if(b[0]){
					if(!s.empty() && s.top() == num)
						s.pop();
					else
						b[0] = false;
				}

				if(b[1]){
					if(!q.empty() && q.front() == num)
						q.pop();
					else
						b[1] = false;
				}

				if (b[2]){
					if(!pq.empty() && pq.top() == num)
						pq.pop();
					else
						b[2] = false;
				} 
			}
		}
		if((b[0] && b[1]) || (b[0] && b[2]) || (b[1] && b[2]))
			cout << "not sure" << endl;
		else if(b[0])
			cout << "stack" << endl;
		else if(b[1])
			cout << "queue" << endl;
		else if(b[2])
			cout << "priority queue" << endl;
		else
			cout << "impossible" << endl;
	}
	return 0;
}