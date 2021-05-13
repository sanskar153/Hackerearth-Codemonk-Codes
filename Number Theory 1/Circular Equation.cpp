#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 20, maxs = maxn * 10, mod = 1e9 + 7;
int n, dp[maxn][maxs];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    dp[0][0] = 1;
    for(int i = 1; i < maxn; i++)
        for(int j = 0; j < maxs; j++)
            for(int ld = 0; ld < 10 && j - ld >= 0; ld++)
                (dp[i][j] += dp[i - 1][j - ld]) %= mod;
    int q;
    cin >> q;
    while(q--){
        ll s;
        cin >> s;
        int ans = 0;
        for(ll pat = 1, n = 1; pat <= s; pat = pat * 10 + 1, n++)
            if(s % pat == 0 && n * 9 >= s / pat)
                (ans += dp[n][s / pat]) %= mod;
        cout << ans << '\n';
    }
}