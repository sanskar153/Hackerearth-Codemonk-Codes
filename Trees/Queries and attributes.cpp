#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <random>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <functional>
#include <sstream>
 
using namespace std;
 
const long long INF = 1LL << 62;
 
class SegmentTree {
    public:
        SegmentTree(int _n) : n(_n), N(n << 1), h(0), data(N, INF), lazy(N, INF) {
            while (1 << h < N) {
                ++h;
            }
        }
 
        void apply(int x, long long v) {
            data[x] = min(data[x], v);
            if (x < n) {
                lazy[x] = min(lazy[x], v);
            }
        }
 
        void pull(int x) {
            for (int p = x >> 1; p > 0; p >>= 1) {
                if (lazy[p] == INF) {
                    data[p] = min(data[p << 1], data[p << 1 | 1]);
                }
            }
        }
 
        void push(int x) {
            for (int i = h; i >= 0; --i) {
                int p = x >> i;
                if (lazy[p] != INF) {
                    apply(p << 1, lazy[p]);
                    apply(p << 1 | 1, lazy[p]);
                    lazy[p] = INF;
                }
            }
        }
 
        void update(int l, int r, long long v) {
            l += n;
            r += n;
            int ll = l, rr = r;
            push(ll);
            push(rr);
            while (l <= r) {
                if (l & 0x1) {
                    apply(l++, v);
                }
                if ((r & 0x1) == 0) {
                    apply(r--, v);
                }
                l >>= 1;
                r >>= 1;
            }
 
            pull(ll);
            pull(rr);
        }
 
        long long query(int l, int r) {
            long long res = INF;
            l += n;
            r += n;
            push(l);
            push(r);
 
            while (l <= r) {
                if (l & 0x1) {
                    res = min(data[l++], res);
                }
                if ((r & 0x1) == 0) {
                    res = min(data[r--], res);
                }
                l >>= 1;
                r >>= 1;
            }
 
            return res;
        }
 
    private:
        int n, N;
        int h;
        vector<long long> data;
        vector<long long> lazy;
};
 
class Solution {
public:
    void init(vector<long long>& A, vector<pair<int,int>>& E) {
        int n = A.size();
        SegmentTree st(n + 10);
        MN.clear();
        MN.resize(n, INF);
        st.update(n - 1, n - 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            MN[i] = st.query(i, i);
            if (i > 0 && MN[i] < INF) {
                st.update(E[i].first, E[i].second, MN[i] + A[i]);
            }
        }
 
        for (int i = 1; i < n; ++i) {
            MN[i] = min(MN[i], MN[i - 1]);
        }
    }
 
    long long query(int x) {
        return MN[x];
    }
 
private:
    vector<long long> MN;
}; 
 
int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    Solution sol;
    int n;
    cin >> n;
    vector<long long> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    vector<pair<int,int>> E(n);
    for (int i = 0; i < n; ++i) {
        cin >> E[i].first >> E[i].second;
        --E[i].first;
        --E[i].second;
    }
 
    sol.init(A, E);
 
    int q;
    cin >> q;
    while (q-- > 0) {
        long long x, y;
        cin >> x >> y;
        --x;
        
        cout << sol.query(x) + y << "\n";
    }
 
    return 0;
}