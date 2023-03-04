#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "robot"
const int maxn = 1005;
const int ngg[4] = {0, -1, 0, 1};
const int doc[4] = {-1, 0, 1, 0};
using namespace std;

struct dl {
    int x, y, t;
};

int n, dx, dy, S, now;
int a[maxn][maxn];
int f[maxn][maxn][4], cnt;
pii g[maxn * maxn * 4];
queue<dl> q;

void except(){
    if (dx > n || dx <= 0 || dy <= 0){
        cout << dx << ' ' << dy - S;
        exit(0);
    }
    if (dy > n){
        int d = min(dy - n, S);
        dy -= d;
        S -= d;
    }
    if (S == 0){
        cout << dx << ' ' << dy;
        exit(0);
    }
    if (a[dy][dx]){
        S++, dy++;
        cout << dx - S << ' ' << dy;
        exit(0);
    }
}

void BFS(){
    q.push({dx, dy, 0});
    cnt--;
    while (q.size()){
        int i = q.front().x;
        int j = q.front().y;
        int t = q.front().t;
        q.pop();
        g[++cnt] = {i, j};
        fi(rep, t, t + 3){
            int z = rep & 3;
            int u = i + ngg[z];
            int v = j + doc[z];
            if (a[v][u] == 1) continue;
            if (a[v][u] == 2){
                cout << i + ngg[z] * (S - f[i][j][t]) << ' ' << j + doc[z] * (S - f[i][j][t]);
                exit(0);
            }
            if (!f[u][v][z]){
                f[u][v][z] = f[i][j][t] + 1;
                if (f[u][v][z] == S){
                    cout << u << ' ' << v;
                    exit(0);
                }
                q.push({u, v, z});
                break;
            }
            else {
                int C = f[i][j][t] + 1 - f[u][v][z];
                int vt = f[u][v][z] + (S - f[u][v][z]) % C;
                cout << g[vt].first << ' ' << g[vt].second;
                exit(0);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> dx >> dy >> S;
    fi(i, 1, n) fi(j, 1, n){
        char c;
        cin >> c;
        a[i][j] = (c == '#');
    }
//    fi(i, 1, n) {
//        fi(j, 1, n) cout << a[i][j];
//        cout << endl;
//    }
    except();
    fi(i, 1, n) a[0][i] = a[n + 1][i] = a[i][0] = a[i][n + 1] = 2;
    BFS();
}
