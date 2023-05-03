//
// Created by 王超凡 on 2023/4/6.
//https://www.luogu.com.cn/problem/P1368


#include <bits/stdc++.h>

using namespace std;
const int N=1e7;
int s[N];
int n;
int get_min(){
    for(int i=1;i<=n;++i)s[i+n]=s[i];
    int i=1,j=2,k=0;
    while(i<=n&&j<=n){
        for(k=0;k<n&&s[i+k]==s[j+k];++k);
        s[i+k]>s[j+k]?i=i+k+1:j=j+k+1;
        if(i==j)j++;
    }
    return min(i,j);
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",&s[i]);
    int ans=get_min();
    for(int i=ans;i<ans+n;++i)printf("%d",s[i]);
    return 0;
}