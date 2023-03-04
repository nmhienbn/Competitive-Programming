#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define file freopen(Ahri".inp", "r", stdin); freopen(Ahri".out", "w", stdout);
#define Ahri ""
using namespace std;

int n, m;
vector<int> ke[100000];

void dfs(int u, vector<bool> &visited) {
    visited[u] = true;
    for (int v: ke[u]) if (!visited[v]) dfs(v, visited);
}

int count_ccs() {
    int c = 0;
    vector<bool> v(n, false);
    for (int i=0; i<n; i++) if (!v[i]) dfs(i, v), c++;
    return c;
}

int dfs1(int i, vector<int>& idx, vector<int> &low, vector<int> &trace, int &index, ll &res, int &nBridge) {
    int nChild = 0;
    index += 1;
    idx[i] = low[i] = index;
    for (int j: ke[i]) {
        if (!idx[j]) {
            trace[j] = i;
            int nChildJ = dfs1(j, idx, low, trace, index, res, nBridge);
            nChild += nChildJ;
            low[i] = min(low[i], low[j]);
            if (low[j] > idx[i]) {
                nBridge++;
                res += (ll)nChildJ * (ll)(n-nChildJ) - 1ll;
            }
        } else if (j != trace[i]) low[i] = min(low[i], idx[j]);
    }
    return nChild + 1;
}

void solve1() {
    int index = 0, nBridge = 0;
    ll res = 0;
    vector<int> idx(n, 0), low(n, 0), trace(n, 0);
    dfs1(0, idx, low, trace, index, res, nBridge);
    res += (ll)(m-nBridge) * ((ll)n * (ll)(n-1) / 2ll - (ll)m);
    cout << res;
}

void dfs2(int i, vector<int>& idx, vector<int> &low, vector<int> &trace, int &index, int &num_bridge) {
    index += 1;
    idx[i] = low[i] = index;
    for (int j: ke[i]) {
        if (!idx[j]) {
            trace[j] = i;
            dfs2(j, idx, low, trace, index, num_bridge);
            low[i] = min(low[i], low[j]);
            if (low[j] > idx[i]) num_bridge++;
        } else if (j != trace[i]) low[i] = min(low[i], idx[j]);
    }
}

void solve2() {
    int index = 0, nBridge = 0;
    vector<int> idx(n, 0), low(n, 0), trace(n, 0);
    dfs2(0, idx, low, trace, index, nBridge);
    int c1 = index;
    for (int i=0; i<n; i++) if (!idx[i]) {
        dfs2(i, idx, low, trace, index, nBridge);
        break;
    }
    ll res = (ll)(m-nBridge) * (ll)c1 * (ll)(n-c1);
    cout << res;
}


int main() {
    faster
    cin >> n >> m;
    fi(i, 0, m-1){
        int u, v;
        cin >> u >> v;
        u--, v--;
        ke[u].push_back(v);
        ke[v].push_back(u);
    }

    int num_ccs = count_ccs();
    if (num_ccs > 2) cout << 0;
    else if (num_ccs == 2) solve2();
    else solve1();
    return 0;
}
