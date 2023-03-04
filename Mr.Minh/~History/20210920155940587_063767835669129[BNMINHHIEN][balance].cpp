#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "balance"
const int maxn = 25, nn = 1 << 20;

using namespace std;

int L[nn], a[maxn], n, m, sum;
ll res;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, n){
        cin >> a[i];
        sum += a[i];
    }
    int uu = (1 << n);
    L[uu-1] = sum;
    fi(x, 1, uu/2-1){
        fi(i, 0, n-1){
            if ((x >> i) & 1){
                L[x] = L[x - (1 << i)] + a[i+1];
                break;
            }
        }
        L[uu-x-1] = sum - L[x];
    }
    fi(x, 0, uu-1){
        fi(y, 0, x-1){
            if ((x&y) == 0 && L[x] - L[y] == m){
                res++;
            }
        }
    }
    cout << res;
}
