#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define all(a) a.begin(), a.end()
#define Irelia "travel"
const int maxn = 2e5 + 5;
using namespace std;

struct dl {
    int f, s;
};

int n, in[maxn];
int f[maxn], res;
bool cl[maxn];
dl a[maxn];
vector<int> val, g[maxn];
queue<int> q;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    val.resize(n * 2 + 1);
    val[0] = -1;
    fi(i, 1, n){
        cin >> val[i] >> val[i + n];
        a[i] = {val[i], val[i + n]};
    }
    sort(all(val));
    val.resize(unique(all(val)) - val.begin());
    fi(i, 1, n){
        a[i].f = lower_bound(all(val), a[i].f) - val.begin();
        a[i].s = lower_bound(all(val), a[i].s) - val.begin();
        if (a[i].f != a[i].s){
            g[a[i].f].pb(a[i].s);
            in[a[i].s]++;
        }
        else {
            cl[a[i].f] = 1;
        }
    }
    n = val.size() - 1;
    fi(i, 1, n){
        if (!in[i]) f[i] = cl[i], q.push(i);
    }
    while (q.size()){
        int u = q.front();
        q.pop();
        for (int v : g[u]){
            f[v] = max(f[v], f[u] + 1 + cl[v]);
            if (--in[v] == 0) q.push(v);
        }
    }
    fi(i, 1, n) res = max(res, f[i]);
    cout << res;
}
