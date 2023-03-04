#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "split"
const int maxn = 1e5+5;

using namespace std;

int n, m, h[maxn], res;
vector<int> g[maxn];
int a[maxn];

void dfs(int u, int p, int k){
    for (auto v : g[u]){
        if (v == p) continue;
        dfs(v, u, k);
    }
    int top = 0;
    for (auto v : g[u]){
        if (v == p) continue;
        a[++top] = h[v] + 1;
    }
    sort(a + 1, a + top + 1);
    while (a[top] + a[top - 1] > k) top--, res++;
    h[u] = a[top];
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> m;
    fi(i, 2, n){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    int d = 0, c = n;
    while (d <= c){
        int g = (d + c) >> 1;
        fi(i, 1, n){
            h[i] = 0;
        }
        res = 0;
        dfs(1, 0, g);
        if (res <= m) c = g - 1;
        else d = g + 1;
    }
    cout << d;
}
