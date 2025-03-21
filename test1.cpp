#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define mid int m = (l + r) >> 1
#define ll long long

const int M = 1e5 + 10;
int lsum1[M<<2],rsum1[M<<2],sum1[M<<2];
int lsum0[M<<2],rsum0[M<<2],sum0[M<<2];
int sum[M<<2],same[M<<2],rev[M<<2];
int a[M];

void pushup(int l,int r,int rt){   
    mid;
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
    lsum0[rt] = lsum0[rt<<1]; lsum1[rt] = lsum1[rt<<1];
    rsum0[rt] = rsum0[rt<<1|1]; rsum1[rt] = rsum1[rt<<1|1];
    if(lsum0[rt] == m-l+1) lsum0[rt] += lsum0[rt<<1|1];
    if(rsum0[rt] == r-m) rsum0[rt] += rsum0[rt<<1];
    if(lsum1[rt] == m-l+1) lsum1[rt] += lsum1[rt<<1|1];
    if(rsum1[rt] == r-m) rsum1[rt] += rsum1[rt<<1];
    sum0[rt] = max(max(sum0[rt<<1],sum0[rt<<1|1]),lsum0[rt<<1|1]+rsum0[rt<<1]);
    sum1[rt] = max(max(sum1[rt<<1],sum1[rt<<1|1]),lsum1[rt<<1|1]+rsum1[rt<<1]);
}

void swa(int len,int rt){
    sum[rt] = len - sum[rt];
    swap(lsum1[rt],lsum0[rt]);
    swap(rsum1[rt],rsum0[rt]);
    swap(sum1[rt],sum0[rt]);
}

void pushdown(int l,int r,int rt){
    mid;
    if(same[rt]!=-1){
        rev[rt<<1] = rev[rt<<1|1] = 0;
        same[rt<<1] = same[rt<<1|1] = same[rt];
        if(same[rt]){
            sum[rt<<1] = lsum1[rt<<1] = rsum1[rt<<1] = sum1[rt<<1] = m-l+1;
            sum[rt<<1|1] = lsum1[rt<<1|1] = rsum1[rt<<1|1] = sum1[rt<<1|1] = r-m;
            lsum0[rt<<1] = rsum0[rt<<1] = sum0[rt<<1] = sum0[rt<<1|1] = rsum0[rt<<1|1] = lsum0[rt<<1|1] = 0;
        }
        else{
            sum[rt<<1] = lsum1[rt<<1] = rsum1[rt<<1] = sum1[rt<<1] = 0;
            sum[rt<<1|1] = lsum1[rt<<1|1] = rsum1[rt<<1|1] = sum1[rt<<1|1] = 0;
            lsum0[rt<<1] = rsum0[rt<<1] = sum0[rt<<1] = m-l+1;
            sum0[rt<<1|1] = rsum0[rt<<1|1] = lsum0[rt<<1|1] = r-m;
        }
        same[rt] = -1;
    }
    if(rev[rt]){
        if(same[rt<<1] != -1){
            same[rt<<1] ^= 1;
            if(same[rt<<1]){
                sum[rt<<1] = lsum1[rt<<1] = rsum1[rt<<1] = sum1[rt<<1] = m-l+1;
                lsum0[rt<<1] = rsum0[rt<<1] = sum0[rt<<1] = 0;
            }
            else{
                sum[rt<<1] = lsum1[rt<<1] = rsum1[rt<<1] = sum1[rt<<1] = 0;
                lsum0[rt<<1] = rsum0[rt<<1] = sum0[rt<<1] = m-l+1;
            }
        }
        else{
            rev[rt<<1] ^= 1;
            swa(m-l+1,rt<<1);
        }
        if(same[rt<<1|1] != -1){
            same[rt<<1|1] ^= 1;
            if(same[rt<<1|1]){
                sum[rt<<1|1] = lsum1[rt<<1|1] = rsum1[rt<<1|1] = sum1[rt<<1|1] = r-m;
                sum0[rt<<1|1] = rsum0[rt<<1|1] = lsum0[rt<<1|1] = 0;
            }
            else{
                sum[rt<<1|1] = lsum1[rt<<1|1] = rsum1[rt<<1|1] = sum1[rt<<1|1] = 0;
                sum0[rt<<1|1] = rsum0[rt<<1|1] = lsum0[rt<<1|1] = r-m;
            }
        }
        else{
            rev[rt<<1|1] ^= 1;
            swa(r-m,rt<<1|1);
        }
        rev[rt] = 0;
    }
}

