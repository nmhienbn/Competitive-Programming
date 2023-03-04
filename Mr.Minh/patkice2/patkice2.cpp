#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "patkice2"
const int maxn = 2005,
            ngg[4] = {-1, 0, 0, 1},
            doc[4] = {0, -1, 1, 0};

using namespace std;

struct dl {
    int u, v, w;
    bool operator < (const dl& x) const {
        return w > x.w;
    }
};

int n, m, dx, dy, sx, sy, L[maxn][maxn], pre[maxn][maxn];
char a[maxn][maxn];
char tt[4] = {'^', '<', '>', 'v'};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> m >> n;
    fi(i, 1, m) fi(j, 1, n){
        cin >> a[i][j];
        if (a[i][j] == 'o') dx = i, dy = j;
        if (a[i][j] == 'x') sx = i, sy = j;
    }
    fi(i, 1, m) fi(j, 1, n) L[i][j] = 1e9;
    priority_queue<dl> q;
    q.push({dx, dy, 0});
    L[dx][dy] = 0;
    while (q.size()){
        int i = q.top().u, j = q.top().v;
        if (q.top().w > L[i][j]){
            q.pop();
            continue;
        }
        q.pop();
        fi(t, 0, 3){
            int u = i + ngg[t], v = j + doc[t];
            if (L[u][v] > L[i][j] + (a[i][j] != tt[t])){
                L[u][v] = L[i][j] + (a[i][j] != tt[t]);
                pre[u][v] = t;
                q.push({u, v, L[u][v]});
            }
        }
    }
    cout << L[sx][sy] - 1 << '\n';
    while (true){
        int typ = pre[sx][sy];
        sx -= ngg[typ];
        sy -= doc[typ];
        if (sx == dx && sy == dy) break;
        a[sx][sy] = tt[typ];
    }
    fi(i, 1, m){
        fi(j, 1, n){
            cout << a[i][j];
        }
        cout << '\n';
    }
}
