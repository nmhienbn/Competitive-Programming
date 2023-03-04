#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "mess"
const int maxn = 5005;

using namespace std;

int n;
ll L[maxn];
vector<pii> g[maxn];

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n;
    int u1, v1, w1;
    while (cin >> u1 >> v1 >> w1){
        g[u1].pb({v1, w1});
    }
    queue<int> q;
    L[n] = 1e18;
    q.push(n);
    while (q.size()){
        int u = q.front();
        q.pop();
        for (auto &vt : g[u]){
            int v = vt.first;
            ll w = vt.second;
            if (w <= 0) continue;
            L[v] += min(L[u], w);
            vt.second -= min(L[u], w);
            q.push(v);
        }
    }
    cout << L[1];
}
