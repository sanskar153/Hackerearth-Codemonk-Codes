#include<bits/stdc++.h>
using namespace std;

int main()
 {
	 int n,m,g;
	 cin>>n>>m>>g;

	 int t[n];
	 int a[m];

	 for(int i=0;i<n;i++)
	  cin>>t[i];

	   for(int i=0;i<m;i++)
	    cin>>a[i];

		vector<int>v;

		for(int i=0;i<n-1;i++)
		 {
           int x = t[i+1]-t[i];
             v.push_back(x);
		 }
     
	  int ma=INT_MIN;

	  for(int i=0;i<v.size();i++)
	   {
		   if(v[i]>ma)
		    ma=v[i];
	   }
	 
	  int c=0;

     for(int i=0;i<m;i++)
	   {
		  if (a[i]<=ma)
            c+=1 ;
	   }
     cout<<c;

	 return 0;
 }


