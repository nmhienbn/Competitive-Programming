#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define NunuAndWillump "nkgolf"
const int maxn = 1005;

using namespace std;

int n, m, a[maxn][maxn], h[maxn],
    k[maxn], L[maxn], R[maxn], res;

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> m >> n;
    fi(i, 1, m){
        fi(j, 1, n){
            cin >> a[i][j];
        }
    }
    fi(i, 1, m){
        fi(j, 1, n){
            if (a[i][j] >= a[i-1][j]){
                h[j]++;
            }
            else h[j] = 1;
        }
        fi(j, 2, n){
            if (a[i][j] >= a[i][j-1]){
                k[j]++;
            }
            else k[j] = 0;
        }
        fi(j, 2, n){
            k[j] = min({k[j], h[j], h[j-1]});
            L[j] = j-1;
            R[j] = j+1;
        }
        fi(j, 2, n){
            while (L[j] > 1 && k[L[j]] >= k[j]){
                L[j] = L[L[j]];
            }
        }
        fid(j, n, 2){
            while (R[j] <= n && k[R[j]] >= k[j]){
                R[j] = R[R[j]];
            }
        }
        fi(j, 1, n) res = max(res, h[j]);
        fi(j, 2, n) res = max(res, k[j] * (R[j] - L[j]));
    }
    cout << res;
}
