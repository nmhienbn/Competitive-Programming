#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "amin"
const int maxn = 505;

using namespace std;

int n, m, a[maxn][maxn], L[maxn][10][maxn][10];

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, n){
        fi(j, 1, m){
            cin >> L[i][0][j][0];
        }
    }
    int z = log2(n), t = log2(m);
    fi(u, 1, z){
        fi(i, 1, n+1 - (1 << u)){
            fi(j, 1, m){
                L[i][u][j][0] = min(L[i][u-1][j][0], L[i + (1 << (u-1))][u-1][j][0]);
            }
        }
    }
    fi(v, 1, t){
        fi(j, 1, m+1 - (1 << v)){
            fi(i, 1, n){
                L[i][0][j][v] = min(L[i][0][j][v-1], L[i][0][j + (1 << (v-1))][v-1]);
            }
        }
    }
    fi(u, 1, z){
        fi(v, 1, t){
            fi(i, 1, n+1 - (1 << u)){
                fi(j, 1, m+1 - (1 << v)){
                    L[i][u][j][v] = min({L[i][u-1][j][v-1],
                                    L[i + (1 << (u-1))][u-1][j][v-1],
                                    L[i][u-1][j + (1 << (v-1))][v-1],
                                    L[i + (1 << (u-1))][u-1][j + (1 << (v-1))][v-1]});
                }
            }
        }
    }
    int q;
    cin >> q;
    while (q--){
        int u, l, v, r;
        cin >> u >> l >> v >> r;
        int z = log2(v-u+1), t = log(r-l+1);
        cout << min({L[u][z][l][t], L[v+1 - (1 << z)][z][l][t],
                    L[u][z][r+1 - (1 << t)][t], L[v+1 - (1 << z)][z][r+1 - (1 << t)][t]}) << '\n';

    }
}
