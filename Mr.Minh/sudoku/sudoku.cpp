#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "sudoku"
const int maxn = 15;
using namespace std;

int a[maxn][maxn], vt[maxn], pos[maxn], vt1, vt2, dem[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    fi(i, 1, 9) fi(j, 1, 9){
        char c;
        cin >> c;
        a[i][j] = c - '0';
    }
    fi(i, 1, 9){
        fi(j, 1, 9){
            vt[j] = 0;
        }
        fi(j, 1, 9){
            if (vt[a[i][j]]){
                int v = vt[a[i][j]];
                fi(u, 1, 9){
                    if (pos[a[u][v]]){
                        vt1 = i;
                        vt2 = v;
                        goto kq;
                    }
                    pos[a[u][v]] = 1;
                }
                vt1 = i;
                vt2 = j;
                goto kq;
            }
            vt[a[i][j]] = j;
        }
    }
    kq : cout << vt1 << ' ' << vt2 << ' ';
    fi(j, 1, 9) if (j != vt2) dem[a[vt1][j]] = 1;
    fi(i, 1, 9) if (!dem[i]){
        cout << i;
        break;
    }
}
