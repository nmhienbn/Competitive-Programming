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

int n, t, par[maxn], cnt;
vector<int> g[maxn];

bool in_stack[maxn], flag;
void dfs(int u){
    in_stack[u] = 1;
    for (auto v : g[u]){
        if (in_stack[v]){
            flag = 1;
            break;
        }
        dfs(v);
    }
    in_stack[u] = 0;
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> t;
    while (t--){
        flag = 0;
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        dfs(u);
        if (flag){
            g[u].pop_back();
            cnt++;
        }
    }
    cout << cnt;
}
