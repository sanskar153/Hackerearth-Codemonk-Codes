#include<bits/stdc++.h>
using namespace std;
 
vector<int> tree[100005];
int arr[100005];
int sol[100005][32];
bool visited[100005];
 
 
 
void dfs(int u)
{
visited[u] = true;
for(int i=0;i<tree[u].size();i++) //accessing its adjacent vertex connected to it
{
int v= tree[u][i];
if(!visited[v])
{
dfs(v);
for(int j=0;j<32;j++)
{
sol[u][j] = max(sol[v][j],sol[u][j]);
}
}
}
 
for(int k=0;k<32;k++)
{
if( sol[u][k] &1)
{
arr[u] ^= (1<<k); // flip the k'th bit
 
}
if(arr[u] & (1<<k) )
{
sol[u][k]++;
arr[u] ^= (1<<k);
}
}
}
 
 
 
int main()
{
int n,a;
scanf("%d%d",&n,&a);
for(int i=0;i<n-1;i++)
{
int u,v;
scanf("%d%d",&u,&v);
tree[u].push_back(v);
tree[v].push_back(u);
}
memset(visited,false,sizeof(visited));
for(int i =1;i<=n;i++ ) scanf("%d",&arr[i]);
dfs(a);
int sum =0;
for(int i=0;i<32;i++)
{
sum+= sol[a][i];
}
cout<<sum<<endl;
 
return 0; // bye bye
}