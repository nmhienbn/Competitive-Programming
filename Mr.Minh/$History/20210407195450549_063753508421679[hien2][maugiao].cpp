#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define maxn 25

using namespace std;

int n, a[maxn][maxn], maxi=0, dem=0, x[maxn], kt[maxn]={0};

void tinh(){
    int sum=0;
    f(i, 1, n) sum+=a[i][x[i]];
    if (sum==maxi) {dem++;}
    if (sum>maxi) {maxi=sum; dem=1;}
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
    cin >> n;
    f(i, 1, n) f(j, 1, n) cin >> a[i][j];
    backtrack(1);
    cout << maxi << ' ' << dem;

}
