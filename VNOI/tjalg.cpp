#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "tjalg"
const int maxn = 1e4 + 5;
using namespace std;

void minimize(int& x, int& y){
    if (x > y) x = y;
}

int n, m;
vector<int> g[maxn];
int num[maxn], low[maxn], id;
int st[maxn], sn;
int stp;

void dfs(int u){
    num[u] = low[u] = ++id;
    st[++sn] = u;
    for (int v : g[u]){
        if (num[v]){
            minimize(low[u], num[v]);
        }
        else {
            dfs(v);
            minimize(low[u], low[v]);
        }
    }
    if (low[u] == num[u]){
        stp++;
        while (true){
            int v = st[sn--];
            low[v] = num[v] = 1e9;
            if (u == v) break;
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
        g[u].pb(v);
    }
    fi(i, 1, n) if (!num[i]) dfs(i);
    cout << stp;
}
