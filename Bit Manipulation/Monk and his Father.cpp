#include<bits/stdc++.h>
using namespace std;
int main()
{
        int t;
        cin>>t;
        while(t--)
        {
                long long  n;
                cin>>n;
                int count=0;
                while(n)
                {
                        count+=(n&1);
                        n>>=1;
 
                }
                cout<<count<<endl;
        }
}