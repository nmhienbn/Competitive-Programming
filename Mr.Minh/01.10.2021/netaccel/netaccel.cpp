#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "netaccel"
#define TWO(x) (1 << x)
const int maxn = 1e3+5;

using namespace std;

struct dl {
    double w;
    int u, l;
    bool operator < (const dl& x) const {
        return w > x.w;
    }
};

int n, m, k;
double L[maxn][15];
vector<pair<int, double>> g[maxn];

priority_queue<dl> q;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    scanf("%d %d %d", &n, &m, &k);
    fi(i, 1, m){
        int u, v;
        double w;
        scanf("%d %d %lf", &u, &v, &w);
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    fi(i, 1, n) fi(j, 0, k) L[i][j] = 1e9;
    L[1][0] = 0;
    q.push({0, 1, 0});
    while (q.size()){
        int u = q.top().u, l = q.top().l;
        q.pop();
        if (u == n) break;
        for (auto vt : g[u]){
            int v = vt.first;
            double w = vt.second;
            fi(i, 0, k-l){
                if (L[v][i+l] > L[u][l] + w/TWO(i)){
                    L[v][i+l] = L[u][l] + w/TWO(i);
                    q.push({L[v][i+l], v, i+l});
                }
            }
        }
    }
    double res = 1e9;
    fi(i, 0, k) if (L[n][i] < res) res = L[n][i];
    printf("%.2lf", res);
}
