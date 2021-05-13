#include<bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define N 1000000
using namespace std;
typedef long long ll;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin>>q;
    unordered_map<int, int> ump;
    priority_queue<int> max, min;
    int mn,mx,x,ans;
    for(int i=0;i<q;i++){
        string s;
        cin>>s;
        if(s=="Push"){
            cin>>x;
            ump[x]++;
            max.push(x);
            min.push(x*(-1));
        }
        else if(s=="CountHigh"){
            while(!max.empty() && ump[max.top()]==0){
                max.pop();
            }
            if(max.empty()) cout<<-1<<'\n';
            else cout<<ump[max.top()]<<'\n';
        }
        else if(s=="CountLow"){
            while(!min.empty() && ump[(min.top())*(-1)]==0) min.pop();
            if(min.empty()) cout<<-1<<'\n';
            else cout<<ump[(min.top())*(-1)]<<'\n';
        }
        else{
            if(max.empty() || min.empty()){ cout<<-1<<'\n';continue;}
            mx=max.top();
            mn=min.top();
            mn *= (-1);
            while(ump[mn]==0 && !min.empty()){
                min.pop();
                mn=min.top();
                mn *= (-1);
            }
            while(ump[mx]==0 && !max.empty()){
                max.pop();
                mx=max.top();
            }
            if(!max.empty() && !min.empty()){
                ans=mx - mn;
                ump[mx]--;
                if(mx != mn) ump[mn]--;
                max.pop();
                min.pop();
            }
            else ans=-1;
            cout<<ans<<'\n';
        }
        
    }
}