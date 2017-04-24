#include <bits/stdc++.h>
using namespace std;

int n, x[11], y[11], dist[11][11], memo[11][1 << 11], dp[11][1 << 11];

int tsp(int u, int bitmask) {			//startin node and bitmask of taken nodes
	if(bitmask == ((1 << (1+n)) - 1))	//when it steps in this node, if all nodes are visited
		return dist[u][0];				//then return to 0'th (starting) node [as the path is hamiltonian]
	if(dp[u][bitmask] != -1)			//if we have previous value set up
		return dp[u][bitmask];			//use that previous value
	
	int ans = 1e9;						//set an infinite value
	
	for(int v = 0; v <= n; v++)					//for all the nodes
		if(u != v && !(bitmask & (1 << v)))		//if this node is not the same node, and if this node is not used yet(in bitmask)
			ans = min(ans, dist[u][v] + tsp(v, bitmask | (1 << v)));	//min(past_val, dist u->v + dist(v->all other untaken nodes))
	return dp[u][bitmask] = ans;				//save in dp and return
}

int main()
{
	freopen("in", "r", stdin);
	
	int t;
	scanf("%d", &t);
	while(t--) {
		int _x, _y;
		scanf("%d %d", &_x, &_y);
		scanf("%d %d", &x[0], &y[0]);
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			scanf("%d %d", &x[i], &y[i]);
		for(int i = 0; i <= n; i++)
			for(int j = 0; j <= n; j++)
				dist[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]);
		
		memset(dp, -1, sizeof(dp));
		memset(memo, -1, sizeof memo);
		
		int ans = tsp(0, 1);
		
		printf("The shortest path has length %d\n", ans);
	}
	return 0;
}
