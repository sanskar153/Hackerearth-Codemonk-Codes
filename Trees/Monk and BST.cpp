#include<bits/stdc++.h>
#define dd double
using namespace std;
#define ll long long
int main()
{
	int levels;
	ll s;
	ll k;
	cin>>levels>>s;
	assert(levels>=1 && levels<=30);
	assert(s>=1 && s<=1000000000000000000);
	int q;
	cin>>q;
	ll pro=1;
	ll pow[100];pow[0]=1;
	for(int i=1;i<=levels-1;i++)
	{
		pro*=2;
		pow[i]=pro;
	}
	ll x;
	if(levels>1)x=(s-((pro-1)*(pro-1)))/(pro*2-1)+1;
	else x=s+1;
	ll val,root=((levels<2)?0:pow[levels-2]-1);
	bool type;
	while(q--)
	{
		cin>>type;
		if(type==0)
		{
			cin>>val;
			ll cnt=levels-3;
			val-=x;
			if(levels>1 && val==pow[levels-1]-1)
			{
				for(int i=1;i<=levels-1;i++)cout<<"r";
				cout<<"\n";
			}
			else
			{
				ll temp=root;
				if(val==temp)cout<<"root\n";
				else
				{
					while(temp!=val)
					{
						if(temp>val)
						{
							cout<<"l";temp=temp-pow[cnt--];
						}
						else
						{
							cout<<"r";temp=temp+pow[cnt--];
						}
					}
					cout<<"\n";
				}
			}
		}
		else
		{
			cin>>k;
			int l=log2(k)+1;
			ll a;
			if(l==levels)a=x;
			else a=x+pow[levels-l-1]-1;
			ll n=k-pow[l-1]+1;
			ll d=pow[levels-l];
			cout<<a+(n-1)*d<<"\n";
		}
	}
	return 0;
}