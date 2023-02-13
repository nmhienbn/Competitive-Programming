#include <bits/stdc++.h>

using namespace std;
const int maxn = 1005;
int n, k;
vector<int> adj[maxn];
long long f[maxn][maxn][5];
int nEdge[maxn];
void DFS(int u, int p = -1) {
    f[u][0][0] = f[u][0][1] = 1; 
    for (int v : adj[u]) if (v != p) {
        DFS(v, u);
        for (int curEdge = nEdge[u]; curEdge >= 0; --curEdge)
            for (int vEdge = nEdge[v]; vEdge >= 0; --vEdge)
                for (int curNode = k; curNode >= 0; --curNode)
                    for (int vNode = 1; vNode + curNode <= k; ++vNode) {
                        int sumNode = curNode + vNode;
                        int sumEdge = curEdge + vEdge + (vNode < k);
                        f[u][sumEdge][sumNode] += f[u][curEdge][curNode] * f[v][vEdge][vNode];
                    }
        nEdge[u] += nEdge[v] + 1;
    }
}
int main() {
    freopen("COMNET.INP", "r", stdin);
#ifndef LDT
    freopen("COMNET.OUT", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b;
    cin >> n >> k >> a >> b;
    for (int i = 2; i <= n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1);
    long long ans = 0;
    for (int i = a; i <= b; ++i)
        ans += f[1][i][k];
    cout << ans;
    return 0;
}
1
