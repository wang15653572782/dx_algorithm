//
// Created by 王超凡 on 2023/5/2.
//


#include <bits/stdc++.h>

using namespace std;
#define lc p<<1
#define lr p<<1|1
#define N 100005
int n,w[N];
struct node{
    int l,r,sum,add;
}tr[N*4];
void pushup(int p)//向上更新
{
    tr[p].sum=tr[lc].sum+tr[lr].sum;
}
void pushdown(int p){//向下更新
    if(tr[p].add){//懒标记存在的话,把账给你儿子
        tr[lc].sum+=tr[p].add*(tr[lc].r-tr[lc].l+1);
        tr[lr].sum+=tr[p].add*(tr[lr].r-tr[lr].l+1);
        tr[lc].add+=tr[p].add;
        tr[lr].add+=tr[p].add;
        tr[p].add=0;//把账分给儿子们了,自己解放了
    }
}
void build(int p,int l,int r){//从编号为p,建l~r之间的树
    tr[p]={l,r,w[l],0};
    if(l==r)return;//是叶节点了则返回
    int mid=l+r>>1;//不是叶节点则裂开
    build(lc,l,mid);
    build(lr,mid+1,r);
    pushup(p);//向上更新每一段的sum值
}
void update(int p,int x,int y,int k){//在区间x~y之间所有元素+k
    if(x<=tr[p].l&&tr[p].r<=y){//覆盖则修改
        tr[p].sum+=(tr[p].r-tr[p].l+1)*k;
        tr[p].add+=k;
        return;
    }
    int m=tr[p].l+tr[p].r>>1;//不覆盖则裂开
    pushdown(p);
    if(x<=m)update(lc,x,y,k);
    if(y>m)update(lr,x,y,k);
    pushup(p);
}
int query(int p,int x,int y){//查询x~y之间的区间和
    if(x<=tr[p].l&&tr[p].r<=y)//覆盖则返回
        return tr[p].sum;
    int m=tr[p].l+tr[p].r>>1;
    pushdown(p);
    int s=0;
    if(x<=m)s+=query(lc,x,y);
    if(y>m)s+=query(lr,x,y);
    return s;
}
int main() {
    int tmp[10]={5,2,0,1,9,7,2,1,2,3};
    for(int i=0;i<10;++i)w[i+1]=tmp[i];
    build(1,1,10);
    update(1,1,5,10);
    cout<<query(1,1,5)<<endl;
    return 0;
}