#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define rep(i,a,b) for(i=a;i<b;i++)
ll int large=(ll int)1e13+7;
ll int mod=(ll int)1e9+7;
ll int const N=(ll int)1e6+10;
 
ll int mod_exp(ll int x,ll int n)
{
    ll int result=1;
    while(n>0)
    {
        if(n%2==1)
            result=(result*x)%mod;
        x=(x*x)%mod;
        n=n/2;
    }
    return result;
}
 
ll int mod_inverse(ll int a)
{
    return mod_exp(a,mod-2);
}
 
ll int finde(ll int a,ll int par[])
{
    if(par[a]<0)
        return a;
    ll int res=finde(par[a],par);
    par[a]=res;
    return res;
}
 
void unione(ll int a,ll int b,ll int par[])
{
    if((a=finde(a,par))==(b=finde(b,par)))
    return;
    else
    {
       par[a]+=par[b];
       par[b]=a;
    }
 
}
 
 
 
int main()
{
ios_base::sync_with_stdio(false);
    cin.tie(NULL);
ll int T,i,j,ij;
T=1;
//cin>>T;
while(T--)
{
  ll int n;
  cin>>n;
  ll int par[n+1];
  rep(i,0,n+1)
  par[i]=-1;
  ll int q;
  cin>>q;
  while(q--)
  {
      ll int a,b;
      cin>>a>>b;
      while(a<=b)
      {
      unione(a,b,par);
      a++;
      b--;
      }
  }
  ll int ans=1;
  rep(i,1,n+1)
  {
      if(par[i]<0)
        ans=(ans*10)%mod;
  }
  cout<<ans<<endl;
 
 
}
return 0;
}