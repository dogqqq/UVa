#include <queue>
#include <istream>

using namespace std;

#define PROBLEM "UVa10935"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen(PROBLEM ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int num;
	queue<int> q;
	while(cin >> num){
		if(num == 0)	break;
		while(!q.empty())	q.pop();

		for (int i = 1; i <= num; ++i)
			q.push(i);
		
		printf("Discarded cards:");
		while(q.size() >= 3){
			printf(" %d,", q.front());
			q.pop();
			q.push(q.front());
			q.pop();
		}
		if(q.size() > 1){
			printf(" %d", q.front());
			q.pop();	
		}
		printf("\nRemaining card: %d\n", q.front());
	}
	return 0;
}