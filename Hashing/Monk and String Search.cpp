#include <bits/stdc++.h>
 
using namespace std;
#define mod 1e6
#define ll long long
const ll nmax = 1e6 + 7;
#define pb push_back
 
 
vector<ll> hsh[nmax];
ll pw[nmax];
 
int main(int argc, char const *argv[])
{
	pw[0] = 1;
	for (int i = 1; i <= 1000000; ++i)
	{
		pw[i] = pw[i - 1]*31;
	}
 
	ll n; cin >> n;
	ll left = 0, right = INT_MAX;
	for (ll i = 1; i <= n; ++i)
	{
		string str; cin >> str;
		hsh[i].pb(0);
		right = min(right, (ll) str.length());
		for (ll j = 0; j < str.length(); ++j)
		{
			hsh[i].pb(hsh[i].back()*31 + (str[j] - 'a' + 1));
		}
	}
 
	ll ans = 0;
	while (left <= right)
	{
		ll mid = (left + right)/2;
		set<ll> s[2];
		ll cur = 0, prev = 1;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = mid; j < hsh[i].size(); ++j)
			{
				int k = j - mid;
				ll h = hsh[i][j] - (pw[mid]*hsh[i][k]);
				if (i == 1)
				{
					s[cur].insert(h);
				}
				else
				{
					if (s[prev].find(h) != s[prev].end())
					{
						s[cur].insert(h);
					}
				}
			}
			s[prev].clear();
			cur = 1 - cur;
			prev = 1 - prev;
		}
		if (s[prev].size())
		{
			left = mid + 1;
			ans = mid;
		}
		else
			right = mid - 1;
	}
	cout << ans;
	return 0;
}