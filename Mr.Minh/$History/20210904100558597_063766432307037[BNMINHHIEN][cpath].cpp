#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "cpath"
const int maxn = 51, mod = 2017;

using namespace std;

int n, m, k;
int L[maxn][maxn][32], res = 1, g[maxn][maxn][32];

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> m >> k;
    fi(i, 1, m){
        int u, v;
        cin >> u >> v;
        L[u][v][0]++;
    }
    int t = log2(k);
    fi(r, 1, t){
        fi(i, 1, n){
            fi(j, 1, n){
                fi(w, 1, n){
                    L[i][j][r] = (L[i][j][r] + L[i][w][r-1] * L[w][j][r-1]) % mod;
                }
            }
        }
    }
    fi(i, 1, n)
        fi(j, 1, n)
            g[i][j][t] = L[i][j][t];
    fid(r, t-1, 0){
        fi(i, 1, n){
            fi(j, 1, n){
                if (((k >> r) & 1) == 0) g[i][j][r] = g[i][j][r+1];
                else {
                    fi(u, 1, n){
                        g[i][j][r] = (g[i][j][r] + g[i][u][r+1] * L[u][j][r]) % mod;
                    }
                }
            }
        }
    }
    cout << g[1][n][0];
}
