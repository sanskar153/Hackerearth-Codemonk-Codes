#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mk make_pair
ll coun=0;
vector<vector<ll>>vec(100002);
ll visited[100002]={0},cc[100002]={0};
ll dfs(ll s)
{
	//coun++;
	visited[s]=1;
	ll i,coun=1;
	for(i=0;i<vec[s].size();i++)
	{
if(!visited[vec[s][i]])
{
	coun+=dfs(vec[s][i]);
	
}
	}
	return cc[s]=coun;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	ll n,q,i;
	cin>>n>>q;
	vector<pair<ll,ll>>edge;
	for(i=1;i<=n-1;i++)
	{
		ll a,b;
		cin>>a>>b;
		edge.pb(mk(a,b));
		vec[a].pb(b);
		vec[b].pb(a);
	}
	dfs(1);
	ll a;
	while(q--)
	{
		ll num,ans=1;
		cin>>num;
		ll u=edge[num-1].first;
		ll v=edge[num-1].second;
		a=min(cc[u],cc[v]);
		ans=a*(n-a);
		
		cout<<ans<<endl;
		
 
	}
}