#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "qbtrans"
const int maxn = 105, maxm = 9005;
using namespace std;

struct dl {
    int u, v, w;
} E[maxm];

int n, m;
double d[maxn];

bool kt(dl e, double w){
    bool ret = d[e.u] + e.w - w < d[e.v];
    if (ret) d[e.v] = d[e.u] + e.w - w;
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
    fi(i, 1, m){
        cin >> E[i].u >> E[i].v >> E[i].w;
    }
    double d = 0, c = 1e9, res = -1;
    while (c-d > 0.0001){
        double g = (d + c) / 2;
        if (check(g)) res = g, c = g;
        else d = g;
    }
    if (res < 0 || res > 1e8) cout << -1;
    else cout << fixed << setprecision(2) << res;
}
