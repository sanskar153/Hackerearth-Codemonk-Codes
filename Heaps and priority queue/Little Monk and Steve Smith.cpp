#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	assert(n>0 and n<=1e6);
	assert(k>0 and k<=1e6);
	long long int sum = 0;
	priority_queue< pair < int , int > > queue;
	for(int i=0;i<n;i++){
		int x,y;
		scanf("%d",&x);
		assert(x>0 and x<=1e9);
		sum+=x;
		y=i+1;
		queue.push(make_pair(x,-y));
	}
	assert(k<=sum);
	while(k--){
		pair < int , int > temp;
		temp = queue.top();
		queue.pop();
		temp.first--;
		printf("%d ",-temp.second);
		queue.push(temp);
	}
	printf("\n");
	return 0;
}