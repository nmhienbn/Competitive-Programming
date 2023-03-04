#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "rselect"
const int maxn = 1005, maxm = 1e6 + 5;
using namespace std;

int n, a[maxn][maxn], res;
int vt[maxn][maxn], id, cnt[maxm];
int lab[maxm];
vector<pii> g[maxm];
int st[maxm * 4], top;

int get(int u){
    while (lab[u] > 0)
        u = lab[u];
    return u;
}

void unify(int u, int v){
    int p = get(u);
    int q = get(v);
    st[++top] = p;
    st[++top] = q;
    if (p == q) return;
    if (lab[p] < lab[q]) swap(p, q);
    lab[q] += lab[p];
    lab[p] = q;
    res = max(res, -lab[q]);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) fi(j, 1, n){
        cin >> a[i][j];
        vt[i][j] = ++id;
    }
    fi(i, 1, n) fi(j, 1, n - 1){
        int w = abs(a[i][j] - a[i][j + 1]);
        g[w].pb({vt[i][j], vt[i][j + 1]});
    }
    fi(i, 1, n - 1) fi(j, 1, n){
        int w = abs(a[i][j] - a[i + 1][j]);
        g[w].pb({vt[i][j], vt[i + 1][j]});
    }
    fi(i, 1, n * n) lab[i] = -1;
    fi(i, 0, 1e6){
        for (pii x : g[i]){
            unify(x.first, x.second);
        }
        while (top > 0){
            lab[st[top--]] = -1;
        }
    }
    cout << res;
}
