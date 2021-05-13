#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main() 
{
	ios_base::sync_with_stdio(false);
	
	int t;
	cin>>t;
	
	while(t--)
	{ 
		int n;
		cin>>n;
		int arr[n];
	for(int i=0;i<n;i++)
	{
	    cin>>arr[i];
	}
	int ar[n-1];int k=0;
	for(int i = n-1;i>0;i--)
	{
       if(arr[i]== -1)
	   {
		   ar[i-1]= k+1;
		   k++;
	   }
	   else
	   ar[i-1]=k;
 
	} 
	
	int j=0;
	k=0;vector<int> v;
	if(arr[0]== 1)
	{
		v.push_back(1+ar[0]);
		j++;
	}
	else
	v.push_back(ar[0]);
	for(int i=1;i<n-1;i++)
	{
       if(arr[i]==1)
	   {
		   v.push_back(1+j+ar[i]);
		   j++;
	   }
	   else
	   {
		   v.push_back(j+ar[i]);
		}
	   
	 }
	
	 if(v.size()==0)
	   cout<<"0"<<endl;
	   else
	   {
		   sort(v.begin(),v.end());
	   cout<<v.front()<<endl;}
	
	}
	return 0;
}