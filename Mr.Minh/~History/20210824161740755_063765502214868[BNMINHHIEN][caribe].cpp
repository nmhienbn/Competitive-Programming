#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "caribe"
const int maxn = 45, maxk = 2e5+5;

using namespace std;

int n, k, L[maxn][maxk], a[maxn], b[maxn], res;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> k;
    fi(i, 1, n) cin >> a[i] >> b[i];
    fi(i, a[1], k) L[1][i] = b[1];
    fi(i, 2, n){
        fi(j, 1, a[i]-1) L[i][j] = L[i-1][j];
        fi(j, a[i], k){
            L[i][j] = max(L[i-1][j], L[i-1][j-a[i]] + b[i]);
        }
    }
    cout << L[n][k];

}
