#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "stacks"
const int maxn = 3e5 + 5;
using namespace std;

int n, pos[maxn], b[maxn][20], h[maxn];
vector<int> g[maxn];

int lca(int u, int v){
    if (h[u] < h[v]) swap(u, v);
    int d = h[u] - h[v];
    fid(i, 18, 0) if (gb(d, i)){
        u = b[u][i];
    }
    if (u == v) return u;
    fid(i, 17, 0) if (b[u][i] != b[v][i]){
        u = b[u][i];
        v = b[v][i];
    }
    return b[u][0];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        char typ;
        int v;
        cin >> typ >> v;
        v = pos[v];
        if (typ == 'a'){
            pos[i] = i;
            b[i][0] = v;
            fi(j, 1, 18) b[i][j] = b[b[i][j - 1]][j - 1];
            h[i] = h[v] + 1;
        }
        else if (typ == 'b'){
            pos[i] = b[v][0];
            cout << v << '\n';
        }
        else {
            pos[i] = v;
            int w;
            cin >> w;
            w = pos[w];
            cout << h[lca(v, w)] << '\n';
        }
    }

}
