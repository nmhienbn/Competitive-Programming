#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "tax"
const int maxn = 1005;
using namespace std;

int n, m, L[maxn][maxn], cnt;
ll res;
char a[maxn];
vector<int> g[maxn];

priority_queue<pii, vector<pii>, greater<pii>> q;

void Dijkstra(int st, int L[]){
    fi(i, 1, n) L[i] = 1e9;
    L[st] = 0;
    q.push({0, st});
    while (q.size()){
        int u = q.top().second;
        if (L[u] < q.top().first){
            q.pop();
            continue;
        }
        q.pop();
        for (int v : g[u]){
            if (L[v] > L[u] + 1 + (a[st] != a[v]) * 3){
                L[v] = L[u] + 1 + (a[st] != a[v]) * 3;
                q.push({L[v], v});
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
    fi(i, 1, n){
        cin >> a[i];
    }
    fi(i, 1, m){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    fi(i, 1, n) Dijkstra(i, L[i]);
    fi(i, 1, n) fi(j, i + 1, n){
        if (a[i] == a[j]) res += L[i][j], cnt++;
    }
    cout << fixed << setprecision(10) << double(res) / cnt;
}
