#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define maxn 20

using namespace std;

int n, k, s[maxn], x[maxn], kt[maxn]={0};
long long dem=0;

void backtrack(int i){
    f(j, 1, n) if (!kt[j] && abs(s[j]-s[x[i-1]])>k){
        kt[j]=1;
        x[i]=j;
        if (i==n) dem++; else backtrack(i+1);
        kt[j]=0;
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    f(i, 1, n) cin >> s[i];
    backtrack(1);
    cout << dem;
}
