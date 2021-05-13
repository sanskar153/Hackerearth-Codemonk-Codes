#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		ll n,k;
	   cin>>n>>k;
	   map<ll,ll> hash;
	    ll ans=0;
		while(n--)
		{
			ll x;
			cin>>x;
			if(hash[x+1]==0)
			   {
				ans++;
				hash[x]++;
			   }
			else
			 {
				hash[x+1]=0;
	
			 }
		}
		  if(ans<=k)
		   {
			cout<<k-ans<<"\n";
		   }
		   else
		    {
			  cout<<"-1"<<"\n";
		    }
	
 
	 }
	
}