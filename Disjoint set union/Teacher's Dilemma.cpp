#include<bits/stdc++.h>
using namespace std;
 
const int MAX_SIZE=100000+7;
int parent[MAX_SIZE];
int findparent(int i)
{
  if(parent[i]!=i)
  {
    parent[i]=findparent(parent[i]);
  }
 
  return parent[i];
}
 
void size_union(int size[],int a,int b)
{
  int root_a=findparent(a);
   int root_b=findparent(b);
   if(root_a!=root_b)
   {
     parent[root_a]=parent[root_b];
     size[root_b]+=size[root_a];
     size[root_a]=0;
   }
}
 
void initialize(int size[],int n)
{
  for(int i=1;i<=n;i++)
  {
    parent[i]=i;
    size[i]=1;
  }
}
 
int main(){
  int n,x,y,m;
  long long int ans=1;
  cin>>n>>m;
  int size[n+1];
  initialize(size,n);
  for(int i=0;i<m;i++)
  {
    cin>>x>>y;
    size_union(size,x,y);
  }
 
  for(int i=1;i<=n;i++)
  {
    if(size[i]>0)
    ans=(ans%1000000007)*size[i];
  }
  cout<<ans%1000000007;
  return 0;
}