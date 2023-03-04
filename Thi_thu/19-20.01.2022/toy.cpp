#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "toy"
const int maxn = 5e5 + 5;
using namespace std;

int n;
pii a[maxn];
int ff[1 << 20], gg[1 << 20], res;
int f[maxn], g[maxn];

void sub1(){
    int u = (1 << n) - 1;
    fi(x, 1, u){
        int m = 1e8, M = 0;
        fi(i, 1, n) if (gb(x, i - 1)){
            m = min(m, a[i].first);
            M = max(M, a[i].first);
        }
        ff[x] = M - m;
    }
    fi(x, 1, u){
        int m = 1e8, M = 0;
        fi(i, 1, n) if (gb(x, i - 1)){
            m = min(m, a[i].second);
            M = max(M, a[i].second);
        }
        gg[x] = M - m;
    }
    res = 1e9;
    fi(x, 1, u){
        res = min(res, ff[x] + gg[u - x]);
    }
    cout << res;
    exit(0);
}

void sub2(){
    sort(a + 1, a + n + 1);
    f[n + 1] = 1e8;
    g[n + 1] = 0;
    fid(i, n, 1){
        f[i] = min(f[i + 1], a[i].second);
        g[i] = max(g[i + 1], a[i].second);
    }
    int m = 1e8, M = 0;
    res = 1e9;
    fi(i, 1, n){
        fid(j, n, i) if (j - i + 1 < n){
            res = min(res, a[j].first - a[i].first
                      + max(M, g[j + 1]) - min(m, f[j + 1]));
        }
        m = min(m, a[i].second);
        M = max(M, a[i].second);
    }
    cout << res;
    exit(0);
}

void sub3(){
    sort(a + 1, a + n + 1);
    f[n + 1] = 1e8;
    g[n + 1] = 0;
    fid(i, n, 1){
        f[i] = min(f[i + 1], a[i].second);
        g[i] = max(g[i + 1], a[i].second);
    }
    int m = 1e8, M = 0;
    res = 1e9;
    srand(time(NULL));
    fi(i, 1, n){
        fi(rep, 1, 5 * log2(n - i + 1)){
            int j = i + (1ll * rand() * rand() % (n - i + 1));
            res = min(res, a[j].first - a[i].first
                      + max(M, g[j + 1]) - min(m, f[j + 1]));
        }
        m = min(m, a[i].second);
        M = max(M, a[i].second);
    }
    cout << res;
    exit(0);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i].first >> a[i].second;
    if (n <= 20) sub1();
    if (n <= 2000) sub2();
    sub3();
}
