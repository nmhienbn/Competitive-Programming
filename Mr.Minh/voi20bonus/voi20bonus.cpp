#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "voi20bonus"
const int maxn = 305;

using namespace std;

int n, k, a[maxn];
ll L[maxn][maxn][maxn];

ll calc(int i, int j, int k){
    if (i > j && k > 0) return -1e18;
    if (L[i][j][k] != -1) return L[i][j][k];
    ll best = max(calc(i+1, j, k), calc(i, j-1, k));
    if (j - i >= 1 && k > 0) best = max({best,
                                calc(i+1, j-1, k-1) + abs(a[i]-a[j]),
                               calc(i+2, j, k-1) + abs(a[i]-a[i+1]),
                            calc(i, j-2, k-1) + abs(a[j]-a[j-1])});
    return L[i][j][k] = best;
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> k;
    fi(i, 1, n) cin >> a[i];
    fi(i, 1, n){
        fi(j, i, n){
            fi(t, 1, k)
            L[i][j][t] = -1;
        }
    }
    cout << calc(1, n, k);
}
