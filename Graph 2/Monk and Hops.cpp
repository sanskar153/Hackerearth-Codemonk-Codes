#include <bits/stdc++.h>
typedef unsigned long long int ll;
using namespace std;
vector <vector <pair <ll,ll>>> adj;
vector <ll> dis;
vector <bool> visited;
struct Node{
    ll u;
    ll d;
    ll hop;
    ll w;
};
struct compare{
    bool operator()(const Node &a,const Node &b){
        if(a.d==b.d){
            return a.hop>b.hop;
        }
        return a.d>b.d;
    }
};
int main(){
    int t;
    t =1;
    while(t--){
        ll n;
        cin>>n;
        ll m;
        cin>>m;
        adj.assign(n+1,vector <pair<ll,ll>> ());
        dis.assign(n+1,1000000000000);
        visited.assign(n+1,false);
        for(ll i=0;i<m;i++){
            ll u,v,w;
            cin>>u>>v>>w;
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        priority_queue <Node,vector <Node>,compare> q;
        dis[1]=0;
        q.push({1,0,0,0});
        ll ans = INT_MAX;
        while(!q.empty()){
            ll u = q.top().u;
            ll hop = q.top().hop;
            ll d = q.top().d;
            ll w = q.top().w;
            q.pop();
            visited[u]=true;
            for(auto i:adj[u]){
                ll v = i.first;
                ll w1 = i.second;
                if(!visited[v] && dis[u]+w1<dis[v]){
                    dis[v]=dis[u]+w1;
                    if(u!=1 && (w%2==0 && w1%2!=0 )|| (w%2!=0 && w1%2==0)){
                            
                        q.push({v,dis[v],hop+1,w1});
                    }
                    else
                        q.push({v,dis[v],hop,w1});
                }
            }
            
        }
        q.push({1,0,0,0});
        while(!q.empty()){
            ll u = q.top().u;
            ll hop = q.top().hop;
            ll d = q.top().d;
            ll w = q.top().w;
            q.pop();
            if(dis[n]==d && u==n){
                ans = min(ans,hop);
            }
            for(auto i:adj[u]){
                ll v = i.first;
                ll w1 = i.second;
                if(dis[u]+w1<=dis[v]){
                    dis[v]=dis[u]+w1;
                    if(u!=1 && (w%2==0 && w1%2!=0 )|| (w%2!=0 && w1%2==0)){
                        //cout<<v<<" "<<hop+1<<endl;
                        q.push({v,dis[v],hop+1,w1});
                    }
                    else{
                        //cout<<v<<" "<<hop<<endl;
                        q.push({v,dis[v],hop,w1});
                    }
                }
            }
            
        }
        cout<<dis[n]<<" "<<ans;
    }
    return 0;
}