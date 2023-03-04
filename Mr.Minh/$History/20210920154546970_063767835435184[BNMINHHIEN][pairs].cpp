#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "pairs"
const int maxn = 1e5+5, mod = 1e9+7;

using namespace std;

int a[maxn], b[maxn], h[20], n;
ll res, cnt;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n;
    h[0] = 1;
    fi(i, 1, 9) h[i] = h[i-1] * 10;
    fi(i, 1, n){
        cin >> a[i];
        int d = 0, c = a[i];
        while (c > 0){
            d++;
            c /= 10;
        }
        cnt += h[d];
        b[i] = h[d];
    }
    fi(i, 1, n){
        res = (res + 1ll*(a[i]*(n-1)) % mod) % mod;
        res = (res + 1ll*(a[i]*(cnt-b[i])) % mod) % mod;
    }
    cout << res;
}
