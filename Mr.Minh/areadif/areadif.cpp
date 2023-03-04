#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "areadif"
const int maxn = 305;

using namespace std;

struct dl {
    int f, s, t;
    bool operator < (const dl& x) const {
        return f > x.f;
    }
};

int m, n, a[maxn][maxn], f[maxn][maxn][maxn];
vector<pii> g[maxn][maxn];

bool check(int u, int v){
    if (v == 0 || v == n) return true;
    if (a[u][v] == a[u][v + 1]) return false;
    return true;
}

void dijkstra(int st){
    priority_queue<dl> q;
    q.push({abs(st * 2 - n), 1, st});
    f[st][1][st] = st * 2 - n;

    while (q.size()){
        int x = q.top().s;
        int y = q.top().t;
        q.pop();
        for (pii p : g[x][y]){
            int u = p.first;
            int v = p.second;
            if (abs(f[st][u][v]) > abs(f[st][x][y] + (v * 2 - n))){
                f[st][u][v] = f[st][x][y] + (v * 2 - n);
                q.push({f[st][u][v], u, v});
            }
        }
    }
}

// 9 9 4 4 4 4 4 4 4 4
int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> m >> n;
    fi(i, 1, m){
        fi(j, 1, n){
            char c;
            cin >> c;
            a[i][j] = c - 'A';
        }
    }
    fi(i, 1, m-1){
        fi(j, 0, n){
            if (!check(i, j)) continue;
            if (check(i + 1, j)) g[i][j].push_back({i + 1, j});
            fi(k, j+1, n){
                if (a[i][k] == a[i + 1][k]) break;
                if (check(i + 1, k)){
                    g[i][j].push_back({i + 1, k});
                }
            }
            fid(k, j-1, 0){
                if (a[i][k + 1] == a[i + 1][k + 1]) break;
                if (check(i + 1, k)){
                    g[i][j].push_back({i + 1, k});
                }
            }
        }
    }

    memset(f, 60, sizeof(f));
    fi(i, 0, n){
        if (!check(1, i)) continue;
        dijkstra(i);
    }
    int res = 1e9;
    fi(k, 0, n){
        fi(j, 0, n){
            if (abs(f[k][m][j]) < abs(res)){
                res = f[k][m][j];
            }
        }
    }
    cout << f[3][m][3];
    cout << abs(res);
}
