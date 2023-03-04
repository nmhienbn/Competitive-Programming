#include <bits/stdc++.h>
#define fi(i,a,b) for(int i=a; i<=b; i++)
#define fid(i,a,b) for(int i=a; i>=b; i--)
#define fir first
#define se second
#define bit(i,j) ((i>>j)&1)
#define bit2(i) (1<<(i-1))
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

#define maxn 500005
#define maxm 1000006
#define base 37
const int mod = 1e9+9;
#define Seraphine "v11str"

using namespace std;

int n, m;
ll a[maxn], b[maxn], h[maxn];

int get1(int l, int r){
    if (l > r) return 0;
    return (a[r] - a[l-1] * h[r-l+1] + 1ll*mod*mod) % mod;
}

int get2(int l, int r){
    if (l > r) return 0;
    return (b[r] - b[l-1] * h[r-l+1] + 1ll*mod*mod) % mod;
}

int main(){
    faster
    freopen(Seraphine".inp","r",stdin);
    freopen(Seraphine".out","w",stdout);
    cin >> n >> m;
    fi(i, 1, n){
        int x;
        cin >> x;
        a[i] = (a[i-1] * base + x) % mod;
    }
    h[0] = 1;
    fi(i, 1, m){
        int x;
        cin >> x;
        b[i] = (b[i-1] * base + x) % mod;
        h[i] = (h[i-1] * base) % mod;
    }
    fi(i, 1, m-n+1){
        int d = 1, c = n;
        while (d <= c){
            int g = (d + c) >> 1;
            if (get1(1, g) != get2(i, i+g-1)) c = g-1;
            else d = g+1;
        }
        if (get1(1, d-1) == get2(i, i+d-2) && get1(d+1, n) == get2(i+d, i+n-1)){
            cout << i;
            exit(0);
        }
    }
    cout << -1;
}
