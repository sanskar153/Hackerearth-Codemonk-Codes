#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
 
const int MAX = 1e5+5;
vector<int>graph[MAX];
int ar[MAX];
int f[10000000];
int n,k;
int ans;
void dfs(int s,int p,int cur)
{
    cur^=ar[s];
    ans+=f[cur^k];
    f[cur]++;
    for(auto x:graph[s])
    {
        if(x!=p)
        dfs(x,s,cur);
    }
    f[cur]--;
}
    
int32_t main()
{
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    cin>>ar[i];
    int x;
    for(int i=1;i<n;i++)
    {
        cin>>x;
        graph[x].push_back(i+1);
        graph[i+1].push_back(x);
    }
    
    ans=0;
    f[0]=1;
    dfs(1,0,0);
    cout<<ans<<endl;
    return 0;
}