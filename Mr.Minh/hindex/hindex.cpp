#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "hindex"
const int maxn = (1 << 19) + 5;
using namespace std;

int n;
ll b, p[maxn], e[maxn], a[maxn], ans[maxn];
pair<ll, int> f[maxn];

bool check(int g){
    ll cnt = 0;
    fi(i, 1, n){
        if (a[i] >= g) e[i] = 0;
        else e[i] = (p[i] <= b / (g - a[i]) ? p[i] * (g - a[i]) : b + 1);
    }
    sort(e + 1, e + n + 1);
    fi(i, 1, g){
        cnt += e[i];
        if (cnt > b) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> b;
    fi(i, 1, n) cin >> a[i];
    fi(i, 1, n) cin >> p[i];
    int d = 1, c = n;
    while (d <= c){
        int g = (d + c) >> 1;
        if (check(g)) d = g+1;
        else c = g-1;
    }
    cout << c << '\n';
    fi(i, 1, n){
        if (a[i] >= c) f[i] = {0, i};
        else f[i] = {(p[i] <= b / (c - a[i]) ? p[i] * (c - a[i]) : b + 1), i};
    }
    sort(f + 1, f + n + 1);
    fi(i, 1, c) ans[f[i].second] = f[i].first / p[f[i].second];
    fi(i, 1, n) cout << ans[i] << ' ';
}
