#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define NunuAndWillump "pvhoi20b5tree"
const int maxn = 1e6+5;

using namespace std;

int n, k, mod, con[maxn], child[maxn], mu3;
ll gt[maxn], res, gt1[4][1000], L[maxn], mu1[4];
int mu2[1000][1000];
vector<int> g[maxn], getK[1000];
int p[4] = {19, 127, 467, 907};

ll mu(ll a, int n, int mod) {
    ll res = 1;
    while (n > 0) {
        if (n % 2 != 0) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        n /= 2;
    }
    return res;
}

ll C(int n, int k, int mod, ll gt[]){
    if (k > n) return 0;
    return ((gt[n] * mu2[mod][k]) % mod) * (mu(gt[n-k], mod-2, mod)) % mod;
}

ll C(int n, int k, int mod){
    if (k > n) return 0;
    return ((gt[n] * mu3) % mod) * (mu(gt[n-k], mod-2, mod)) % mod;
}

vector<int> getRepresentation(int N, int p) {
    vector<int> res;
    while (N > 0) {
        res.push_back(N % p);
        N /= p;
    }
    return res;
}

ll Cp(int n, int k, int p, ll gt[]){
    if (n < k) return 0;
    vector<int> N = getRepresentation(n, p);
    vector<int> K = getK[p];
    ll res = 1;
    for (int i = 0; i < int(K.size()); ++i) {
        res = (res * C(N[i], K[i], p, gt)) % p;
    }
    return res;
}

ll Cm(int n, int k){
    if (L[n] != -1) return L[n];
    ll res = 0;
    fi(i, 0, 3){
        ll tmp = Cp(n, k, p[i], gt1[i]);
        res = (res + tmp*mu1[i]) % mod;
    }
    L[n] = res;
    return res;
}

bool cl[maxn];
void dfs(int u){
    cl[u] = 1;
    con[u] = 1;
    for (int v : g[u]){
        if (cl[v]) continue;
        dfs(v);
        con[u] += con[v];
        child[u] = (child[u] + C(con[v], k, mod)) % mod;
    }
    child[u] = (child[u] + C(n-con[u], k, mod)) % mod;
}
void dfs2(int u){
    cl[u] = 1;
    con[u] = 1;
    for (int v : g[u]){
        if (cl[v]) continue;
        dfs2(v);
        con[u] += con[v];
        child[u] = (child[u] + Cm(con[v], k)) % mod;
    }
    child[u] = (child[u] + Cm(n-con[u], k)) % mod;
}

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> n >> k >> mod;
    gt[0] = 1;
    fi(i, 1, n-1){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    if (mod == 1019972207){
        fi(i, 1, n) gt[i] = (gt[i-1] * i) % mod;
        mu3 = mu(gt[k], mod-2, mod);
        dfs(1);
        res = C(n-1, k, mod)*n % mod;
    }
    else {
        fi(i, 0, 3){
            gt1[i][0] = 1;
            fi(j, 1, p[i]-1){
                gt1[i][j] = (gt1[i][j-1] * j) % p[i];
            }
        }
        fi(i, k, n) L[i] = -1;
        fi(i, 0, 3){
            getK[p[i]] = getRepresentation(k, p[i]);
            mu1[i] = mu(mod/p[i], p[i]-2, p[i]) * (mod/p[i]) % mod;
        }
        fi(i, 0, 3){
            fi(j, 0, p[i]-1){
                mu2[p[i]][j] = mu(gt1[i][j], p[i]-2, p[i]);
            }
        }
        dfs2(1);
        res = Cm(n-1, k)*n % mod;
    }
    fi(i, 1, n){
        res = (res - child[i] + mod) % mod;
    }
    cout << res;
}
