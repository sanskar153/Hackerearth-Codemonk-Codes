#include<bits/stdc++.h>
using namespace std;
int root(int u,int r[]){
	while(u != r[u]){
		r[u] = r[r[u]];
		u = r[u];
	}
	return u;
}
void un(int u,int v,int r[],int s[]){
	int ru = root(u,r);
	int rv = root(v,r);
	if(s[ru]<=s[rv]){
		r[ru] = rv;
		s[rv] += s[ru];
	}
	else{
		r[rv] = ru;
		s[ru] += s[rv];
	}
}
int main(){
	int n,m;
	cin>>n>>m;
	int arr[n];
	int r[n];
	int s[n];
	for(int i = 0 ;i<n ; i++){
		cin>>arr[i];
		s[i] = 1;
		r[i] = i;
	}
	vector<vector<int>> v;
	for(int i= 0 ; i<m ; i++){
		int a,b,w;
		cin>>a>>b>>w;
		vector<int> vec{w,a-1,b-1};
		v.push_back(vec);
	}
	int u,ve;
	cin>>u>>ve;
	u--;ve--;
	sort(v.begin(),v.end(),greater<vector<int>>());
	int min = 0;
	for(int i = 0 ;i<m ; i++){
		if(root(v[i][1],r) == root(v[i][2],r)){
			continue;
		}
		else{
			if(v[i][0] < min) break;
			un(v[i][1],v[i][2],r,s);
			if(root(u,r) == root(ve,r)) {
				min = v[i][0];
			}
		}
	}
	long long int sum = 0;
	
	int roote = root(u,r);
	for(int i = 0 ; i<n ; i++){
		if(root(i,r) == roote){
			sum = sum+arr[i];
		}
	}
	cout<<min<<" "<<sum<<endl;
}