#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define name "main"
#define maxn 1000005

using namespace std;

int res;
string s;
int next1[maxn][3];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s;
    int n=s.length();
    s='*'+s;
    f(j, 1, n){
        if (s[j] >= '0' && s[j] <= '9') s[j]='1';
        if (s[j] >= 'a' && s[j] <= 'z') s[j]='2';
        if (s[j] >= 'A' && s[j] <= 'Z') s[j]='3';
    }
    next1[n+1][1]=n+1;
    next1[n+1][2]=n+1;
    next1[n+1][3]=n+1;
    fd(i, n, 1){
        next1[i][1]=next1[i+1][1];
        next1[i][2]=next1[i+1][2];
        next1[i][3]=next1[i+1][3];
        if (s[i]=='1') next1[i][1]=i;
        if (s[i]=='2') next1[i][2]=i;
        if (s[i]=='3') next1[i][3]=i;
        if (i<=n-5) res+=n+1 - max(max(next1[i][1], next1[i][2]), max(next1[i][3], i+5));
    }
    cout << res;
}
