#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
const int M = 5e4 + 10; // 定义线段树的节点数量上限
struct TnT { // 定义线段树的节点结构
    int l , r , num , add , first , ends; // 分别表示区间的左右端点、区间内满足条件的数量、懒惰标记、区间内第一个满足条件的位置、区间内最后一个满足条件的位置
}T[M << 2]; // 定义线段树数组，大小为 M 的四倍
int n , m; // n 表示总长度，m 表示操作次数
// 构建线段树
void build(int l,int r,int p){
    T[p].add = T[p].num = 0;
    T[p].first = l,T[p].ends = r;
    T[p].l = l,T[p].r = r;
    
    if(l == r) return;

    int mid = (l+r) >> 1;
    build(l,mid,p << 1);
    build(mid+1,r,p << 1 | 1);
}
// 向上更新节点信息
void pushup(int p){
    T[p].num = T[p << 1].num + T[p << 1 | 1].num;

    if(T[p << 1].first == -1) T[p].first = T[p << 1 | 1].first;
    else if(T[p << 1 | 1].first == -1) T[p].first = T[p << 1].first;
    else T[p].first = min(T[p << 1].first,T[p << 1 | 1].first);

    if(T[p << 1].ends == -1) T[p].ends = T[p << 1 | 1].ends;
    else if(T[p << 1 | 1].ends == -1) T[p].ends = T[p << 1].ends;
    else T[p].ends = max(T[p << 1].ends,T[p << 1 | 1].ends);
}
// 向下更新节点信息
void pushdown(int p) {
    if(T[p].add == 1) { // 如果当前节点的懒惰标记为 1
        T[p << 1].num = T[p << 1].r - T[p << 1].l + 1; // 更新左子节点的 num 值
        T[p << 1].first = -1; // 更新左子节点的 first 值
        T[p << 1].ends = -1; // 更新左子节点的 ends 值
        T[(p << 1) | 1].num = T[(p << 1) | 1].r - T[(p << 1) | 1].l + 1; // 更新右子节点的 num 值
        T[(p << 1) | 1].first = -1; // 更新右子节点的 first 值
        T[(p << 1) | 1].ends = -1; // 更新右子节点的 ends 值
        T[p << 1].add = T[p].add; // 更新左子节点的懒惰标记
        T[(p << 1) | 1].add = T[p].add; // 更新右子节点的懒惰标记
    }
    if(T[p].add == -1) { // 如果当前节点的懒惰标记为 -1
        T[p << 1].first = T[p << 1].l; // 更新左子节点的 first 值
        T[p << 1].ends = T[p << 1].r; // 更新左子节点的 ends 值
        T[p << 1].num = 0; // 更新左子节点的 num 值
        T[(p << 1) | 1].num = 0; // 更新右子节点的 num 值
        T[p << 1].add = T[p].add; // 更新左子节点的懒惰标记
        T[(p << 1) | 1].first = T[(p << 1) | 1].l; // 更新右子节点的 first 值
        T[(p << 1) | 1].ends = T[(p << 1) | 1].r; // 更新右子节点的 ends 值
        T[(p << 1) | 1].add = T[p].add; // 更新右子节点的懒惰标记
    }
    T[p].add = 0; // 清除当前节点的懒惰标记
}
// 查询区间 [l, r] 内的 num 值
int query(int l , int r , int p) {
    int mid = (T[p].l + T[p].r) >> 1; // 计算当前区间的中点
    if(T[p].l == l && T[p].r == r) { // 如果当前区间与查询区间完全匹配
        return T[p].num; // 直接返回当前节点的 num 值
    }
    pushdown(p); // 向下更新节点信息
    if(mid >= r) { // 如果查询区间在左子树范围内
        return query(l , r , p << 1); // 递归查询左子树
    }
    else if(mid < l) { // 如果查询区间在右子树范围内
        return query(l , r , (p << 1) | 1); // 递归查询右子树
    }
    else { // 否则查询区间跨越左右子树
        return query(l , mid , p << 1) + query(mid + 1 , r , (p << 1) | 1); // 分别查询左右子树并返回结果之和
    }
}
// 查询区间 [l, r] 内的 first 值
int queryfr(int l , int r , int p) {
    int mid = (T[p].l + T[p].r) >> 1; // 计算当前区间的中点
    if(T[p].l == l && T[p].r == r) { // 如果当前区间与查询区间完全匹配
        return T[p].first; // 直接返回当前节点的 first 值
    }
    pushdown(p); // 向下更新节点信息
    if(mid >= r) { // 如果查询区间在左子树范围内
        return queryfr(l , r , p << 1); // 递归查询左子树
    }
    else if(mid < l) { // 如果查询区间在右子树范围内
        return queryfr(l , r , (p << 1) | 1); // 递归查询右子树
    }
    else { // 否则查询区间跨越左右子树
        int ans = queryfr(l , mid , p << 1); // 查询左子树的 first 值
        if(ans == -1) { // 如果左子树的 first 值为 -1
            return queryfr(mid + 1 , r , (p << 1) | 1); // 返回右子树的 first 值
        }
        else { // 否则
            return ans; // 返回左子树的 first 值
        }
    }
}
// 查询区间 [l, r] 内的 ends 值
int queryed(int l , int r , int p) {
    int mid = (T[p].l + T[p].l) >> 1; // 计算当前区间的中点（这里应该是 T[p].r，可能是代码的错误）
    if(T[p].l == l && T[p].r == r) { // 如果当前区间与查询区间完全匹配
        return T[p].ends; // 直接返回当前节点的 ends 值
    }
    pushdown(p); // 向下更新节点信息
    if(mid >= r) { // 如果查询区间在左子树范围内
        return queryed(l , r , p << 1); // 递归查询左子树
    }
    else if(mid < l) { // 如果查询区间在右子树范围内
        return queryed(l , r , (p << 1) | 1); // 递归查询右子树
    }
    else { // 否则查询区间跨越左右子树
        int ans = queryed(mid + 1 , r , (p << 1) | 1); // 查询右子树的 ends 值
        if(ans == -1) { // 如果右子树的 ends 值为 -1
            return queryed(l , mid , p << 1); // 返回左子树的 ends 值
        }
        else { // 否则
            return ans; // 返回右子树的 ends 值
        }
    }
}
// 更新区间 [l, r] 的信息
void updata(int l , int r , int p , int ad) {
    int mid = (T[p].l + T[p].r) >> 1; // 计算当前区间的中点
    if(T[p].l == l && T[p].r == r) { // 如果当前区间与更新区间完全匹配
        if(ad == 1) { // 如果更新操作为 1
            T[p].add = 1; // 设置当前节点的懒惰标记为 1
            T[p].num = T[p].r - T[p].l + 1; // 更新当前节点的 num 值
            T[p].first = -1; // 更新当前节点的 first 值
            T[p].ends = -1; // 更新当前节点的 ends 值
            return ; // 直接返回
        }
        if(ad == -1) { // 如果更新操作为 -1
            T[p].add = -1; // 设置当前节点的懒惰标记为 -1
            T[p].num = 0; // 更新当前节点的 num 值
            T[p].first = T[p].l; // 更新当前节点的 first 值
            T[p].ends = T[p].r; // 更新当前节点的 ends 值
            return ; // 直接返回
        }
    }
    pushdown(p); // 向下更新节点信息
    if(mid >= r) { // 如果更新区间在左子树范围内
        updata(l , r , p << 1 , ad); // 递归更新左子树
    }
    else if(mid < l) { // 如果更新区间在右子树范围内
        updata(l , r , (p << 1) | 1 , ad); // 递归更新右子树
    }
    else { // 否则更新区间跨越左右子树
        updata(l , mid , p << 1 , ad); // 更新左子树
        updata(mid + 1 , r , (p << 1) | 1 , ad); // 更新右子树
    }
    pushup(p); // 向上更新节点信息
}
// 二分查找满足条件的区间
int bisearch(int sta , int sum) {
    int l = sta , r = n; // 初始化二分查找的左右边界
    int ans = n; // 初始化答案为 n
    while(l <= r) { // 二分查找的循环条件
        int mid = (l + r) >> 1; // 计算中间位置
        int gg = query(sta , mid , 1); // 查询区间 [sta, mid] 内的 num 值
        gg = mid - sta + 1 - gg; // 计算区间 [sta, mid] 内不满足条件的数量
        if(gg >= sum) { // 如果不满足条件的数量大于等于 sum
            r = mid - 1; // 更新右边界
            ans = mid; // 更新答案
        }
        else { // 否则
            l = mid + 1; // 更新左边界
        }
    }
    return ans; // 返回答案
}
int main() {
    int t; // 测试用例的数量
    scanf("%d" , &t); // 输入测试用例的数量
    while(t--) { // 遍历每个测试用例
        scanf("%d%d" , &n , &m); // 输入总长度 n 和操作次数 m
        build(1 , n , 1); // 构建线段树
        for(int i = 1 ; i <= m ; i++) { // 遍历每个操作
            int k , a , f; // 操作类型、操作区间左端点、操作区间右端点
            scanf("%d%d%d" , &k , &a , &f); // 输入操作信息
            if(k == 1) { // 如果操作类型为 1
                a++; // 将操作区间左端点加 1
                int res = query(a , n , 1); // 查询区间 [a, n] 内的 num 值
                res = n - a + 1 - res; // 计算区间 [a, n] 内不满足条件的数量
                if(res == 0) { // 如果不满足条件的数量为 0
                    printf("Can not put any one.\n"); // 输出无法放置
                    continue; // 跳过当前操作
                }
                int sum = min(res , f); // 计算需要放置的数量
                int ed = bisearch(a , sum); // 二分查找满足条件的区间
                int fr = queryfr(a , ed , 1); // 查询区间 [a, ed] 内的 first 值
                updata(fr , ed , 1 , 1); // 更新区间 [fr, ed] 的信息
                printf("%d %d\n" , fr - 1 , ed - 1); // 输出放置的位置
            }
            if(k == 2) { // 如果操作类型为 2
                a++ , f++; // 将操作区间左端点和右端点加 1
                int res = query(a , f , 1); // 查询区间 [a, f] 内的 num 值
                updata(a , f , 1 , -1); // 更新区间 [a, f] 的信息
                printf("%d\n" , res); // 输出查询结果
            }
        }
        printf("\n"); // 输出换行符
    }
    return 0; // 返回 0
}

