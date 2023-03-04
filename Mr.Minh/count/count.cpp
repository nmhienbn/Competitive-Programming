#include <bits/stdc++.h>
#define fi(i,a,b) for(int i=a; i<=b; i++)
#define fid(i,a,b) for(int i=a; i>=b; i--)
#define fir first
#define se second
#define bit(i,j) ((i>>j)&1)
#define bit2(i) (1<<(i-1))
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

#define maxn 200005
#define maxm 1000006
#define MOD
#define Seraphine "count"

using namespace std;

int n, a[maxn], num[maxn], id, b[maxn], res[maxn],
    pre[maxn], out[maxn], nex[maxn], bit[maxn];
vector<int> g[maxn];
vector<pii> t[maxn];

void dfs(int u){
    num[u] = ++id;
    for (auto v : g[u]){
        if (num[v]) continue;
        dfs(v);
    }
    out[u] = id;
    t[num[u]].pb({out[u], u});
}

void update(int x, int val){
    while (x <= n){
        bit[x] += val;
        x += x & -x;
    }
}

int get(int x){
    int ans = 0;
    while (x > 0){
        ans += bit[x];
        x -= x & -x;
    }
    return ans;
}

int main(){
    faster
    freopen(Seraphine".inp","r",stdin);
    freopen(Seraphine".out","w",stdout);
    cin >> n;
    fi(i, 1, n-1){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    fi(i, 1, n) cin >> a[i];
    dfs(1);
    fi(i, 1, n) b[num[i]] = a[i], pre[a[i]] = n+1;
    fid(i, n, 1){
        nex[i] = pre[b[i]];
        pre[b[i]] = i;
    }
    fi(i, 1, n) update(i, 1);
    fi(i, 1, n) update(nex[i], -1);
    fi(l, 1, n){
        if (l > 1){
            update(l-1, -1);
            update(nex[l-1], 1);
        }
        for (auto vt : t[l]){
            int i = vt.second, r = vt.first;
            res[i] = get(r) - get(l-1);
        }
    }
    fi(i, 1, n) cout << res[i] << ' ';
}
