#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
ll par[2000005];
//ll size1[2000005];
ll col0,col1;
ll find(ll x)
{
	if(x!=par[x])
		par[x]=find(par[x]);
	return par[x];
}
void merge(ll x, ll y)
{
	/*if(x>y)
		swap(x,y);*/
	x=find(x);
	y=find(y);
	/*if(size1[x]<size1[y])
		swap(x,y);*/
	par[y]=x;
	/*size1[x]=size1[y]+size1[x];*/
 
 
}
int dp[105][105][105];
ll a[105],b[105];
int n;
int rec(int i,int x,int y)
{
	if(i>=n||(x<=0&&y<=0))
		return 0;
	if(dp[i][x][y]!=-1)
		return dp[i][x][y];
	//cout<<i<<" "<<x<<" "<<y<<endl;
	
	dp[i][x][y]=INT_MIN;
	if(x>=a[i]&&y>=b[i])
		dp[i][x][y]=max(1+rec(i+1,x-a[i],y-b[i]),rec(i+1,x,y));
	else
		dp[i][x][y]=rec(i+1,x,y);
	return dp[i][x][y];
 
}
 
 
 
 
 
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		int cntr=0,cntb=0;
		for(int j=0;j<s.length();j++)
		{
			if(s[j]=='R')
				cntr++;
			else
				cntb++;
		}
		a[i]=cntr;
		b[i]=cntb;
 
	}
	int q;
	cin>>q;
	
	memset(dp,-1,sizeof(dp));
	while(q--)
 
	{
		int x,y;
		cin>>x>>y;
		cout<<rec(0,x,y)<<endl;
 
	}
	
	
	return 0;
}