void build(int l,int r,int rt){
    same[rt] = -1; rev[rt] = 0;
    lsum1[rt] = rsum1[rt] = lsum0[rt] = rsum0[rt] = sum0[rt] = sum1[rt] = sum[rt] = 0;
    if(l == r){
        if(a[l]){
            lsum1[rt] = sum[rt] = sum1[rt] = rsum1[rt] = 1;
            lsum0[rt] = rsum0[rt] = sum0[rt] = 0;
        }
        else {
            sum1[rt] = sum[rt] = sum1[rt] = rsum1[rt] = 0;
            lsum0[rt] = rsum0[rt] = sum0[rt] = 1;
        }
        return ;
    }
    mid ;
    build(lson); build(rson);
    pushup(l,r,rt);
}

void update_same(int L,int R,int c,int l,int r,int rt){
    if(L <= l&&R >= r){
        rev[rt] = 0;
        same[rt] = c;
        if(same[rt]){
            sum[rt] = lsum1[rt] = rsum1[rt] = sum1[rt] = r-l+1;
            lsum0[rt] = rsum0[rt] = sum0[rt] = 0;
        }
        else{
            sum[rt] = lsum1[rt] = rsum1[rt] = sum1[rt] = 0;
            lsum0[rt] = rsum0[rt] = sum0[rt] = r-l+1;
        }
        return ;
    }
    pushdown(l,r,rt);
    mid;
    if(L <= m) update_same(L,R,c,lson);
    if(R > m) update_same(L,R,c,rson);
    pushup(l,r,rt);
}

void update_rev(int L,int R,int l,int r,int rt){
    if(L <= l&&R >= r){
        if(same[rt] != -1){
            same[rt] ^= 1;
            if(same[rt]){
                sum[rt] = lsum1[rt] = rsum1[rt] = sum1[rt] = r-l+1;
                lsum0[rt] = rsum0[rt] = sum0[rt] = 0;
            }
            else{
                sum[rt] = lsum1[rt] = rsum1[rt] = sum1[rt] = 0;
                lsum0[rt] = rsum0[rt] = sum0[rt] = r-l+1;
            }
        }
        else{
            rev[rt] ^= 1;
            swa(r-l+1,rt);
        }
        return ;
    }
    mid ;
    pushdown(l,r,rt);
    if(L <= m) update_rev(L,R,lson);
    if(R > m) update_rev(L,R,rson);
    pushup(l,r,rt);
}

int query_sum(int L,int R,int l,int r,int rt){
    if(L <= l&&R >= r){
        return sum[rt];
    }
    pushdown(l,r,rt);
    mid;
    int ret = 0;
    if(L <= m) ret += query_sum(L,R,lson);
    if(R > m) ret += query_sum(L,R,rson);
    return ret;
}

int query_max(int L,int R,int l,int r,int rt){
    if(L <= l&&R >= r){
        return sum1[rt];
    }
    pushdown(l,r,rt);
    mid;
    int ret = 0;
    if(L > m) return query_max(L,R,rson);
    if(R <= m) return query_max(L,R,lson);
    int t1 = query_max(L,R,lson);
    int t2 = query_max(L,R,rson);
    int ls = min(rsum1[rt<<1],m-L+1);
    int rs = min(lsum1[rt<<1|1],R-m);
    return max(max(t1,t2),ls+rs);
}

int main()
{
    int n,q,x,y,op,t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&q);
        for(int i = 1;i <= n;i ++)
            scanf("%d",&a[i]);
        build(1,n,1);
        while(q--){
            scanf("%d%d%d",&op,&x,&y);
            x++; y++;
            if(op == 0){
                update_same(x,y,0,1,n,1);
            }
            else if(op == 1){
                update_same(x,y,1,1,n,1);
            }
            else if(op == 2){
                update_rev(x,y,1,n,1);
            }
            else if(op == 3){
                printf("%d\n",query_sum(x,y,1,n,1));
            }
            else {
                printf("%d\n",query_max(x,y,1,n,1));
            }
        }
    }
    return 0;
}