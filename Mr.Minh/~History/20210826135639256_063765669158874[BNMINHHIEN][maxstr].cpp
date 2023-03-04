#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "maxstr"
const int maxn = 2e5+5, mod = 1e9+9, base = 103;

using namespace std;

int n;
ll a[maxn], h[maxn], b[maxn];
string s;

ll get_hash(int l, int r){
    return (a[r] - a[l-1] * h[r-l+1] + 1ll*mod*mod) % mod;
}

bool check(int g){
    if (g < 0) return 0;
    fi(i, 1, n-g+1){
        b[i] = get_hash(i, i+g-1);
    }
    sort(b+1, b+n-g+2);
    fi(i, 2, n-g+1){
        if (b[i] == b[i-1]) return 1;
    }
    return 0;
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> s;
    s = ' ' + s;
    h[0] = 1;
    fi(i, 1, n){
        a[i] = (a[i-1] * base + s[i] - 'a') % mod;
        h[i] = (h[i-1] * base) % mod;
    }
    int d = 0, c = n;
    while (d <= c){
        int g = (d + c) >> 1;
        if (check(g)) d = g+1;
        else c = g-1;
    }
    cout << c;
}
