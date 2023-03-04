#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define maxn 20

using namespace std;

int n, a[maxn][maxn], kt[maxn]={0}, x[maxn], res=200000;

void tinh(){
    int sum=0;
    f(i, 1, n-1) sum+=a[x[i]][x[i+1]];
    if (sum<res) res=sum;
}

void backtrack(int i){
    f(j, 1, n) if (!kt[j]){
        kt[j]=1;
        x[i]=j;
        if (i==n) tinh(); else backtrack(i+1);
        kt[j]=0;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >>n;
    f(i, 1, n) f(j, 1, n) cin >>a[i][j];
    backtrack(1);
    cout << res;



}
