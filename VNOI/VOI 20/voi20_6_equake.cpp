#include <bits/stdc++.h>

using namespace std;
const int maxn = 3005;
long long f[maxn][maxn], INF, sum[maxn], p[maxn];
int n_child[maxn], cost_to_par[maxn];
int n, c, lim, ppl_per_node;
vector<pair<int, int> > adj[maxn];
//for trace
long long need[maxn];
int save[maxn][maxn];
vector<pair<int, long long> > moves[maxn];
bool done[maxn];
void DFS(int u, int par) {
    f[u][0] = 0;
    f[u][1] = 0;
    n_child[u] = 1;
    for (auto [v, w] : adj[u]) {
        if (v == par) continue;
        cost_to_par[v] = w;
        DFS(v, u);
        for (int j = n_child[u] + n_child[v]; j >= 0; --j) {
            f[u][j] += f[v][0];
            save[v][j] = j;
            for (int k = min(j - 1, n_child[u]); k >= 0 && j - k <= n_child[v]; --k) {
                if (f[u][j] > f[u][k] + f[v][j - k]) {
                    f[u][j] = f[u][k] + f[v][j - k];
                    save[v][j] = k;
                }
            }
        }
        n_child[u] += n_child[v];
        sum[u] += sum[v];
    }
    sum[u] += p[u];
    for (int i = 0; i <= n_child[u]; ++i) {
        long long number_ppl_need_to_move = abs(sum[u] - 1ll * ppl_per_node * n_child[u] - i);
        //(a + c - 1) / c = ceil(a/c)
        f[u][i] += (number_ppl_need_to_move + c - 1) / c * cost_to_par[u];
    }
}
int get_step(int u, int k, int par) {
    done[u] = 1;
    long long number_ppl_need_to_move = sum[u] - 1ll * ppl_per_node * n_child[u] - k;
    int res = 0;
    if (number_ppl_need_to_move < 0) {
        need[par] -= number_ppl_need_to_move;
        res += 1;
        moves[par].push_back({u, -number_ppl_need_to_move});
    }
    else if (number_ppl_need_to_move > 0) {
        need[u] += number_ppl_need_to_move;
        res += 1;
        moves[u].push_back({par, number_ppl_need_to_move});
    }
    reverse(adj[u].begin(), adj[u].end());
    while (true) {
        int v = -1;
        for (auto [vv, w] : adj[u])
            if (save[vv][k] != -1 && !done[vv]) {
                v = vv;
                break;
            }
        if (v == -1) break;
        int nxt = save[v][k];
        res += get_step(v, k - nxt, u);
        k = nxt;
    }
    for (auto [v, w] : adj[u]) if (!done[v]) 
        res += get_step(v, 0, u);
    return res;
}
void trace() {
    queue<int> q;
    for (int i = 1; i <= n; ++i) if (p[i] >= need[i] && need[i]) {
        q.push(i);
        need[i] = 0;
    }
    while (q.size()) {
        int u = q.front(); q.pop();
        for (auto [v, ppl] : moves[u]) {
            p[v] += ppl;
            p[u] -= ppl;
            cout << u << ' ' << v << ' ' << ppl << '\n';
            if (p[v] >= need[v] && need[v]) {
                q.push(v);
                need[v] = 0;
            }
        }
    }
}
int main() {
#ifdef LDT
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    freopen("EQUAKE.INP", "r", stdin);
    freopen("EQUAKE.OUT", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> c;
    long long S = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        S += p[i];
    }
    for (int i = 2; i <= n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    lim = S % n;
    ppl_per_node = S / n;
    memset(f, 63, sizeof(f));
    memset(save, 255, sizeof(save));
    INF = f[0][0];
    DFS(1, 0);
    cout << f[1][lim] << '\n';
    cout << get_step(1, lim, 0) << '\n';
    trace();
    return 0;
}
1
