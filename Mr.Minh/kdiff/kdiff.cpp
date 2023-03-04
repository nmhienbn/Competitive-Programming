#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "floor"
const int maxn = 755;

using namespace std;

int m, n, a[maxn][maxn], L[maxn][maxn][10][10], M[maxn][maxn], q;

int main(){
    faster
    cin >> m >> n;
    fi(i, 1, m){
        fi(j, 1, n){
            cin >> a[i][j];
            L[i][j][0][0] = a[i][j];
        }
    }
    int uu = log2(m), vv = log2(n);
    fi(v, 1, vv){
        fi(i, 1, m){
            fi(j, 1, n - (1 << v) + 1){
                L[i][j][0][v] = min(L[i][j + (1 << (v-1))][0][v-1], L[i][j][0][v-1]);
            }
        }
    }
    fi(u, 1, uu){
        fi(i, 1, m - (1 << u) + 1){
            fi(j, 1, n){
                L[i][j][u][0] = min(L[i + (1 << (u-1))][j][u-1][0], L[i][j][u-1][0]);
            }
        }
    }
    fi(u, 1, uu){
        fi(v, 1, vv){
            fi(i, 1, m - (1 << u) + 1){
                fi(j, 1, n - (1 << v) + 1){
                    int gt1 = max(u-1, 0), gt2 = max(v-1, 0);
                    int tg1 = (1 << gt1), tg2 = (1 << gt2);
                    int l1 = min(L[i][j][gt1][gt2], L[i + tg1][j + tg2][gt1][gt2]);
                    int l2 = min(L[i + tg1][j][gt1][gt2], L[i][j + tg2][gt1][gt2]);
                    L[i][j][u][v] = min(l1, l2);
                }
            }
        }
    }
    cin >> q;
    fi(i, 1, q){
        int x, y, z, t;
        cin >> x >> y >> z >> t;
        int u = log2(z - x + 1);
        int v = log2(t - y + 1);
        int l1 = min(L[x][y][u][v], L[z - (1 << u) + 1][t - (1 << v) + 1][u][v]);
        int l2 = min(L[z - (1 << u) + 1][y][u][v], L[x][t - (1 << v) + 1][u][v]);
        cout << min(l1, l2) << '\n';
    }
}
