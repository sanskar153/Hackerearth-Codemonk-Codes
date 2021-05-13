#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	 std::ios_base::sync_with_stdio(false); 
	ll n;
	cin>>n;
	vector<ll>b(n),s(n);
	
	for(int i=0;i<n;i++)
		cin>>b[i];
	
	for(int i=0;i<n;i++)
		cin>>s[i];
	
	sort(b.begin(),b.end());
	sort(s.begin(),s.end());
	ll c=0;
	
	for(int i=0;i<n;i++)
		c+=fabs(b[i]-s[i]);
	
	cout<<c;
}