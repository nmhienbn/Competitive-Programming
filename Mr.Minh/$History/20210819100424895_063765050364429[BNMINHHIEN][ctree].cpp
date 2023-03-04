#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define file freopen(Ahri".inp", "r", stdin); freopen(Ahri".out", "w", stdout);
#define Ahri "ctree"
const int maxn = 1e5+5;

using namespace std;

int n, l[maxn], d1[maxn], d2[maxn], c1, c2, now = 1e9;
vector<int> g[maxn], res;

void dfs(int u, int l[], int& ans){
    for (auto v : g[u]){
        if (!l[v]){
            l[v] = l[u] + 1;
            dfs(v, l, ans);
        }
    }
    if (l[u] > l[ans]) ans = u;
}

int main(){
    faster file
    cin >> n;
    fi(i, 2, n){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1, l, c1);
    dfs(c1, d1, c2);
    dfs(c2, d2, l[1]);
    fi(i, 1, n){
        if (max(d1[i], d2[i]) < now){
            now = max(d1[i], d2[i]);
            res.clear();
            res.pb(i);
        }
        else if (max(d1[i], d2[i]) == now){
            res.pb(i);
        }
    }
    sort(res.begin(), res.end());
    cout << res.size() << '\n';
    for (auto i : res) cout << i << ' ';
}
