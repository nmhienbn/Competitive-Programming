#include <bits/stdc++.h>
#define fi(i,a,b) for(int i=a;i<=b;++i)
#define fid(i,a,b) for(int i=a;i>=b;--i)
#define pp pair<int, int>
#define ll long long
#define name "callfood"
#define maxn 500005

using namespace std;

int n, res = 1e9;
ll L[maxn];
pp a[maxn]; //first la ai, second la bi

bool cmp(pp x, pp y){
    return x.second < y.second;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i].first >> a[i].second;
    sort(a+1, a+n+1, cmp);
    fi(i, 1, n) L[i] = 1e18;
    fi(i, 1, n){
        res = min(res, a[i].first);
        L[1] = a[i].first;
        int t = 2;
        for (int j = 1; j <= n && j != i; j++){
            L[t] = min(L[t], L[t-1] + a[j].second);
            t++;
        }
    }
    L[1] = res;
    fi(i, 1, n) cout << L[i] << '\n';
}
