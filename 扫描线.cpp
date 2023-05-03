//
// Created by 王超凡 on 2023/5/3.
//


#include <bits/stdc++.h>

using namespace std;
#define lc u<<1
#define lr u<<1|1
//使用离散线段树
const int N=1e5+10;
typedef long long LL;
struct Line{//扫描线
    int x,y1,y2;
    int flg;
    bool operator<(Line& b){return x<b.x;}
}L[N];
struct Tree{//离散线段树,便于维护坐标值,区间长度
    int l,r,len;//区间有效高度
    int cnt;//区间覆盖次数
}tr[N*8];
int n,Y[N];//矩形的y坐标
void build(int u,int l,int r){
    tr[u].l=Y[l];tr[u].r=Y[r];
    if(r==l+1)return;//叶子宽度是2
    int mid=l+r>>1;
    build(lc,l,mid);
    build(lr,mid,r);
}
void pushup(int u){//向上拼凑答案
    if(tr[u].cnt)tr[u].len=tr[u].r-tr[u].l;
    else tr[u].len=tr[lc].len+tr[lr].len;
}
void change(int u,int a,int b,int c){//向下分裂区间
    if(a>=tr[u].r||b<=tr[u].l)return;//越界
    if(a<=tr[u].l&&tr[u].r<=b){
        tr[u].cnt+=c;pushup(u);return;
    }
    change(lc,a,b,c);
    change(lr,a,b,c);//裂开
    pushup(u);
}
int main() {
    scanf("%d",&n);
    int x1,x2,y1,y2;
    for(int i=1;i<=n;++i){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        L[i]={x1,y1,y2,1},L[n+i]={x2,y1,y2,-1};
        Y[i]=y1,Y[n+i]=y2;
    }
    n*=2;
    sort(L+1,L+n+1);//扫描线排序
    sort(Y+1,Y+1+n);//Y坐标离散化
    build(1,1,n);
    LL ans=0;
    for(int i=1;i<n;++i){//枚举扫描线
        change(1,L[i].y1,L[i].y2,L[i].flg);
        ans+=1LL*(L[i+1].x-L[i].x)*tr[1].len;
    }
    cout<<ans<<endl;
    return 0;
}