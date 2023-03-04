#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "elephant"
const int maxn = 55, INF = 10001;
using namespace std;

int n, a[maxn], p[maxn], mina, minx, cnt, sum, res;
bool cl[maxn];
vector<int> g[maxn];

void dfs(int u){
    cl[u] = 1;
    for (int v : g[u]) if (!cl[v]){
        dfs(v);
    }
    sum += a[u];
    minx = min(minx, a[u]);
    cnt++;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i];
    mina = *min_element(a + 1, a + n + 1);
    fi(i, 1, n){
        cin >> p[i];
        p[i]++;
        g[i].pb(p[i]);
        g[p[i]].pb(i);
    }
    fi(i, 1, n) if (!cl[i]){
        cnt = sum = 0;
        minx = INF;
        dfs(i);
        res += sum + min(mina * (cnt + 1) + minx, minx * (cnt - 2));
    }
    cout << res;
}
