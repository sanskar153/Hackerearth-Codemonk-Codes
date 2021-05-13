#include <bits/stdc++.h>
using namespace std;
 
int find(int x, vector<int> &friends) {
	if(friends[x] == x) return x;
	return friends[x] = find(friends[x], friends);
}
 
int main()
{
	int x, y, q1, q2, q3, a, b;
	cin >> x >> y;
	vector<int> friends(x+y+1);
	for(int i = 1; i <= x+y; i++)
		friends[i] = i;
	cin >> q1;
	for(int i = 0; i < q1; i++) {
		cin >> a >> b;
		int u = find(a, friends);
		int v = find(b, friends);
		if(u != v)
			friends[v] = u;
	}
	cin >> q2;
	for(int i = 0; i < q2; i++) {
		cin >> a >> b;
		a += x, b+= x;
		int u = find(a, friends);
		int v = find(b, friends);
		if(u != v)
			friends[v] = u;
	}
	cin >> q3;
	for(int i = 0; i < q3; i++) {
		cin >> a >> b;
		b += x;
		int u = find(a, friends);
		int v = find(b, friends);
		if(u != v)
			friends[v] = u;
	}
	vector<int> men(x+y+1, 0);
	vector<int> women(x+y+1, 0);
	// unordered_map<int, int> men;
	// unordered_map<int, int> women;
 
	for(int i = 1; i <= x; i++) {
		int u = find(i, friends);
		men[u]++;
	}
	for(int i = 1; i <= y; i++) {
		int u = find(i+x, friends);
		women[u]++;
	}
	long ans = 0;
	for(int i = 1; i <= x; i++) {
		if(men[i])
			ans += 1l * men[i] * (y - women[i]);
	}
	cout << ans << "\n";
	return 0;
}