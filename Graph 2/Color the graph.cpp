#include<bits/stdc++.h>
using namespace std;
 
int p[100010];
 
void initialise()
{
	for(int i=0;i<100010;i++)
	{
		p[i]=0;
	}
}
int c=0, r=0, b=0;
void dfs(vector<int>v[100010], int i)
{
	if(p[i]==0)
		{
			p[i]=1;
			r++;
		}
	for(int j=0;j<v[i].size();j++)
	{
		if(p[v[i][j]]==p[i])
		{
			c=-1;
			//cout<<v[i][j];
			return ;
		}
		if(p[v[i][j]]==0)
		{
			p[v[i][j]]=-1*p[i];
			if(p[v[i][j]]==1)
				r++;
			else
				b++;
			dfs(v, v[i][j]);
		
		}
		else if(p[v[i][j]]==-1*p[i])
			continue;
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		vector<int>v[100010];
		int n, m, i, x, y;
		cin>>n>>m;
		initialise();
		for(i=0;i<m;i++)
		{
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		c=0;
		int s=0;
		for(i=1;i<=n;i++)
		{
			r=0;
			b=0;
			if(p[i]==0)
				{
					dfs(v, i);
					s = s + max(r, b);
				}
			if(c==-1)
				break;
		}
		if(c==-1)
			cout<<"NO"<<"\n";
		else
		{	
			cout<<s<<"\n";
		}
 
	}
	return 0;
}