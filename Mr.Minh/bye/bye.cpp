#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define mu2(x) (1 << (x))
#define Irelia "bye"
const int maxn = 25, N = 1 << 20;

using namespace std;

int n, m, k, tg, s1, s2, p[maxn];
int L[maxn][maxn]; //, pre[maxn][maxn];
int d[N + 5][maxn], pre[N + 5][maxn], luu[maxn];
vector<pii> g[maxn];
//
//void Dijkstra(int st, int L[], int pre[]){
//    priority_queue<pii, vector<pii>, greater<pii>> q;
//    q.push({0, st});
//    fi(i, 1, n) L[i] = 1e9;
//    L[st] = 0;
//    while (q.size()){
//        int u = q.top().second;
//        q.pop();
//        for (pii vt : g[u]){
//            int v = vt.first, w = vt.second;
//            if (L[v] > L[u] + w){
//                L[v] = L[u] + w;
//                pre[v] = u;
//                q.push({L[v], v});
//            }
//        }
//    }
//}

void minimize(int& x, int y){
    if (x > y) x = y;
}

void dp_bit(){
    memset(d, 60, sizeof(d));
    fi(i, 1, k) d[mu2(i - 1)][i] = max(L[s1][p[i]], L[s2][p[i]]);
    int u = mu2(k) - 1;
    fi(x, 1, u - 1){
        fi(i, 1, k) if (gb(x, i - 1)){
            fi(j, 1, k) if (!gb(x, j - 1)){
                int y = (x | mu2(j - 1));
                if (d[y][j] > d[x][i] + L[p[i]][p[j]]){
                    d[y][j] = d[x][i] + L[p[i]][p[j]];
                    pre[y][j] = i;
                }
            }
        }
    }
    int res = 1e9, id = 0;
    fi(i, 1, k){
        if (res > d[u][i] + d[mu2(i - 1)][i]){
            res = d[u][i] + d[mu2(i - 1)][i];
            id = i;
        }
    }
    cout << tg - res << '\n';
    fid(i, k, 1){
        luu[i] = id;
        int trc = u;
        u -= mu2(id - 1);
        id = pre[trc][id];
    }
    fi(i, 1, k) cout << p[luu[i]] << ' ';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m >> k >> tg >> s1 >> s2;
    fi(i, 1, k) cin >> p[i];
    fi(i, 1, n) fi(j, 1, i - 1) L[i][j] = L[j][i] = 1e9;
    fi(i, 1, m){
        int u, v, w;
        cin >> u >> v >> w;
        L[u][v] = L[v][u] = w;
    }
//    fi(i, 1, n){
//        Dijkstra(i, L[i], pre[i]);
//
    fi(k, 1, n) fi(i, 1, n) fi(j, 1, n){
        minimize(L[i][j], L[i][k] + L[k][j]);
    }
    dp_bit();

}
