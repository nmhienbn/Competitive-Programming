#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "bridge"
const int maxn = 20, nn = 1 << 20;
using namespace std;

int n, m;
double g[maxn][maxn], x[maxn], y[maxn], L[nn][maxn];
bool kt[maxn][maxn];

double dis(int i, int j){
    double X = x[i] - x[j];
    double Y = y[i] - y[j];
    return sqrt(X*X + Y*Y);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    scanf("%d %d", &n, &m);
    fi(i, 0, n-1) scanf("%lf %lf", x+i, y+i);
    fi(i, 0, n-1){
        fi(j, 0, i-1){
            g[i][j] = g[j][i] = dis(i, j);
        }
    }
    fi(i, 1, m){
        int x, y;
        scanf("%d %d", &x, &y);
        x--, y--;
        g[x][y] = g[y][x] = 0;
    }
    int mu = (1 << n) - 1;
    fi(x, 1, mu){
        fi(i, 0, n-1){
            L[x][i] = 1e18;
        }
    }
    fi(i, 0, n-1) L[1 << i][i] = 0;
    fi(x, 1, mu){
        fi(i, 0, n-1){
            if ((x >> i) & 1){
                fi(j, 0, n-1) if (!((x >> j) & 1)){
                    L[x | (1 << j)][j] = min(L[x][i] + g[i][j], L[x | (1 << j)][j]);
                }
            }
        }
    }
    double res = 1e18;
    fi(i, 0, n-1) res = min(res, L[mu][i]);
    if (res == 0) printf("YES");
    else printf("NO\n%.3lf", res);
}
