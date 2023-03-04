#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pid pair<int,double>
#define pdi pair<double,int>
#define pb push_back
#define ll long long
#define Irelia "highway"
const int maxn = 755;
using namespace std;

struct dl {
    double w;
    int u, p;
    bool operator < (const dl& x) const {
        return w > x.w;
    }
};

int n, m, cnt;
pii a[maxn];
bool kt[maxn][maxn];
double dis[maxn], res;
vector<pid> g[maxn];
pii b[maxn];

double d(int x, int y){
    return sqrt(1ll * x * x + 1ll * y * y);
}

priority_queue<dl> q;

void prim(){
    fi(i, 1, n) dis[i] = 1e9;
    dis[1] = 0;
    kt[0][1] = kt[1][0] = 1;
    q.push({0, 1, 0});

    while (q.size()) {
        int u = q.top().u;
        int p = q.top().p;
        if (q.top().w > dis[u]){
            q.pop();
            continue;
        }
        q.pop();
        if (!kt[u][p]) b[++cnt] = {u, p};
        res += dis[u];
        dis[u] = -1e9;

        fi(v, 1, n){
            double w = 0;
            if (!kt[u][v]) w = d(a[u].first - a[v].first, a[u].second - a[v].second);
            if (dis[v] > w){
                dis[v] = w;
                q.push({dis[v], v, u});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i].first >> a[i].second;
    cin >> m;
    fi(i, 1, m){
        int u, v;
        cin >> u >> v;
        kt[u][v] = kt[v][u] = 1;
    }
    prim();
    cout << fixed << setprecision(2) << res << '\n';
    cout << cnt << '\n';
    fi(i, 1, cnt){
        cout << b[i].first << ' ' << b[i].second << '\n';
    }
}
