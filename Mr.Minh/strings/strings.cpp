#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "strings"
const int maxn = 1e5 + 5, base1 = 123, mod1 = 1e9 + 427;
const ll M1 = 1ll * mod1 * mod1;
const int base2 = 127, mod2 = 1e9 + 7;
const ll M2 = 1ll * mod2 * mod2;
using namespace std;

int n, m, res;
int a1[maxn * 2], h1[maxn], b1[maxn];
string s, t;

int getA1(int l, int r){
    return (a1[r] - 1ll * a1[l - 1] * h1[r - l + 1] + M1) % mod1;
}
int getB1(int l, int r){
    return (b1[r] - 1ll * b1[l - 1] * h1[r - l + 1] + M1) % mod1;
}

int a2[maxn * 2], h2[maxn], b2[maxn];

int getA2(int l, int r){
    return (a2[r] - 1ll * a2[l - 1] * h2[r - l + 1] + M2) % mod2;
}
int getB2(int l, int r){
    return (b2[r] - 1ll * b2[l - 1] * h2[r - l + 1] + M2) % mod2;
}

set<pii> kt;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> t >> s;
    n = s.size();
    m = t.size();
    s = ' ' + s;
    t = ' ' + t;

    h1[0] = 1;
    fi(i, 1, n) h1[i] = 1ll * h1[i - 1] * base1 % mod1;
    fi(i, 1, n) a1[i] = (1ll * a1[i - 1] * base1 + s[i]) % mod1;
    fi(i, n + 1, n * 2) a1[i] = (1ll * a1[i - 1] * base1 + s[i - n]) % mod1;
    fi(i, 1, m) b1[i] = (1ll * b1[i - 1] * base1 + t[i]) % mod1;

    h2[0] = 1;
    fi(i, 1, n) h2[i] = 1ll * h2[i - 1] * base2 % mod2;
    fi(i, 1, n) a2[i] = (1ll * a2[i - 1] * base2 + s[i]) % mod2;
    fi(i, n + 1, n * 2) a2[i] = (1ll * a2[i - 1] * base2 + s[i - n]) % mod2;
    fi(i, 1, m) b2[i] = (1ll * b2[i - 1] * base2 + t[i]) % mod2;

    fi(i, 1, n) kt.insert({getA1(i, i + n - 1), getA2(i, i + n - 1)});
    fi(i, 1, m - n + 1) res += (kt.find({getB1(i, i + n - 1), getB2(i, i + n - 1)}) != kt.end());
    cout << res;
}
