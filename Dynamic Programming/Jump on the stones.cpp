#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
const ll mod = 1e9 + 7;
ll dp[N], n, k;
int main()
{
	cin >> n >> k;
	dp[n] = dp[n - 1] = 1;
	for (ll i = n - 2; i > 0; i--)
	{
		for (ll j = k; j > 0; j--)
		{
			if (i + j <= n) dp[i] = (dp[i] + dp[i + j]) % mod;
		}
	}
	cout << dp[1] << "\n";
	return 0;
}