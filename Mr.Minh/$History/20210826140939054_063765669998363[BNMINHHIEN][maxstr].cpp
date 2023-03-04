#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "maxstr"
const int maxn = 2e5+5, base = 103, base2 = 101;
const ll mod = 1000992299, mod2 = 1e9+7;

using namespace std;

int n;
ll a[maxn], h[maxn], b[maxn], l[maxn], t[maxn];
string s;

ll get_hash(int l, int r, ll a[], ll h[], ll mod){
    return (a[r] - a[l-1] * h[r-l+1] + mod*mod) % mod;
}

bool check(int g){
    if (g < 0) return 0;
    bool ok1 = 0, ok2 = 0;
    fi(i, 1, n-g+1){
        t[i] = get_hash(i, i+g-1, a, h, mod);
    }
    sort(t+1, t+n-g+2);
    fi(i, 2, n-g+1){
        if (t[i] == t[i-1]) {ok1 = 1; break;}
    }

    fi(i, 1, n-g+1){
        t[i] = get_hash(i, i+g-1, b, l, mod2);
    }
    sort(t+1, t+n-g+2);
    fi(i, 2, n-g+1){
        if (t[i] == t[i-1]) {ok2 = 1; break;}
    }
    return (ok1 && ok2);
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> s;
    s = ' ' + s;
    h[0] = 1;
    l[0] = 1;
    fi(i, 1, n){
        a[i] = (a[i-1] * base + s[i] - 'a') % mod;
        h[i] = (h[i-1] * base) % mod;
        b[i] = (b[i-1] * base2 + s[i] - 'a') % mod2;
        l[i] = (l[i-1] * base2) % mod2;
    }
    int d = 0, c = n;
    while (d <= c){
        int g = (d + c) >> 1;
        if (check(g)) d = g+1;
        else c = g-1;
    }
    cout << c;
}
