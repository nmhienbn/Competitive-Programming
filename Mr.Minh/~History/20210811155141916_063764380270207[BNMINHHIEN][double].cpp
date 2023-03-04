#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "double"
const int maxn = 5e4+5, maxx = 1e5+5;

using namespace std;

int n, c[maxn], d[maxn], par[maxn], L[maxn], cnt, cnt2, res;
vector<pii> g[maxn];

void dfs(int u){
    cnt++;
    for (auto vt : g[u]){
        int v = vt.first, w = vt.second;
        if (par[v]) continue;
        par[v] = u;
        L[v] = (L[u]+w)&1;
        dfs(v);
    }
    cnt2 += L[u];
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        int x;
        cin >> x;
        if (c[x]){
            g[i].pb({c[x], 1});
            g[c[x]].pb({i, 1});
        }
        else {
            c[x] = i;
        }
    }
    fi(i, 1, n){
        int x;
        cin >> x;
        if (d[x]){
            g[i].pb({d[x], 1});
            g[d[x]].pb({i, 1});
        }
        else {
            d[x] = i;
        }
    }
    fi(i, 1, 1e5){
        if (c[i] && d[i]){
            g[c[i]].pb({d[i], 0});
            g[d[i]].pb({c[i], 0});
        }
    }
    fi(u, 1, n){
        if (!par[u]){
            par[u] = -1;
            cnt = cnt2 = 0;
            dfs(u);
            res += min(cnt2, cnt-cnt2);
        }
    }
    cout << res;
}
