#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "select"
const int maxn = 1e4+5;
const int tt[8] = {0, 1, 2, 4, 5, 8, 9, 10};

using namespace std;

int n, a[maxn][20];
ll L[maxn][10], res = -1e18;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        fi(j, 1, 4){
            cin >> a[i][j];
        }
        fi(j, 0, 7){
            L[i][j] = -1e18;
        }
    }
    fi(i, 1, n){
        fi(j, 0, 7){
            fi(t, 0, 7){
                if (!(tt[j]&tt[t])){
                    L[i][j] = max(L[i][j], L[i-1][t]);
                }
            }
            fi(t, 1, 4) if ((tt[j] >> (t-1))&1) L[i][j] += a[i][t];
        }
    }
    fi(i, 0, 7) res = max(res, L[n][i]);
    cout << res;
}
