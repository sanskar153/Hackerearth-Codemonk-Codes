#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,x; cin>>n>>x;
    int a[n+1];
    queue<pair<int, int> > q,h;
    for(int i=1;i<=n;i++){
      cin>>a[i];
      q.push(make_pair(a[i] , i));
    } 
    int k=x;
    while(x--)
    {
        int max=-1, index=-1;
        for(int i=0;i<k; i++)
         {
             h.push(q.front());
             if(q.front().first>max)
             {
                 max=q.front().first;
                 index=q.front().second;
             }
             q.pop();
            if(q.empty()) break;
         }
         cout<<index<<" ";
         
         for(int i=0;i<k; i++)
          {
              if(h.front().second!=index)
               {
                   int num=h.front().first;
                   if(num) num--;
                   q.push(make_pair(num,h.front().second));
               }
              h.pop();
              if(h.empty()) break;
          }
         
    }
    
}