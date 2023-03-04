#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "xor"
const int maxn = 1e3+5, mod = 1e9+7;

using namespace std;

int n, k, a[maxn], L[maxn][maxn], l[maxn], r[maxn];

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> k;
    fi(i, 1, n){
        cin >> a[i];
        a[i] ^= a[i-1];
    }
    fi(i, 1, k) cin >> l[i] >> r[i];
    L[0][0] = 1;
    fi(i, 1, k){
        fi(j, 1, n){
            fi(t, 1, j){
                int ss = a[j]^a[t-1];
                if (l[i] <= ss && ss <= r[i]){
                    L[j][i] += L[t-1][i-1];
                    L[j][i] %= mod;
                }
            }
        }
    }
    cout << L[n][k];
}
