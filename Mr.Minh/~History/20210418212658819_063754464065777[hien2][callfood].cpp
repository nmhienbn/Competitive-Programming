#include <bits/stdc++.h>
#define fi(i,a,b) for(int i=a;i<=b;++i)
#define fid(i,a,b) for(int i=a;i>=b;--i)
#define pp pair<int, int>
#define ll long long
#define name "callfood"
#define maxn 500005

using namespace std;

int n, minab[maxn], mina[maxn];
ll S[maxn];
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
    minab[0] = 1e9;
    fi(i, 1, n) {
        S[i] = S[i-1] + a[i].second;
        minab[i] = min(minab[i-1], a[i].first - a[i].second);
    }
    mina[n] = a[n].first;
    fid(i, n-1, 1) mina[i] = min(mina[i+1], a[i].first);
    fi(i, 1, n){
        S[i] = min(S[i] + minab[i], S[i-1] + mina[i]);
    }
    fi(i, 1, n) cout << S[i] << '\n';
}
