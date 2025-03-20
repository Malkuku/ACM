#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 5e4 + 10;

struct Node {
    int l, r;       // 区间左右端点
    int sum;        // 区间内空花瓶的数量
    int add;        // 懒惰标记：1 表示填充，-1 表示清空
    int first;      // 区间内第一个空花瓶的位置
    int ends;       // 区间内最后一个空花瓶的位置
} tree[N << 2];

int n, m;

// 构建线段树
void build(int l, int r, int p) {
    tree[p].l = l, tree[p].r = r;
    tree[p].sum = r - l + 1;  // 初始时所有花瓶都是空的
    tree[p].add = 0;
    tree[p].first = l;
    tree[p].ends = r;

    if (l == r) return;

    int mid = (l + r) >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1 | 1);
}

// 向上更新节点信息
void push_up(int p) {
    tree[p].sum = tree[p << 1].sum + tree[p << 1 | 1].sum;

    if (tree[p << 1].first == -1) {
        tree[p].first = tree[p << 1 | 1].first;
    } else if (tree[p << 1 | 1].first == -1) {
        tree[p].first = tree[p << 1].first;
    } else {
        tree[p].first = min(tree[p << 1].first, tree[p << 1 | 1].first);
    }

    if (tree[p << 1].ends == -1) {
        tree[p].ends = tree[p << 1 | 1].ends;
    } else if (tree[p << 1 | 1].ends == -1) {
        tree[p].ends = tree[p << 1].ends;
    } else {
        tree[p].ends = max(tree[p << 1].ends, tree[p << 1 | 1].ends);
    }
}

// 向下更新节点信息
void push_down(int p) {
    if (tree[p].add == 1) {  // 填充操作
        tree[p << 1].sum = 0;
        tree[p << 1].first = -1;
        tree[p << 1].ends = -1;
        tree[p << 1].add = 1;

        tree[p << 1 | 1].sum = 0;
        tree[p << 1 | 1].first = -1;
        tree[p << 1 | 1].ends = -1;
        tree[p << 1 | 1].add = 1;
    } else if (tree[p].add == -1) {  // 清空操作
        tree[p << 1].sum = tree[p << 1].r - tree[p << 1].l + 1;
        tree[p << 1].first = tree[p << 1].l;
        tree[p << 1].ends = tree[p << 1].r;
        tree[p << 1].add = -1;

        tree[p << 1 | 1].sum = tree[p << 1 | 1].r - tree[p << 1 | 1].l + 1;
        tree[p << 1 | 1].first = tree[p << 1 | 1].l;
        tree[p << 1 | 1].ends = tree[p << 1 | 1].r;
        tree[p << 1 | 1].add = -1;
    }
    tree[p].add = 0;  // 清除懒惰标记
}

// 更新区间 [l, r] 的信息
void update(int l, int r, int p, int d) {
    if (tree[p].l == l && tree[p].r == r) {
        if (d == 1) {  // 填充操作
            tree[p].sum = 0;
            tree[p].first = -1;
            tree[p].ends = -1;
            tree[p].add = 1;
        } else if (d == -1) {  // 清空操作
            tree[p].sum = r - l + 1;
            tree[p].first = l;
            tree[p].ends = r;
            tree[p].add = -1;
        }
        return;
    }

    push_down(p);
    int mid = (tree[p].l + tree[p].r) >> 1;
    if (mid >= r) {
        update(l, r, p << 1, d);
    } else if (mid < l) {
        update(l, r, p << 1 | 1, d);
    } else {
        update(l, mid, p << 1, d);
        update(mid + 1, r, p << 1 | 1, d);
    }
    push_up(p);
}

// 查询区间 [l, r] 内空花瓶的数量
int query(int l, int r, int p) {
    if (tree[p].l == l && tree[p].r == r) {
        return tree[p].sum;
    }

    push_down(p);
    int mid = (tree[p].l + tree[p].r) >> 1;
    if (mid >= r) {
        return query(l, r, p << 1);
    } else if (mid < l) {
        return query(l, r, p << 1 | 1);
    } else {
        return query(l, mid, p << 1) + query(mid + 1, r, p << 1 | 1);
    }
}

// 查询区间 [l, r] 内第一个空花瓶的位置
int queryfr(int l, int r, int p) {
    if (tree[p].l == l && tree[p].r == r) {
        return tree[p].first;
    }

    push_down(p);
    int mid = (tree[p].l + tree[p].r) >> 1;
    if (mid >= r) {
        return queryfr(l, r, p << 1);
    } else if (mid < l) {
        return queryfr(l, r, p << 1 | 1);
    } else {
        int ans = queryfr(l, mid, p << 1);
        if (ans == -1) {
            return queryfr(mid + 1, r, p << 1 | 1);
        } else {
            return ans;
        }
    }
}

// 查询区间 [l, r] 内最后一个空花瓶的位置
int queryed(int l, int r, int p) {
    if (tree[p].l == l && tree[p].r == r) {
        return tree[p].ends;
    }

    push_down(p);
    int mid = (tree[p].l + tree[p].r) >> 1;
    if (mid >= r) {
        return queryed(l, r, p << 1);
    } else if (mid < l) {
        return queryed(l, r, p << 1 | 1);
    } else {
        int ans = queryed(mid + 1, r, p << 1 | 1);
        if (ans == -1) {
            return queryed(l, mid, p << 1);
        } else {
            return ans;
        }
    }
}

// 二分查找满足条件的区间
int find(int sta, int sum) {
    int l = sta, r = n;
    int ans = n;
    while (l <= r) {
        int mid = (l + r) >> 1;
        int gg = query(sta, mid, 1);
        gg = mid - sta + 1 - gg;  // 计算区间 [sta, mid] 内空花瓶的数量
        if (gg >= sum) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}

void solve() {
    cin >> n >> m;
    build(1, n, 1);

    for (int i = 1; i <= m; i++) {
        int op, a, f;
        cin >> op >> a >> f;

        if (op == 1) {
            a++;
            int res = query(a, n, 1);
            res = n - a + 1 - res;  // 计算区间 [a, n] 内空花瓶的数量
            if (res == 0) {
                cout << "Can not put any one.\n";
            } else {
                int sum = min(res, f);
                int ed = find(a, sum);
                int fr = queryfr(a, ed, 1);
                update(fr, ed, 1, 1);
                cout << fr - 1 << " " << ed - 1 << "\n";
            }
        } else {
            a++, f++;
            int res = query(a, f, 1);
            update(a, f, 1, -1);
            cout << res << "\n";
        }
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}