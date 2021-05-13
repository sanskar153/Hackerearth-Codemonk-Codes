#include <bits/stdc++.h>
using namespace std;
 
int main()
{
 
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,m;
    cin>>m>>n;
    int arr[m]={0},brr[m]={0};
    
    while(n--)
    {
        int a,b;
        cin>>a>>b;
 
        arr[a-1]++;
        brr[b-1]++;        
    }
 
    int c1=0,c2=0;
 
    for(int i=0;i<m;i++)
    {
        if(arr[i]==0)
           c1+=1;
    }    
 
    for(int i=0;i<m;i++)
    {
        if(brr[i]==0)
           c2+=1;;
    }    
 
    cout<<max(c1,c2);
 
 
    return 0;
}
 