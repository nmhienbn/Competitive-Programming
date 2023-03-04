#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "robots"
const int maxn = 1e5+5;
using namespace std;

int n, l[maxn], maxl[maxn];
pii a[maxn];

bool cmp(pii a, pii b){
    return a.second == b.second ? a.first > b.first : a.second < b.second;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        int u, v;
        cin >> u >> v;
        a[i] = {u-v, u+v};
    }
    sort(a+1, a+n+1, cmp);
    fi(i, 1, n){
        int d = 1, c = i-1;
        while (d <= c){
            int g = (d + c) >> 1;
            if (a[g].second <= a[i].first) d = g+1;
            else c = g-1;
        }
        l[i] = maxl[c] + 1;
        maxl[i] = max(l[i], maxl[i-1]);
    }
    cout << maxl[n];
}
