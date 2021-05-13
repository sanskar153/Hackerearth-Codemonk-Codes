#include <bits/stdc++.h>
 
using namespace std;
 
class segment {
public:
    char *lazy;
    int *tree;
 
 
    segment(int n) {
        tree = new int[4 * n + 5];
        lazy = new char[4 * n + 5];
        for (int i = 0; i < 4 * n + 5; i++) tree[i] = lazy[i] = 0;
    }
 
 
    void update(int node, int start, int end, int l, int r, char const &what) {
        if (lazy[node]) {
            int size = end - start + 1;
            if (lazy[node] == 1)tree[node] = size;
            else if (lazy[node] == 2) tree[node] = 0;
            else if (lazy[node] == 3)
                tree[node] = size - tree[node];
            if (size != 1) {
                int left = node << 1;
                int right = left | 1;
                if (lazy[left] == 0) lazy[left] = lazy[node];
                else {
                    if (lazy[node] == 1) lazy[left] = 1;
                    else if (lazy[node] == 2) lazy[left] = 2;
                    else if (lazy[node] == 3) {
                        if (lazy[left] == 1) lazy[left] = 2;
                        else if (lazy[left] == 2) lazy[left] = 1;
                        else lazy[left] = 0;
                    } else {
                        lazy[left] = lazy[node];
                    }
                }
 
                if (lazy[right] == 0) lazy[right] = lazy[node];
                else {
                    if (lazy[node] == 1) lazy[right] = 1;
                    else if (lazy[node] == 2) lazy[right] = 2;
                    else if (lazy[node] == 3) {
                        if (lazy[right] == 1) lazy[right] = 2;
                        else if (lazy[right] == 2) lazy[right] = 1;
                        else lazy[right] = 0;
                    } else {
                        lazy[right] = lazy[node];
                    }
                }
            }
            lazy[node] = 0;
        }
        if (l > end || start > r) return;
        if (l <= start && end <= r) {
            if (lazy[node] == 0) lazy[node] = what;
            else {
                if (what == 1) lazy[node] = 1;
                else if (what == 2) lazy[node] = 2;
                else if (what == 3) {
                    if (lazy[node] == 1) lazy[node] = 2;
                    else if (lazy[node] == 2) lazy[node] = 1;
                    else lazy[node] = 0;
                } else {
                    lazy[node] = what;
                }
            }
            if (lazy[node]) {
                int size = end - start + 1;
                if (lazy[node] == 1)tree[node] = size;
                else if (lazy[node] == 2) tree[node] = 0;
                else if (lazy[node] == 3)
                    tree[node] = size - tree[node];
                if (size != 1) {
                    int left = node << 1;
                    int right = left | 1;
                    if (lazy[left] == 0) lazy[left] = lazy[node];
                    else {
                        if (lazy[node] == 1) lazy[left] = 1;
                        else if (lazy[node] == 2) lazy[left] = 2;
                        else if (lazy[node] == 3) {
                            if (lazy[left] == 1) lazy[left] = 2;
                            else if (lazy[left] == 2) lazy[left] = 1;
                            else lazy[left] = 0;
                        } else {
                            lazy[left] = lazy[node];
                        }
                    }
 
                    if (lazy[right] == 0) lazy[right] = lazy[node];
                    else {
                        if (lazy[node] == 1) lazy[right] = 1;
                        else if (lazy[node] == 2) lazy[right] = 2;
                        else if (lazy[node] == 3) {
                            if (lazy[right] == 1) lazy[right] = 2;
                            else if (lazy[right] == 2) lazy[right] = 1;
                            else lazy[right] = 0;
                        } else {
                            lazy[right] = lazy[node];
                        }
                    }
                }
                lazy[node] = 0;
            }
            return;
        }
        int mid = (start + end) >> 1;
        update(node << 1, start, mid, l, r, what);
        update(node << 1 | 1, mid + 1, end, l, r, what);
        tree[node] = tree[node << 1] + tree[node << 1 | 1];
    }
 
    int query(int node, int start, int end, int l, int r) {
        if (lazy[node]) {
            if (lazy[node]) {
                int size = end - start + 1;
                if (lazy[node] == 1)tree[node] = size;
                else if (lazy[node] == 2) tree[node] = 0;
                else if (lazy[node] == 3)
                    tree[node] = size - tree[node];
                if (size != 1) {
                    int left = node << 1;
                    int right = left | 1;
                    if (lazy[left] == 0) lazy[left] = lazy[node];
                    else {
                        if (lazy[node] == 1) lazy[left] = 1;
                        else if (lazy[node] == 2) lazy[left] = 2;
                        else if (lazy[node] == 3) {
                            if (lazy[left] == 1) lazy[left] = 2;
                            else if (lazy[left] == 2) lazy[left] = 1;
                            else lazy[left] = 0;
                        } else {
                            lazy[left] = lazy[node];
                        }
                    }
 
                    if (lazy[right] == 0) lazy[right] = lazy[node];
                    else {
                        if (lazy[node] == 1) lazy[right] = 1;
                        else if (lazy[node] == 2) lazy[right] = 2;
                        else if (lazy[node] == 3) {
                            if (lazy[right] == 1) lazy[right] = 2;
                            else if (lazy[right] == 2) lazy[right] = 1;
                            else lazy[right] = 0;
                        } else {
                            lazy[right] = lazy[node];
                        }
                    }
                }
                lazy[node] = 0;
            }
        }
        if (l > end || start > r) return 0;
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = (start + end) >> 1;
        if (r <= mid) return query(node << 1, start, mid, l, r);
        else if (l > mid) return query(node << 1 | 1, mid + 1, end, l, r);
        return query(node << 1, start, mid, l, r) + query(node << 1 | 1, mid + 1, end, l, r);
    }
};
 
class Demosegment {
public:
    void solve(std::istream &in, std::ostream &out) {
        int n, q;
        in >> n >> q;
        segment *sg[18];
        for (int i = 0; i < 18; i++) sg[i] = new segment(n + 1);
        while (q-- > 0) {
            int type;
            in >> type;
            if (type == 1) {
                int l, r, x;
                in >> l >> r >> x;
                for (int i = 0; i < 18; i++)if ((1 << i) & x)sg[i]->update(1, 1, n, l, r, 1);
            } else if (type == 2) {
                int l, r, x;
                in >> l >> r >> x;
                for (int i = 0; i < 18; i++)
                    if (((1 << i) & x) == 0)sg[i]->update(1, 1, n, l, r, 2);
            } else if (type == 3) {
                int l, r, x;
                in >> l >> r >> x;
                for (int i = 0; i < 18; i++)
                    if ((1 << i) & x)sg[i]->update(1, 1, n, l, r, 3);
            } else if (type == 4) {
                int l, r;
                in >> l >> r;
                long long ans = 0;
                for (int i = 0; i < 18; i++) ans += ((1ll << i) * sg[i]->query(1, 1, n, l, r));
                out << ans << "\n";
            } else {
                int l, r;
                in >> l >> r;
                long long ans = 0;
                for (int i = 0; i < 18; i++) if (sg[i]->query(1, 1, n, l, r) & 1) ans += (1ll << i);
                out << ans << "\n";
            }
        }
 
    }
};
 
int main() {
    Demosegment solver;
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::istream &in(std::cin);
    std::ostream &out(std::cout);
    solver.solve(in, out);
    return 0;
}