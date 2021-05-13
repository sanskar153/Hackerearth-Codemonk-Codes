#include <bits/stdc++.h>
using namespace std;
#include <unordered_map>
#define inputarr(a,n) for(ll i=0;i<n;i++) cin>>a[i];
#define prllarr(a,n) for(ll i=0;i<n;i++) cout<<a[i]<<" ";
#define pb push_back
#define ll long long
#define mod 1000000007
#define foi ios_base::sync_with_stdio(false);
ll n;
ll arr[10002];
ll dp[10002][3][1<<5];
ll solve(ll l,ll choosen,ll mask)
{
	if(choosen==0)
	{
		if(mask!=0)
		{
			return 1;
		}
		return 0;
	}
	if(l==n)
	{
		return 0;
	}
	if(dp[l][choosen][mask]!=-1)
	{
		return dp[l][choosen][mask];
	}
	ll ans=0;
	ans=solve(l+1,choosen,mask)+solve(l+1,choosen-1,mask&arr[l]);
	return dp[l][choosen][mask]=ans;
}
int main() 
{
	foi;
	ll t;
	cin>>t;
	unordered_map<char,ll>mapa;
	mapa['a']=0;
	mapa['e']=1;
	mapa['i']=2;
	mapa['o']=3;
	mapa['u']=4;
	while(t--)
	{
		cin>>n;
 
		for(ll i=0;i<n;i++)
		{
			string s;
			cin>>s;
			ll x=0;
			for(ll j=0;j<s.size();j++)
			{
				if(mapa.count(s[j]))
				{
					x|=(1<<mapa[s[j]]);
				}
			}
			arr[i]=x;
		}
		for(ll i=0;i<10001;i++)
		{
			for(ll j=0;j<=3;j++)
			{
				for(ll k=0;k<(1<<5);k++)
				{
					dp[i][j][k]=-1;
				}
			}
		}
		cout<<solve(0,3,(1<<5)-1)<<endl;
 
		
	}
}
 