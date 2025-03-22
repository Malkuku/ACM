#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+3;
const int mod = 10007;

struct Node {
    ll sum1, sum2, sum3;
    ll add, muti, change;
} tr[N<<2];

void push_up(int p) {
    tr[p].sum1 = (tr[p<<1].sum1 + tr[p<<1|1].sum1) % mod;
    tr[p].sum2 = (tr[p<<1].sum2 + tr[p<<1|1].sum2) % mod;
    tr[p].sum3 = (tr[p<<1].sum3 + tr[p<<1|1].sum3) % mod;
}

void build(int p, int pl, int pr) {
    tr[p].add = tr[p].change = 0;
    tr[p].muti = 1;
    if (pl == pr) {
        tr[p].sum1 = tr[p].sum2 = tr[p].sum3 = 0;
        return;
    }
    int mid = (pl + pr) >> 1;
    build(p<<1, pl, mid);
    build(p<<1|1, mid+1, pr);
    push_up(p);
}

void push_down(int p, int pl, int pr) {
    int mid = (pl + pr) >> 1;
    int lenl = mid - pl + 1;
    int lenr = pr - mid;

    if (tr[p].change) {
        tr[p<<1].add = tr[p<<1|1].add = 0;
        tr[p<<1].muti = tr[p<<1|1].muti = 1;
        tr[p<<1].change = tr[p<<1|1].change = tr[p].change;

        tr[p<<1].sum1 = lenl * tr[p].change % mod;
        tr[p<<1].sum2 = lenl * tr[p].change % mod * tr[p].change % mod;
        tr[p<<1].sum3 = lenl * tr[p].change % mod * tr[p].change % mod * tr[p].change % mod;

        tr[p<<1|1].sum1 = lenr * tr[p].change % mod;
        tr[p<<1|1].sum2 = lenr * tr[p].change % mod * tr[p].change % mod;
        tr[p<<1|1].sum3 = lenr * tr[p].change % mod * tr[p].change % mod * tr[p].change % mod;

        tr[p].change = 0;
    }

    if (tr[p].muti != 1) {
        tr[p<<1].add = tr[p<<1].add * tr[p].muti % mod;
        tr[p<<1|1].add = tr[p<<1|1].add * tr[p].muti % mod;

        tr[p<<1].muti = tr[p<<1].muti * tr[p].muti % mod;
        tr[p<<1|1].muti = tr[p<<1|1].muti * tr[p].muti % mod;

        tr[p<<1].sum1 = tr[p<<1].sum1 * tr[p].muti % mod;
        tr[p<<1].sum2 = tr[p<<1].sum2 * tr[p].muti % mod * tr[p].muti % mod;
        tr[p<<1].sum3 = tr[p<<1].sum3 * tr[p].muti % mod * tr[p].muti % mod * tr[p].muti % mod;

        tr[p<<1|1].sum1 = tr[p<<1|1].sum1 * tr[p].muti % mod;
        tr[p<<1|1].sum2 = tr[p<<1|1].sum2 * tr[p].muti % mod * tr[p].muti % mod;
        tr[p<<1|1].sum3 = tr[p<<1|1].sum3 * tr[p].muti % mod * tr[p].muti % mod * tr[p].muti % mod;

        tr[p].muti = 1;
    }

    if (tr[p].add) {
        tr[p<<1].add = (tr[p<<1].add + tr[p].add) % mod;
        tr[p<<1|1].add = (tr[p<<1|1].add + tr[p].add) % mod;

        tr[p<<1].sum3 = (tr[p<<1].sum3 + 3 * tr[p].add % mod * tr[p<<1].sum2 % mod + 3 * tr[p].add % mod * tr[p].add % mod * tr[p<<1].sum1 % mod + lenl * tr[p].add % mod * tr[p].add % mod * tr[p].add % mod) % mod;
        tr[p<<1].sum2 = (tr[p<<1].sum2 + 2 * tr[p].add % mod * tr[p<<1].sum1 % mod + lenl * tr[p].add % mod * tr[p].add % mod) % mod;
        tr[p<<1].sum1 = (tr[p<<1].sum1 + lenl * tr[p].add % mod) % mod;

        tr[p<<1|1].sum3 = (tr[p<<1|1].sum3 + 3 * tr[p].add % mod * tr[p<<1|1].sum2 % mod + 3 * tr[p].add % mod * tr[p].add % mod * tr[p<<1|1].sum1 % mod + lenr * tr[p].add % mod * tr[p].add % mod * tr[p].add % mod) % mod;
        tr[p<<1|1].sum2 = (tr[p<<1|1].sum2 + 2 * tr[p].add % mod * tr[p<<1|1].sum1 % mod + lenr * tr[p].add % mod * tr[p].add % mod) % mod;
        tr[p<<1|1].sum1 = (tr[p<<1|1].sum1 + lenr * tr[p].add % mod) % mod;

        tr[p].add = 0;
    }
}

void update(int l, int r, int op, int c, int p, int pl, int pr) {
    if (l <= pl && r >= pr) {
        int len = (pr - pl + 1);
        if (op == 1) {
            tr[p].add = (tr[p].add + c) % mod;
            tr[p].sum3 = (tr[p].sum3 + 3 * c % mod * tr[p].sum2 % mod + 3 * c % mod * c % mod * tr[p].sum1 % mod + len * c % mod * c % mod * c % mod) % mod;
            tr[p].sum2 = (tr[p].sum2 + 2 * c % mod * tr[p].sum1 % mod + len * c % mod * c % mod) % mod;
            tr[p].sum1 = (tr[p].sum1 + len * c % mod) % mod;
        } else if (op == 2) {
            tr[p].add = tr[p].add * c % mod;
            tr[p].muti = tr[p].muti * c % mod;
            tr[p].sum1 = tr[p].sum1 * c % mod;
            tr[p].sum2 = tr[p].sum2 * c % mod * c % mod;
            tr[p].sum3 = tr[p].sum3 * c % mod * c % mod * c % mod;
        } else if (op == 3) {
            tr[p].add = 0;
            tr[p].muti = 1;
            tr[p].change = c;
            tr[p].sum1 = len * c % mod;
            tr[p].sum2 = len * c % mod * c % mod;
            tr[p].sum3 = len * c % mod * c % mod * c % mod;
        }
        return;
    }
    push_down(p, pl, pr);
    int mid = (pl + pr) >> 1;
    if (l <= mid) update(l, r, op, c, p<<1, pl, mid);
    if (r > mid) update(l, r, op, c, p<<1|1, mid+1, pr);
    push_up(p);
}

ll query(int l, int r, int op, int p, int pl, int pr) {
    if (l <= pl && r >= pr) {
        if (op == 1) return tr[p].sum1;
        if (op == 2) return tr[p].sum2;
        if (op == 3) return tr[p].sum3;
    }
    push_down(p, pl, pr);
    ll ans = 0;
    int mid = (pl + pr) >> 1;
    if (l <= mid) ans = (ans + query(l, r, op, p<<1, pl, mid)) % mod;
    if (r > mid) ans = (ans + query(l, r, op, p<<1|1, mid+1, pr)) % mod;
    return ans;
}

int n, m;

void solve() {
    build(1, 1, n);
    while (m--) {
        int op, x, y, c;
        cin >> op >> x >> y >> c;
        if (op == 1 || op == 2 || op == 3) {
            update(x, y, op, c, 1, 1, n);
        } else if (op == 4) {
            cout << query(x, y, c, 1, 1, n) % mod << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;
        solve();
    }
    return 0;
}