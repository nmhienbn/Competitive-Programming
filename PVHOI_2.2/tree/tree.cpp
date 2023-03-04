#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "tree"
const int maxn = 4040, maxm = 1e6 + 5;
using namespace std;

int sub, n, nt, q;
bool flag;
bitset<maxn> path[maxn];
vector<int> g[maxn];

void dfs(int u, int p, int kt, int i){
    for (auto v : g[u]) if (v != p){
        if (v == kt) flag = 1;
        if (!flag) dfs(v, u, kt, i);
        if (flag){
            path[i][v] = 1;
            return;
        }
    }
}

bool query(){
    cin >> q;
    fi(i, 1, q){
        int u, v;
        cin >> u >> v;
        path[i].reset();
        path[i][u] = 1;
        flag = 0;
        dfs(u, 0, v, i);
    }
    fi(i, 1, q) fi(j, i + 1, q){
        if ((path[i] & path[j]).count() == 0) continue;
        if ((path[i] & path[j]) == path[i]) continue;
        if ((path[i] & path[j]) == path[j]) continue;
        return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> sub >> n;
    if (n > maxn) exit(0);
    fi(i, 1, n-1){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cin >> nt;
    while (nt--){
        if (query()) cout << "RO RANG\n";
        else cout << "MAP MO\n";
    }
}
