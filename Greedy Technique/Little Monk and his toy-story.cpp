#include<bits/stdc++.h>
using namespace std;
#define fainou ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long ll;
ll mod=1000000007;

int main()
{
	ll n;
	cin>>n;
	ll a[n],step=0,it=0;
	
	for(ll i=0;i<n;i++) 
	  cin>>a[i];
	
	while(n-it>0)
	{
       it++;
	   n=n-it;
	   step++;
	}
	
	cout<<step;
}