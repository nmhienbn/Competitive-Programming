#include <bits/stdc++.h>
#define fi(i,a,b) for(int i=a; i<=b; i++)
#define fid(i,a,b) for(int i=a; i>=b; i--)
#define fir first
#define se second
#define bit(i,j) ((i>>j)&1)
#define bit2(i) (1<<(i-1))
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

#define maxn 25
#define maxm 1000006
#define MOD
#define Seraphine "c11dk2"
const int mod = 2012;

using namespace std;

int n, x, p, g[maxn][3];

struct matrix {
    ll a[60][60];
};

matrix operator * (matrix A, matrix B){
    matrix C;
    fi(i, 0, n*3-1){
        fi(j, 0, n*3-1){
            C.a[i][j] = 0;
            fi(k, 0, n*3-1){
                C.a[i][j] = (C.a[i][j] + A.a[i][k] * B.a[k][j]) % mod;
            }
        }
    }
    return C;
}

matrix mu(matrix A, ll k){
    if (k == 1) return A;
    auto tg = mu(A, k >> 1);
    tg = tg * tg;
    if (k & 1) tg = tg * A;
    return tg;
}
matrix A;
int row[maxn][maxn], f[maxn][maxn];

int main(){
    faster
    freopen(Seraphine".inp","r",stdin);
    freopen(Seraphine".out","w",stdout);
    cin >> n >> x >> p;
    fi(u, 1, n*2){
        g[u][0] = u <= n ? u+n : u-n;
        if (u <= n){
            g[u][1] = u == n ? 1 : u+1;
            g[u][2] = u == 1 ? n : u-1;
        }
        else {
            g[u][1] = u == n*2 ? n+1 : u+1;
            g[u][2] = u == n+1 ? n*2 : u-1;
        }
    }
    n *= 2;
    fi(i, 1, n){
        fi(j, 0, 2){
            int u = g[i][j];
            row[i][u] = i*3+j-3;
        }
    }
    fi(i, 0, 2) f[1][g[1][i]] = 1;
    fi(i, 1, n){
        fi(j, 0, 2){
            fi(k, 0, 2) if (j != k){
                int x = row[i][g[i][j]], y = row[g[i][k]][i];
                A.a[x][y] = 1;
            }
        }
    }
    ll ans = 0;
    if (p == 1){
        fi(i, 0, 2) ans = (ans + f[g[x][i]][x]) % mod;
        cout << ans;
        exit(0);
    }
    A = mu(A, p-1);
    fi(i, 0, 2){
        int u = g[x][i];
        fi(j, 0, 2){
            ans = (ans + A.a[row[u][x]][j]) % mod;
        }
    }
    cout << ans;
}
