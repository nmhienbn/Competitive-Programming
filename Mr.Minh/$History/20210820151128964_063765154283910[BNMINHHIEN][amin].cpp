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

int n, m, L[maxn][15][maxn][15];

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
    fi(u, 0, z){
        fi(v, 0, t){
            fi(i, 1, n+1 - (1 << u)){
                fi(j, 1, m+1 - (1 << v)){
                    int gt1 = max(u-1, 0), gt2 = max(v-1, 0);
                    int tg1 = (1 << gt1), tg2 = (1 << gt2);
                    if (u && v){
                        int l1 = min(L[i][gt1][j][gt2], L[i + tg1][gt1][j + tg2][gt2]);
                        int l2 = min(L[i][gt1][j + tg2][gt2], L[i + tg1][gt1][j][gt2]);
                        L[i][u][j][v] = min(l1, l2);
                    }
                    else if (u)
                        L[i][u][j][v] = min(L[i][gt1][j][gt2], L[i + tg1][gt1][j][gt2]);
                    else if (v)
                        L[i][u][j][v] = min(L[i][gt1][j][gt2], L[i][gt1][j + tg2][gt2]);
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
        z = max(z, 0), t = max(t, 0);
        int l1 = min(L[u][z][l][t], L[v+1 - (1 << z)][z][r+1 - (1 << t)][t]);
        int l2 = min(L[v+1 - (1 << z)][z][l][t], L[u][z][r+1 - (1 << t)][t]);
        cout << min(l1, l2) << '\n';
    }
}
