#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
typedef pair<int,int> PII;
vector<PII> query[N];
vector<int> e[N];
int fa[N],vis[N],ans[N];
int n,m;
int find(int x){
    if(fa[x]!=x)fa[x]=find(fa[x]);
    return fa[x];
}
void tarjan(int u){
    vis[u]=true;//入u时候就标记u
    for(auto v:e[u]){
        if(!vis[v]){
            tarjan(v);
            fa[v]=u;//回u时候,v指向u
        }
    }
    //离u的时,枚举LCA
    for(auto q:query[u]){
        int v=q.first,i=q.second;
        if(vis[v])ans[i]=find(v);
    }
}
int main() {
    int k;
    cin>>n>>m>>k;
    int a,b;
    for(int i=1;i<n;++i){
        scanf("%d%d",&a,&b);
        e[a].push_back(b);
        e[b].push_back(a);
    }
    for(int i=1;i<=m;++i){
        scanf("%d%d",&a,&b);
        query[a].push_back({b,i});
        query[b].push_back({a,i});
    }
    for(int i=1;i<N;++i)fa[i]=i;
    tarjan(k);
    for(int i=1;i<=m;++i)cout<<ans[i]<<endl;
    return 0;
}