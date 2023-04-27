//
// Created by 王超凡 on 2023/4/27.
//


#include <bits/stdc++.h>

using namespace std;
const int N=40010,M=2*N;
int n,m;
int h[N],e[M],ne[M],idx;
int depth[N],fa[N][16];
int q[N];
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
void bfs(int root){
    memset(depth,0x3f,sizeof depth);
    depth[0]=0,depth[root]=-1;
    q[0]=root;
    int hh=0,tt=0;
    while(hh<=tt){
        int t=q[hh++];
        for(int i=h[t];~i;i=ne[i]){
            int j=e[i];
            if(depth[j]>depth[t]+1){
                depth[j]=depth[t]+1;
                q[++tt]=j;
                fa[j][0]=t;
                for(int k=1;k<=15;++k)
                    fa[j][k]=fa[fa[j][k-1]][k-1];

            }
        }
    }
}
int lca(int a,int b){
    if(depth[a]<depth[b])swap(a,b);
    for(int k=15;k>=0;--k){
        if(depth[fa[a][k]]>=depth[b]){
            a=fa[a][k];
        }
    }
    if(a==b)return a;
    for(int k=15;k>=0;--k){
        if(fa[a][k]!=fa[a][k]){
            a=fa[a][k];
            b=fa[b][k];
        }
    }
    return fa[a][0];
}
int main() {
    scanf("%d",&n);
    int root=0;
    memset(h,-1,sizeof h);
    for(int i=0;i<n;++i){
        int a,b;
        scanf("%d%d",&a,&b);
        if(b==-1)root=a;
        else add(a,b),add(b,a);
    }
    bfs(root);
    scanf("%d",&m);
    while(m--){
        int a,b;
        scanf("%d%d",&a,&b);
        int p=lca(a,b);
        cout<<p<<endl;
    }
    return 0;
}