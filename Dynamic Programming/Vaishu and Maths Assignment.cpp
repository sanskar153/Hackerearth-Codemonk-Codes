#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
ll par[2000005];

ll col0,col1;
ll find(ll x)
{
	if(x!=par[x])
		par[x]=find(par[x]);
	return par[x];
}
void merge(ll x, ll y)
{
	
	x=find(x);
	y=find(y);
	
	par[y]=x;
	
 
 
}
int dp[105][10005];
 
int l,n,low,high;
int a[105];
int che;
int rec1(int i,int cur)
{
	
	if(cur<low||cur>high)
		return INT_MIN;
	if(i==n)
	{
		
		
	    if(cur>che)
	    	return 1;
	    return INT_MIN;
	}
 
	
	if(dp[i][cur]!=-1)
		return dp[i][cur];
	
	if(rec1(i+1,cur+a[i])!=INT_MIN||rec1(i+1,cur-a[i])!=INT_MIN)
		dp[i][cur]=1;
	else
		dp[i][cur]=INT_MIN;
	return dp[i][cur];
}
int rec2(int i,int cur)
{
	if(cur<low||cur>high)
		return INT_MIN;
	if(i==n)
	{
		
	    if(cur<che)
	    	return 1;
	    return INT_MIN;
	}
 
	
	if(dp[i][cur]!=-1)
		return dp[i][cur];
	
	if(rec2(i+1,cur+a[i])!=INT_MIN||rec2(i+1,cur-a[i])!=INT_MIN)
		dp[i][cur]=1;
	else
		dp[i][cur]=INT_MIN;
	return dp[i][cur];
}
 
 
 
 
 
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>l>>n>>low>>high;
	
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int q;
	cin>>q;
	
	while(q--)
	{
		memset(dp,-1,sizeof(dp));
		char ch;
		cin>>ch;
		cin>>che;
		
		if(ch=='>')
		{
 
			if(rec1(0,l)!=INT_MIN)
				cout<<"YES";
			else
				cout<<"NO";
		}
		else
			{
			if(rec2(0,l)!=INT_MIN)
				cout<<"YES";
			else
				cout<<"NO";
		}
		cout<<endl;
	}
	
	return 0;
}