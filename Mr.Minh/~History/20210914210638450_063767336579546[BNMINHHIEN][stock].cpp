#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "stock"
const int maxn = 240;

using namespace std;

int n, t, cnt;
vector<int> g[maxn];

bool cl[maxn];
int q[maxn], d, c;
bool bfs(int bd){
    d = 0, c = 0;
    fi(i, 1, n) cl[i] = 0;
    q[++c] = bd;
    cl[bd] = 1;
    while (d <= c){
        int u = q[++d];
        for (auto v : g[u]){
            if (v == bd) return 1;
            if (cl[v]) continue;
            cl[v] = 1;
            q[++c] = v;
        }
    }
    return 0;
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> t;
    while (t--){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        bool kq = bfs(u);
        if (kq){
            g[u].pop_back();
            cnt++;
        }
    }
    cout << cnt;
}
