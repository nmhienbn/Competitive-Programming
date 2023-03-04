#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "lift"
const int maxn = 5005, INF = 1e9;
using namespace std;

struct edge {
    int u, v;
    int other(const int& x){
        return u ^ v ^ x;
    }
};

int n, m, f[maxn], pre[maxn], b[maxn], cnt;
edge a[maxn * 2];
vector<int> g[maxn];
priority_queue<pii, vector<pii>, greater<pii>> q;

void Dijkstra(int st){
    fi(i, 1, n) f[i] = INF;
    f[st] = 0;
    q.push({0, st});
    while (q.size()){
        int u = q.top().second;
        if (f[u] < q.top().first){
            q.pop();
            continue;
        }
        q.pop();
        for (int i : g[u]){
            int v = a[i].other(u);
            if (f[v] > f[u] + abs(u - v)){
                f[v] = f[u] + abs(u - v);
                pre[v] = i;
                q.push({f[v], v});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, m){
        int u, v;
        cin >> u >> v;
        a[i] = {u, v};
        g[u].pb(i);
        g[v].pb(i);
    }
    Dijkstra(1);
    cout << f[n] * 5 << '\n';
    while (n > 1){
        b[++cnt] = pre[n];
        n = a[pre[n]].other(n);
    }
    cout << cnt << '\n';
    fid(i, cnt, 1) cout << b[i] << ' ';
}
