#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "maxstr"
const int maxn = 2e5+5, mod = 1e6+3, base = 29, mod2 = 1e9+7;

using namespace std;

int n;
bool cnt[mod], cnt2[mod2];
ll a[maxn], h[maxn], b[maxn];
string s;

ll get_hash(int l, int r, ll a[], int mod){
    return (a[r] - a[l-1] * h[r-l+1] + 1ll*mod*mod) % mod;
}

bool check(int g){
    if (g < 0) return 0;
    memset(cnt, 0, sizeof(cnt));
    memset(cnt2, 0, sizeof(cnt2));
    fi(i, 1, n-g+1){
        if (cnt[get_hash(i, i+g-1, a, mod)] && cnt2[get_hash(i, i+g-1, b, mod2)]){
            return 1;
        }
        else cnt[get_hash(i, i+g-1, a, mod)]  = cnt2[get_hash(i, i+g-1, b, mod2)] = 1;
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
        b[i] = (b[i-1] * base + s[i] - 'a') % mod2;
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
