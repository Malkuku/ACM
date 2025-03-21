#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 10;

struct Node {
    int pre, suf, len, num; // 前缀1，后缀1，最大连续1，区间1的个数
    int pre0, suf0, len0, num0; // 前缀0，后缀0，最大连续0，区间0的个数
    int add1, add2, add3; // 标记：add1-区间赋0，add2-区间赋1，add3-区间反转
    void clear() { add1 = add2 = add3 = 0; } // 清空标记
} tr[N << 2];

int a[N];

// 交换0和1的信息
void swa(int p) {
    swap(tr[p].pre, tr[p].pre0);
    swap(tr[p].suf, tr[p].suf0);
    swap(tr[p].len, tr[p].len0);
    swap(tr[p].num, tr[p].num0);
}

// 上推更新区间信息
void push_up(int p, int len) {
    int l = p << 1, r = p << 1 | 1;
    tr[p].num = tr[l].num + tr[r].num;
    tr[p].num0 = tr[l].num0 + tr[r].num0;

    // 更新前缀1和后缀1
    tr[p].pre = tr[l].pre;
    if (tr[l].pre == len - (len >> 1)) tr[p].pre += tr[r].pre;

    tr[p].suf = tr[r].suf;
    if (tr[r].suf == (len >> 1)) tr[p].suf += tr[l].suf;

    // 更新前缀0和后缀0
    tr[p].pre0 = tr[l].pre0;
    if (tr[l].pre0 == len - (len >> 1)) tr[p].pre0 += tr[r].pre0;

    tr[p].suf0 = tr[r].suf0;
    if (tr[r].suf0 == (len >> 1)) tr[p].suf0 += tr[l].suf0;

    // 更新最大连续1和最大连续0
    tr[p].len = max(max(tr[l].len, tr[r].len), tr[l].suf + tr[r].pre);
    tr[p].len0 = max(max(tr[l].len0, tr[r].len0), tr[l].suf0 + tr[r].pre0);
}

// 应用标记
void addtag(int p, int len) {
    if (tr[p].add1) { // 区间赋0
        tr[p].num = tr[p].len = tr[p].pre = tr[p].suf = 0;
        tr[p].num0 = tr[p].len0 = tr[p].pre0 = tr[p].suf0 = len;
    } else if (tr[p].add2) { // 区间赋1
        tr[p].num = tr[p].len = tr[p].pre = tr[p].suf = len;
        tr[p].num0 = tr[p].len0 = tr[p].pre0 = tr[p].suf0 = 0;
    } else if (tr[p].add3) { // 区间反转
        swa(p);
    }
}

// 下推标记
void push_down(int p, int pl, int pr) {
    int mid = (pl + pr) >> 1;
    if (tr[p].add1 || tr[p].add2 || tr[p].add3) {
        if (tr[p].add1) { // 区间赋0
            tr[p << 1].clear(), tr[p << 1 | 1].clear();
            tr[p << 1].add1 = tr[p << 1 | 1].add1 = 1;
            tr[p << 1].add2 = tr[p << 1 | 1].add2 = 0;
            tr[p << 1].add3 = tr[p << 1 | 1].add3 = 0;
        } else if (tr[p].add2) { // 区间赋1
            tr[p << 1].clear(), tr[p << 1 | 1].clear();
            tr[p << 1].add2 = tr[p << 1 | 1].add2 = 1;
            tr[p << 1].add1 = tr[p << 1 | 1].add1 = 0;
            tr[p << 1].add3 = tr[p << 1 | 1].add3 = 0;
        } else if (tr[p].add3) { // 区间反转
            if (tr[p << 1].add1 || tr[p << 1].add2) {
                swap(tr[p << 1].add1, tr[p << 1].add2);
            } else {
                tr[p << 1].add3 ^= 1;
            }
            if (tr[p << 1 | 1].add1 || tr[p << 1 | 1].add2) {
                swap(tr[p << 1 | 1].add1, tr[p << 1 | 1].add2);
            } else {
                tr[p << 1 | 1].add3 ^= 1;
            }
        }
        // 更新子节点的值
        addtag(p << 1, mid - pl + 1);
        addtag(p << 1 | 1, pr - mid);
        tr[p].clear();
    }
}



// 建树
void build(int p, int pl, int pr) {
    tr[p].clear();
    if (pl == pr) {
        tr[p].num = tr[p].len = tr[p].pre = tr[p].suf = a[pl];
        tr[p].num0 = tr[p].len0 = tr[p].pre0 = tr[p].suf0 = 1 - a[pl];
        return;
    }
    int mid = (pl + pr) >> 1;
    build(p << 1, pl, mid);
    build(p << 1 | 1, mid + 1, pr);
    push_up(p, pr - pl + 1);
}

// 区间更新
void update(int l, int r, int d, int p, int pl, int pr) {
    if (l <= pl && r >= pr) {
        if (d == 1) { // 区间赋0
            tr[p].clear();
            tr[p].add1 = 1;
        } else if (d == 2) { // 区间赋1
            tr[p].clear();
            tr[p].add2 = 1;
        } else if (d == 3) { // 区间反转
            if (tr[p].add1 || tr[p].add2) {
                swap(tr[p].add1, tr[p].add2);
            } else {
                tr[p].add3 ^= 1;
            }
        }
        addtag(p, pr - pl + 1);
        return;
    }
    push_down(p, pl, pr);
    int mid = (pl + pr) >> 1;
    if (l <= mid) update(l, r, d, p << 1, pl, mid);
    if (r > mid) update(l, r, d, p << 1 | 1, mid + 1, pr);
    push_up(p, pr - pl + 1);
}

// 查询区间1的个数
int query_num(int l, int r, int p, int pl, int pr) {
    if (l <= pl && r >= pr) return tr[p].num;
    push_down(p, pl, pr);
    int mid = (pl + pr) >> 1;
    int ans = 0;
    if (l <= mid) ans += query_num(l, r, p << 1, pl, mid);
    if (r > mid) ans += query_num(l, r, p << 1 | 1, mid + 1, pr);
    return ans;
}

// 查询区间最大连续1的长度
int query_len(int l, int r, int p, int pl, int pr) {
    if (l <= pl && r >= pr) return tr[p].len;
    push_down(p, pl, pr);
    int mid = (pl + pr) >> 1;
    int ans = 0;
    if (l <= mid) ans = max(ans, query_len(l, r, p << 1, pl, mid));
    if (r > mid) ans = max(ans, query_len(l, r, p << 1 | 1, mid + 1, pr));
    if (l <= mid && r > mid) { // 跨区间的情况
        ans = max(ans, min(mid - l + 1, tr[p << 1].suf) + min(r - mid, tr[p << 1 | 1].pre));
    }
    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    while (m--) {
        int op, l, r;
        cin >> op >> l >> r;
        l++, r++;
        if (op == 0) update(l, r, 1, 1, 1, n); // 区间赋0
        else if (op == 1) update(l, r, 2, 1, 1, n); // 区间赋1
        else if (op == 2) update(l, r, 3, 1, 1, n); // 区间反转
        else if (op == 3) cout << query_num(l, r, 1, 1, n) << "\n"; // 查询区间1的个数
        else if (op == 4) cout << query_len(l, r, 1, 1, n) << "\n"; // 查询最大连续1的长度
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}