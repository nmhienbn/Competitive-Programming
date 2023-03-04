#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "max"
const int maxn = 105;

using namespace std;

int m, n, a[maxn][maxn], pre[maxn][maxn], id, vt[maxn];
ll L[maxn][maxn], res = -1e18;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> m >> n;
    fi(i, 1, m){
        fi(j, 1, n){
            cin >> a[i][j];
        }
    }
    fi(i, 1, m) L[i][1] = a[i][1];
    fi(j, 2, n){
        fi(i, 1, m){
            L[i][j] = -1e18;
            fi(t, max(i-1, 1), min(i+1, m)){
                if (L[i][j] < L[t][j-1] + a[i][j]){
                    L[i][j] = L[t][j-1] + a[i][j];
                    pre[i][j] = t;
                }
            }
        }
    }
    fi(i, 1, m){
        if (res < L[i][n]){
            res = L[i][n];
            id = i;
        }
    }
    fid(i, n, 1){
        vt[i] = id;
        id = pre[id][i];
    }
    cout << res << '\n';
    fi(i, 1, n) cout << vt[i] << '\n';
}
