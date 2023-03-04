#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "pushbox"
const int maxn = 1e4 + 5;
using namespace std;

int n, m, k, f[maxn], pre[maxn], res;
vector<int> g[maxn];
int a[maxn];
queue<int> q;

bool cmp(int a, int b){
    return f[a] < f[b];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m >> k;
    fi(i, 1, k) cin >> a[i];
    fi(i, 1, m){
        int u, v;
        cin >> u >> v;
        g[v].pb(u);
    }
    q.push(1);
    while (q.size()){
        int u = q.front();
        q.pop();
        for (int v : g[u]){
            if (!f[v]) f[v] = f[u] + 1, pre[v] = u, q.push(v);
        }
    }
    sort(a + 1, a + k + 1, cmp);
    fi(i, 1, k) res += f[a[i]];
    cout << res << '\n';
    fi(i, 1, k){
        int u = a[i];
        fi(j, 1, f[a[i]]){
            cout << u << ' ' << pre[u] << '\n';
            u = pre[u];
        }
    }
}
