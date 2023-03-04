#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define ll long long
#define Irelia "compseq"
const int maxn = 5005;
using namespace std;

int n, m, a[maxn], b[maxn], res;
int now[maxn], pa[maxn], pb[maxn];
int f[maxn][maxn], g[maxn][maxn];
pii val[maxn];

void nhap(int a[], int pre[], int n){
    fi(i, 1, n) cin >> a[i];
    fi(i, 1, n) val[i] = {a[i], i};
    sort(val + 1, val + n + 1);
    a[val[1].second] = 1;
    fi(i, 2, n){
        a[val[i].second] = a[val[i - 1].second];
        if (val[i].first != val[i - 1].first)
            a[val[i].second]++;
    }
    fi(i, 1, n) now[i] = 0;
    fi(i, 1, n){
        pre[i] = now[a[i]];
        now[a[i]] = i;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    nhap(a, pa, n);
    nhap(b, pb, m);
    fi(i, 1, n) fi(j, 1, m){
        int u = pa[i], v = pb[j];
        if (i - u == j - v && u && v)
            f[i][j] = f[u][v] + i - u;
        else
            f[i][j] = min(i - u, j - v);
    }
    fi(i, 1, n) fi(j, 1, m){
        g[i][j] = min(g[i - 1][j - 1] + 1, f[i][j]);
        res = max(res, g[i][j]);
    }
    cout << res;
}
