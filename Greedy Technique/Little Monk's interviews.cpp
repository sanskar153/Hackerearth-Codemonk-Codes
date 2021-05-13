#include<bits/stdc++.h>
using namespace std;
 
#define pipi pair<int, pair<int, int>>
#define F first
#define S second
 
bool comp(pipi p1, pipi p2) 
{
	return p1.F > p2.F;
}
 
int find_set(int parent[], int v) 
{
	if(parent[v] == v) 
	{
		return v;
	}
	return parent[v] = find_set(parent, parent[v]);
}
 
int main() 
{
	int tc;
	scanf("%d", &tc);
	
	while(tc--) 
	{
		int n, m;
		scanf("%d %d", &n, &m);
		int parent[n+1];
		
		for(int i=0; i<=n; i++) 
		{
			parent[i] = i;
		}
		pipi edge[m];
		
		for(int i=0; i<m; i++) 
		{
			scanf("%d %d %d", &edge[i].S.F, &edge[i].S.S, &edge[i].F);
		}
		
		sort(edge, edge+m, comp);
		int ans = 0;
		
		for(int i=0; i<m; i++) 
		{
			int u = find_set(parent, edge[i].S.F);
			int v = find_set(parent, edge[i].S.S);
			if(u != v) {
				ans += edge[i].F;
				parent[v] = u;
			}
		}
		
		printf("%d\n", ans);
	}
	return 0;
}