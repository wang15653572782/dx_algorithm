//
// Created by 王超凡 on 2023/5/6.
//


#include <bits/stdc++.h>

using namespace std;
const int N=5e5+10;
vector<int> e[N];
int fa[N]//存u的父节点
,dep[N]//存u的深度
,son[N]//存u的重儿子
,sz[N];//存以u为根的子树的结点数
int top[N];//存u所在重链的顶点
int n,m;
void dfs1(int u,int father){//预处理出fa,son,dep
    fa[u]=father,dep[u]=dep[father]+1,sz[u]=1;
    for(int v:e[u]){
        if(v==father)continue;
        dfs1(v,u);
        sz[u]+=sz[v];
        if(sz[son[u]]<sz[v])son[u]=v;
    }
}
void dfs2(int u,int t){//处理出top
    top[u]=t;//记录链头
    if(!son[u])return;//无重儿子就返回,就是叶节点返回
    dfs2(son[u],t);//搜重儿子
    for(int v:e[u]) {
        if (v == fa[u] || v == son[u])continue;
        dfs2(v, v);//搜轻儿子
    }
}
int lca(int u,int v){
    while(top[u]!=top[v]){
        if(dep[top[u]]<dep[top[v]])swap(u,v);
        u=fa[top[u]];//让处于较深重链的顶点跳到他顶点的父节点,类似于倍增法
    }
    return dep[u]<dep[v]?u:v;
}
int main() {
    int k;
    cin>>n>>m>>k;
    for(int i=1;i<n;++i){
        int a,b;
        scanf("%d%d",&a,&b);
        e[a].push_back(b);
        e[b].push_back(a);
    }
    dfs1(k,0);
    dfs2(k,k);

    while(m--){
        int u,v;
        scanf("%d%d",&u,&v);
        cout<<lca(u,v)<<endl;
    }
    //for(int i=1;i<=5;++i)cout<<top[i]<<endl;
    return 0;
}