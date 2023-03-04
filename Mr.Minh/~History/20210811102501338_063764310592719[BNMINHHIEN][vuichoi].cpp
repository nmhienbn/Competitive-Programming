#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "vuichoi"
const int maxn = 505, ngg[4] = {-1, 0, 0, 1}, doc[4] = {0, -1, 1, 0};

using namespace std;

struct dl{
    int d, u, v, t;
    bool operator < (const dl& x) const {
        return d > x.d;
    }
};

int n, m, L[maxn][maxn][8], a[maxn][maxn];
int xy[maxn][maxn];

bool kt(int l, int a, int r){
    return l <= a && a <= r;
}

void Dijkstra(){
    priority_queue<dl> q;
    q.push({L[1][1][xy[1][1]], 1, 1, xy[1][1]});
    while(q.size()){
        int u = q.top().u, v = q.top().v, t = q.top().t;
        //cout << u << ' ' << v << ' ' << t << ' ' << L[u][v][t] << '\n';
        q.pop();
        fi(i, 0, 3){
            int u1 = u+ngg[i], v1 = v+doc[i];
            if (kt(1, u1, n) && kt(1, v1, m)){
                int id = t|xy[u1][v1];
                if (L[u1][v1][id] > L[u][v][t] + a[u1][v1]){
                    L[u1][v1][id] = L[u][v][t] + a[u1][v1];
                    q.push({L[u1][v1][id], u1, v1, id});
                }
            }
        }
    }
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> m;
    fi(i, 0, 2){
        int x, y;
        cin >> x >> y;
        xy[x][y] = 1 << i;
    }
    fi(i, 1, n){
        fi(j, 1, m){
            cin >> a[i][j];
            fi(t, 0, 7){
                L[i][j][t] = 1e9;
            }
        }
    }
    L[1][1][xy[1][1]] = a[1][1];
    Dijkstra();
    //cout << L[n][m][3] << ' ' << L[n][m][5] << ' ' << L[n][m][6] << ' ' << L[n][m][7] << '\n';
    cout << min(min(L[n][m][3], L[n][m][5]), min(L[n][m][6], L[n][m][7]));
}
