#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "lift"
const int maxn = 1e6 + 5;
using namespace std;

int n, f[maxn], a[1005], U, D, I, J, L;
priority_queue<pii, vector<pii>, greater<pii>> q;
vector<int> g[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> U >> D >> I >> J >> L;
    fi(i, 1, L){
        int k;
        cin >> k;
        fi(u, 1, k) cin >> a[u];
        fi(u, 1, k) fi(v, u + 1, k){
            g[a[u]].pb(a[v]);
            g[a[v]].pb(a[u]);
        }
    }
    fi(i, 2, maxn - 5) f[i] = 1e9;
    q.push({0, 1});
    while (q.size()){
        int u = q.top().second;
        if (f[u] < q.top().first){
            q.pop();
            continue;
        }
        q.pop();
        if (f[u - 1] > f[u] + D){
            f[u - 1] = f[u] + D;
            q.push({f[u - 1], u - 1});
        }
        if (f[u + 1] > f[u] + U){
            f[u + 1] = f[u] + U;
            q.push({f[u + 1], u + 1});
        }
        for (int v : g[u]){
            if (f[v] > f[u] + I + J){
                f[v] = f[u] + I + J;
                q.push({f[v], v});
            }
        }
    }
    cout << f[n];
}
