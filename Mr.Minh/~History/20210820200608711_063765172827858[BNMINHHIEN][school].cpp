#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pli pair<long long, int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "school"
const int maxn = 5005;

using namespace std;

int n, m;
ll L[maxn], cnt[maxn];
vector<pii> g[maxn];
priority_queue<pli, vector<pli>, greater<pli>> q;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, m){
        int k, u, v, w;
        cin >> k >> u >> v >> w;
        g[u].pb({v, w});
        if (k == 2) g[v].pb({u, w});
    }
    fi(i, 2, n) L[i] = 1e18;
    cnt[1] = 1;
    q.push({0, 1});
    while (q.size()){
        int u = q.top().second;
        q.pop();
        for (auto vt : g[u]){
            int v = vt.first, w = vt.second;
            if (L[v] > L[u] + w){
                L[v] = L[u] + w;
                cnt[v] = cnt[u];
                q.push({L[v], v});
            }
            else if (L[v] == L[u] + w){
                cnt[v] += cnt[u];
            }
        }
    }
    cout << L[n] << ' ' << cnt[n];
}
