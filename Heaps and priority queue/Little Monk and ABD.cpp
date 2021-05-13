#include <bits/stdc++.h>
using namespace std;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n;
	cin >> n;
	vector <long long> v;
 
	for (int i=0; i<n; i++){
		int a;
		cin>>a;
		v.push_back(a);
	} 
	
	sort(v.begin(),v.end());
	int q;
	cin >> q;
	while (q--) {
		int k; char c;
		cin >> k >> c;
		if ( c == 'S' )
			cout << v[k-1] << endl;
		else
			cout << v[n-k] << endl;
	}
	return 0;
}