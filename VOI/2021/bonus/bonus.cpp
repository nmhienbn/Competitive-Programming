#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "bonus"
const int maxn = 3e5 + 5, maxl = 1e6 + 5, maxm = 1e5 + 5;
using namespace std;

int n, m, id;
int a[maxn], vt[maxn];
ll dp[maxn], res;
ll c[maxm], f[maxm];
string s;
vector<int> g[maxm], gg[maxm];

struct node{
    int child[26];
    ll val;
    int pre;
} T[maxl];

void add(string s, int i){
    int x = 0;
    for (char c : s){
        int now = c - 'A';
        if (!T[x].child[now]) T[x].child[now] = ++id, T[id].pre = x;
        x = T[x].child[now];
    }
    vt[i] = x;
}

void update(int x, ll val){
    while (x > 0){
        x = T[x].pre;
        T[x].val = max(T[x].val, val);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, n){
        cin >> s;
        add(s, i);
        cin >> a[i];
    }
    fi(i, 1, m){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    int qt = sqrt(m);
    fi(u, 1, 100000){
        for (int v : g[u]) if (g[v].size() >= qt){
            gg[u].pb(v);
        }
    }
    fi(i, 1, n){
        dp[i] = max(T[vt[i]].val, c[a[i]]) + a[i];
        for (int x : gg[a[i]]){
            dp[i] = max(dp[i], f[x] + a[i]);
        }
        update(vt[i], dp[i]);
        if (g[a[i]].size() < qt){
            for (int v : g[a[i]]){
                c[v] = max(c[v], dp[i]);
            }
        }
        else {
            f[a[i]] = max(f[a[i]], dp[i]);
        }
        res = max(res, dp[i]);
    }
    cout << res;
}
