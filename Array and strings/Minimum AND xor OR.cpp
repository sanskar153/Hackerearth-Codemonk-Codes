#include<bits/stdc++.h>
using namespace std;

int main()
{
   ios_base::sync_with_stdio(0);
    cin.tie(0);
     
	 int t;
	 cin>>t;

      while(t--)
      {
        int n,f=0;
		cin>>n;

        long long a[n],m;
        for(int i=0;i<n;i++)
          cin>>a[i];

         sort(a,a+n);

		for(int i=0;i<n-1;i++)
        {
           for(int j=i+1;j<n;j++)
           {
              if(f==0)
               {
                 m=(a[i]^a[j]);
				  f=1;
			   }
             
			 if((a[i]^a[j])<m)
                m=(a[i]^a[j]);
		
			else
               break;
            }
    	}
  
    cout<<m<<"\n";
	
	}
}