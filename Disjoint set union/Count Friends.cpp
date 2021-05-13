#include<bits/stdc++.h>
using namespace std;
void make_set(int parent[],int size[],int n)
{
	for(int i=1;i<=n;i++)
	{
		parent[i]=i;
		size[i]=1;
	}
}
int find_set(int parent[],int v)
{
	if(parent[v]==v)
	return v;
	else
	return parent[v]=find_set(parent,parent[v]);
}
void union_sets(int parent[],int size[],int a,int b)
{
	a=find_set(parent,a);
	b=find_set(parent,b);
	if(a!=b)
	{
		if(size[a]<size[b])
		swap(a,b);
		parent[b]=a;
		size[a]+=size[b];
	}
}
int main(void)
{
	int n,m;
	cin>>n>>m;
	int parent[n+1],size[n+1];
	make_set(parent,size,n);
	while(m--)
	{
		int a,b;
		cin>>a>>b;
		union_sets(parent,size,a,b);
	}
	for(int i=1;i<=n;i++)
	{
		int count=find_set(parent,i);
		cout<<size[count]-1<<" ";
	}
	return 0;
}