#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL);
#define NunuAndWillump "gcdpath"
const int maxn = 3e5 + 5, maxm = 15e5;

using namespace std;

int n, a[maxn], sub, lab[maxn], maxa, num[maxn];
ll cnt[maxm+5], res;
vector<pii> g[maxm+5];

int find(int u){
    return lab[u] < 0 ? u : lab[u] = find(lab[u]);
}

ll getNumPath(int i){
    int id = 0;
    for (int j = i; j <= maxa; j += i){
        for (pii it : g[j]){
            if (num[it.first] < 0) num[it.first] = ++id;
            if (num[it.second] < 0) num[it.second] = ++id;
        }
    }
    if (id == 0) return 0;

    ll ans = 0;
    for (int j = i; j <= maxa; j += i){
        for (pii it : g[j]){
            int u = find(num[it.first]);
            int v = find(num[it.second]);
            ans += 1ll * lab[u] * lab[v];
            if (lab[u] > lab[v]) swap(u, v);
            lab[u] += lab[v];
            lab[v] = u;
        }
    }
    fi(i, 1, id) lab[i] = -1;
    for (int j = i; j <= maxa; j += i){
        for (pii it : g[j]){
            num[it.first] = num[it.second] = -1;
        }
    }
    return ans;
}

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> sub >> n;
    fi(i, 1, n) cin >> a[i];
    fi(i, 1, n-1){
        int u, v, w;
        cin >> u >> v;
        w = __gcd(a[u], a[v]);
        g[w].pb({u, v});
        maxa = max(maxa, w);
    }
    memset(lab, -1, sizeof lab);
    memset(num, -1, sizeof num);
    cnt[1] = 1ll * n * (n-1) / 2;
    fi(i, 2, maxa){
        cnt[i] = getNumPath(i);
    }
    fid(i, maxa, 1){
        for (int j = 2 * i; j <= maxa; j += i){
            cnt[i] -= cnt[j];
        }
    }
    fi(i, 1, maxa) res += 1ll * i * cnt[i];
    cout << res;
}
