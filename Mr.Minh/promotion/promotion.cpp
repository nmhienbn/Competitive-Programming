#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "promotion"
const int maxn = 1005, maxm = 5005;
using namespace std;

struct dl {
    int u, v, w;
} E[maxm];

int n, m, a[maxn];
double d[maxn];

bool kt(dl e, double w){
    bool ret = d[e.u] + w*e.w - a[e.v] < d[e.v];
    if (ret) d[e.v] = d[e.u] + w*e.w - a[e.v];
    return ret;
}

bool check(double tb){
    bool stop;
    fi(i, 1, n) d[i] = 0;
    fi(i, 1, n-1){
        stop = 1;
        fi(j, 1, m){
            if (kt(E[j], tb)){
                stop = 0;
            }
        }
        if (stop) break;
    }
    fi(i, 1, m) if (kt(E[i], tb)) return 1;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, n) cin >> a[i];
    fi(i, 1, m){
        cin >> E[i].u >> E[i].v >> E[i].w;
    }
    double d = 0, c = 1e6, res = -1;
    while (c-d > 0.001){
        double g = (d + c) / 2;
        if (check(g)) res = g, d = g;
        else c = g;
    }
    if (res < 0 || res > 1e8) cout << 0;
    else cout << fixed << setprecision(2) << res;
}
