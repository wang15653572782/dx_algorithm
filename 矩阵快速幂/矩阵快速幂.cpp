//
// Created by 王超凡 on 2023/4/8.
//<<<<<<< HEAD
////https://www.luogu.com.cn/problem/P3390    //
//=======
////
//>>>>>>> 518ee7614f2ade8e80a20662095c77e6fac80e66


#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int mod=1e9+7;
LL n,k;
struct matrix{
    LL c[110][110];
    matrix(){
        memset(c,0,sizeof c);
    }
};

matrix operator*(matrix &a,matrix &b){
    matrix ans;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            for(int k=1;k<=n;++k){
                ans.c[i][j]=(ans.c[i][j]+a.c[i][k]*b.c[k][j])%mod;
            }
    return ans;
}
void qmi(matrix &a,LL k){
    matrix ans;
    for(int i=1;i<=n;++i)ans.c[i][i]=1;
    while(k){
        if(k&1)ans=ans*a;
        a=a*a;
        k>>=1;
    }
    a=ans;
}
int main()
{
    cin>>n>>k;
    matrix a;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)scanf("%d",&a.c[i][j]);
    qmi(a,k);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j)cout<<a.c[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}