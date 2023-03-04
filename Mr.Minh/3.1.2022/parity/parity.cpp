#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "parity"
#define all(v) v.begin(), v.end()
const int maxn = 10005;
using namespace std;

struct dl{
    int u, v, w;
} a[5005];

int k, n, m, f[maxn];
vector<int> val;
vector<pii> g[maxn];
queue<int> q;

void enter(){
    fi(i, 1, m){
        string c;
        int l, r, w;
        cin >> l >> r >> c;
        l--;
        w = (c[0] == 'o');
        a[i] = {l, r, w};
        val.pb(l);
        val.pb(r);
    }
    val.pb(-1);
    sort(all(val));
    val.resize(unique(all(val)) - val.begin());
    fi(i, 1, m){
        a[i].u = lower_bound(all(val), a[i].u) - val.begin();
        a[i].v = lower_bound(all(val), a[i].v) - val.begin();
    }
    n = val.size() - 1;
}

bool bfs(int st){
    while (q.size()) q.pop();
    q.push(st);
    while (q.size()){
        int u = q.front();
        q.pop();
        for (pii vt : g[u]){
            int v = vt.first, w = vt.second;
            if (f[v] == -1){
                f[v] = (f[u] ^ w);
                q.push(v);
            }
            else {
                if (f[v] != (f[u] ^ w)) return false;
            }
        }
    }
    return true;
}

bool check(int x){
    fi(i, 1, n) f[i] = -1, g[i].clear();
    fi(i, 1, x){
        g[a[i].u].pb({a[i].v, a[i].w});
        g[a[i].v].pb({a[i].u, a[i].w});
    }
    fi(i, 1, n) if (f[i] == -1){
        f[i] = 0;
        if (!bfs(i)) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> k >> m;
    enter();
    int d = 1, c = m;
    while (d <= c){
        int g = (d + c) >> 1;
        if (check(g)) d = g + 1;
        else c = g - 1;
    }
    cout << c;
}
