#include<bits/stdc++.h>
using namespace std;
int main()
{
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,i,j,k,c;
    long long ans,max;
    string s;
    cin>>t;
    while(t--)
    {
        ans=0;max=-1;
        cin>>s;
        cin>>n;
        vector<int>a(n);
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        j=1<<n;
        for(i=0;i<j;i++)
        {
            c=0;ans=0;
            for(k=0;k<n;k++)
            {
                if(i&(1<<k))
                {
                    if(c==0)
                    {
                    ans=a[k];
                    c++;
                    }
                    else if(c==1)
                    {
                        ans|=(a[k]);
                        c++;
                    }
                    else if(c==2)
                    {
                        ans^=(a[k]);
                        c++;
                    }
                    else if(c==3)
                    {
                        ans+=a[k];
                        c=1;
                    }
                }
            }
            if(ans>max)
            max=ans;
        }
        if(max&1)
        {
            if(s[0]=='O')
            {
                cout<<"Monk"<<"\n";
            }
            else
            cout<<"Mariam"<<"\n";
 
        }
        else
        {
            if(s[0]=='E')
            {
                cout<<"Monk"<<"\n";
            }
            else
            cout<<"Mariam"<<"\n";
        }
    }
}