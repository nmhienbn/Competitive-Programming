#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "kamp"
const int maxn = 5e5 + 5;
using namespace std;

int n, k;
bool cl[maxn];
int child[maxn], dad[maxn];
vector<pii> g[maxn];
ll sUp[maxn], sDown[maxn];
ll fUp[maxn], fDown[maxn], tmp[maxn], id[maxn];

void dfs(int u, int p){
    if (cl[u]) child[u]++;
    for (pii vt : g[u]) if (vt.first != p){
        int v = vt.first;
        int w = vt.second;
        dfs(v, u);
        //sum
        sUp[u] += sUp[v];
        child[u] += child[v];
        if (child[v]) sUp[u] += w;
        //longest
        if (child[v]){
            if (fUp[v] + w > fUp[u]){
                id[u] = v;
                tmp[u] = fUp[u];
                fUp[u] = fUp[v] + w;
            }
            else if (fUp[v] + w > tmp[u]){
                tmp[u] = fUp[v] + w;
            }
        }
    }
    dad[u] = k - child[u];
}

void dfs2(int u, int p){
    for (pii vt : g[u]) if (vt.first != p){
        int v = vt.first;
        int w = vt.second;
        //sum
        sDown[v] = sDown[u] + sUp[u] - sUp[v] - w * (child[v] > 0);
        if (dad[v]) sDown[v] += w;
        //longest
        if (dad[v] > dad[u]){
            if (v == id[u]){
                if (child[u] > child[v]) fDown[v] = tmp[u] + w;
            }
            else {
                fDown[v] = fUp[u] + w;
            }
        }
        if (dad[u]){
            fDown[v] = max(fDown[v], fDown[u] + w);
        }
        //--------
        dfs2(v, u);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> k;
    fi(i, 1, n - 1){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    fi(i, 1, k){
        int x;
        cin >> x;
        cl[x] = 1;
    }
    dfs(1, 0);
    dfs2(1, 0);
//    fi(i, 1, n){
//        cout << fDown[i] << '\n';
//    }
//    cout << endl;
    fi(i, 1, n){
        cout << (sUp[i] + sDown[i]) * 2 - max(fUp[i], fDown[i]) << '\n';
    }
}
