#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 5;
struct TPoint{
    int x, y, u, v;
} rec[maxn];
struct TData {
    int val, typ, id;
    bool operator < (TData &other) {
        return val < other.val || (val == other.val && typ < other.typ);
    }
};
int n;
vector<TData> adjX[maxn << 1], adjY[maxn << 1];
set<int> adj[maxn];
int res;
int num[maxn], low[maxn], cnt, nChild[maxn];
vector<int> br;
void DFS(int u, int p = -1) {
    num[u] = low[u] = ++cnt;
    nChild[u] = 1;
    for (int v : adj[u]) {
        if (v == p) continue;
        if (num[v])
            low[u] = min(low[u], num[v]);
        else {
            DFS(v, u);
            nChild[u] += nChild[v];
            low[u] = min(low[u], low[v]);
            if (low[v] >= num[v]) {
                br.push_back(v);
            }
        }
    }
}
int main() {
#ifdef LDT
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    freopen("BUILDING.INP", "r", stdin);
    freopen("BUILDING.OUT", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vector<int> X, Y;
    for (int i = 1; i <= n; ++i) {
        int x, y, p, q;
        cin >> x >> y >> p >> q;
        swap(y, q);
        assert(x < p);
        assert(y < q);
        rec[i] = {x, y, p, q};
        X.push_back(x);
        X.push_back(p);
        Y.push_back(y);
        Y.push_back(q);
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    X.erase(unique(X.begin(), X.end()), X.end());
    Y.erase(unique(Y.begin(), Y.end()), Y.end());
    for (int i = 1; i <= n; ++i) {
        rec[i].x = lower_bound(X.begin(), X.end(), rec[i].x) - X.begin();
        rec[i].u = lower_bound(X.begin(), X.end(), rec[i].u) - X.begin();
        rec[i].y = lower_bound(Y.begin(), Y.end(), rec[i].y) - Y.begin();
        rec[i].v = lower_bound(Y.begin(), Y.end(), rec[i].v) - Y.begin();
        //cout << rec[i].x << ' ' << rec[i].y << ' ' << rec[i].u << ' ' << rec[i].v << endl;
        adjX[rec[i].x].push_back({rec[i].y, -1, i});
        adjX[rec[i].x].push_back({rec[i].v, 1, i});
        adjX[rec[i].u].push_back({rec[i].y, -1, i});
        adjX[rec[i].u].push_back({rec[i].v, 1, i});
        adjY[rec[i].y].push_back({rec[i].x, -1, i});
        adjY[rec[i].y].push_back({rec[i].u, 1, i});
        adjY[rec[i].v].push_back({rec[i].x, -1, i});
        adjY[rec[i].v].push_back({rec[i].u, 1, i});
    }
    vector<pair<int, int> > E;
    for (int i = 0; i < X.size(); ++i) {
        set<int> myset;
        sort(adjX[i].begin(), adjX[i].end());
        for (auto &cur : adjX[i]) {
            if (cur.typ == 1) myset.erase(cur.id);
            else {
                for (int id : myset)
                    E.push_back({min(id, cur.id), max(id, cur.id)});
                myset.insert(cur.id);
            }
        }
    }
    for (int i = 0; i < Y.size(); ++i) {
        set<int> myset;
        sort(adjY[i].begin(), adjY[i].end());
        for (auto &cur : adjY[i]) {
            if (cur.typ == 1) myset.erase(cur.id);
            else {
                for (int id : myset)
                    E.push_back({min(id, cur.id), max(id, cur.id)});
                myset.insert(cur.id);
            }
        }
    }
    sort(E.begin(), E.end());
    E.erase(unique(E.begin(), E.end()), E.end());
    for (auto x : E) {
        int u = x.first, v = x.second;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    res = 1e9;
    for (int i = 1; i <= n; ++i)
        if (num[i] == 0) {
            br.clear();
            DFS(i);
            for (int v : br)
                res = min(res, abs(nChild[v] - (nChild[i] - nChild[v])));
        }
    if (res > n) res = -1;
    cout << res;
    return 0;
}
1
