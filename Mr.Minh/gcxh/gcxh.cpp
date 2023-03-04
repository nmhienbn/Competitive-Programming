    #include <bits/stdc++.h>
    #define fi(i, a, b) for(int i = a; i <= b; i++)
    #define fid(i, a, b) for(int i = a; i >= b; i--)
    #define pii pair<int,int>
    #define pb push_back
    #define ll long long
    #define faster ios_base::sync_with_stdio(0); cin.tie(NULL);
    #define NunuAndWillump "pvhoi20b4gcxh"
    const int maxn = 3e5+5, mod = 998244353;

    using namespace std;

    struct dl{
        int u, v;
        bool used;

        int other(int x){
            return u^v^x;
        }
    };

    int sub, n, m, num[maxn], low[maxn], id,
        con[maxn], scc, num_scc[maxn], cnt[maxn];
    vector<int> g[maxn], child[maxn];
    dl E[maxn];

    void dfs(int u, int par){
        num_scc[u] = scc;
        cnt[scc]++;
        if (par != -1) child[u].pb(par);
        con[u] = 1;
        num[u] = ++id;
        low[u] = n+1;
        for (int v : g[u]) if (v != par){
            if (num[v]){
                low[u] = min(low[u], num[v]);
            }
            else {
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] >= num[u]) child[u].pb(v);
                con[u] += con[v];
            }
        }
    }

    int main(){
        //faster
        freopen(NunuAndWillump".inp", "r", stdin);
        freopen(NunuAndWillump".out", "w", stdout);
        scanf("%d %d %d", &sub, &n, &m);
        fi(i, 1, m){
            int u, v;
            scanf("%d %d", &u, &v);
            E[i] = {u, v, 0};
            g[u].pb(v);
            g[v].pb(u);
        }
        fi(i, 1, n) if (!num[i]){
            scc++;
            dfs(i, -1);
        }
        ll bd = 0, sum = 0;
        fi(i, 1, scc){
            bd = (bd + sum*cnt[i]) % mod;
            sum = (sum + cnt[i]) % mod;
        }
        fi(u, 1, n){
            if (child[u].size() >= 2){
                ll res = bd - n + cnt[num_scc[u]];
                int dem = 0;
                for (int i = 1; i < int(child[u].size()); i++){
                    int v = child[u][i];
                    res = (res + 1ll*dem*con[v]) % mod;
                    dem += con[v];
                }
                res = (res + 1ll*(cnt[num_scc[u]]-1-dem)*dem) % mod;
                printf("%lld ", res);
            }
            else printf("%lld ", bd - n + cnt[num_scc[u]]);
        }
        printf("\n");
        fi(i, 1, m){
            int u = E[i].u, v = E[i].v;
            if (num[u] > num[v]) swap(u, v);
            if (low[v] <= num[u]) cout << bd << ' ';
            else {
                printf("%lld ", (1ll*con[v]*(cnt[num_scc[v]]-con[v]) + bd) % mod);
            }
        }
    }
