#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "costquery"
const int maxn = 1e5+5;

using namespace std;

struct dl {
    int u, v, w;
    bool operator < (const dl& x) const {
        return w < x.w;
    }
} E[maxn];

int n, q;
ll a[maxn];
int lab[maxn];

int get_root(int u){
    return lab[u] < 0 ? u : lab[u] = get_root(lab[u]);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> q;
    fi(i, 1, n-1){
        cin >> E[i].u >> E[i].v >> E[i].w;
    }
    sort(E+1, E+n);
    memset(lab, -1, sizeof(lab));
    fi(i, 1, n-1){
        int u = get_root(E[i].u), v = get_root(E[i].v);
        a[i] = 1ll * lab[u] * lab[v];
        if (lab[u] > lab[v]) swap(u, v);
        lab[u] += lab[v];
        lab[v] = u;
        a[i] += a[i-1];
    }
    while (q--){
        int l, r;
        cin >> l >> r;
        int d = 1, c = n-1;
        while (d <= c){
            int g = (d + c) >> 1;
            if (E[g].w < l) d = g + 1;
            else c = g - 1;
        }
        int pos1 = c;
        d = 1, c = n-1;
        while (d <= c){
            int g = (d + c) >> 1;
            if (E[g].w <= r) d = g + 1;
            else c = g - 1;
        }
        int pos2 = c;
        cout << a[pos2] - a[pos1] << ' ';
    }
}
