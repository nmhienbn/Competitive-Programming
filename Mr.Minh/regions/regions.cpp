#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "regions"
const int maxn = 1e5+5;
using namespace std;

int n, m, scc, num[maxn], k;
ll res1, res2, tg, dem, cnt;
vector<int> g[maxn];

bool cl[maxn];
void dfs(int u){
    cl[u] = 1;
    num[scc]++;
    for (int v : g[u]) if (!cl[v]){
        dfs(v);
    }
}

void process(){
    cin >> n >> m >> k;
    fi(i, 1, m){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    fi(i, 1, n) if (!cl[i]){
        scc++;
        dfs(i);
        cnt += dem * num[scc];
        dem += num[scc];
    }
    cnt = 1ll*n*(n-1)/2 - m - cnt;
}

void do1(){
    res1 = scc;
    if (k >= scc-1) res1 = 1;
    else res1 -= k;
}

void do2(){
    res2 = scc;
    if (k <= cnt) return;
    k -= cnt;
    sort(num+1, num+scc+1, greater<int>());
    int tg = num[1];
    fi(i, 2, scc){
        k -= 1ll*num[i]*tg;
        tg += num[i];
        res2--;
        if (k <= 0) break;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    process();
    do1();
    do2();
    cout << res1 << ' ' << res2;
}
