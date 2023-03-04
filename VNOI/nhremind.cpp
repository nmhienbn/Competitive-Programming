#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "nhremind"
const int maxn = 1e6 + 5;
const int base = 29;
const int mod = 1e9 + 427;
const ll M = 1ll * mod * mod;
using namespace std;

int n, m;
vector<string> s;
string t;
vector<vector<ll>> a;
ll b[maxn], h[maxn], f[maxn], g[maxn];
int sz[maxn];
pii ff[maxn];
int d = 1, c, len;
vector<int> pos;

void enter(){
    cin >> n;
    a.resize(n + 1);
    s.resize(n + 1);
    fi(i, 1, n){
        cin >> s[i];
        sz[i] = s[i].size();
        a[i].assign(sz[i] + 2, 0);
        s[i] = ' ' + s[i];
    }
    cin >> t;
    m = t.size();
    t = ' ' + t;
}
void hashing(){
    fi(i, 1, n){
        fi(j, 1, sz[i]){
            a[i][j] = (a[i][j - 1] * base + s[i][j] - 'a') % mod;
        }
        if (c < sz[i]) c = sz[i];
    }
    h[0] = 1;
    fi(i, 1, m){
        b[i] = (b[i - 1] * base + t[i] - 'a') % mod;
        h[i] = h[i - 1] * base % mod;
    }
}
int get(int i, int l, int r){
    return (a[i][r] - a[i][l - 1] * h[r - l + 1] + M) % mod;
}
int get(int l, int r){
    return (b[r] - b[l - 1] * h[r - l + 1] + M) % mod;
}

bool check(int x){
    int u = m - x + 1;
    fi(i, 1, u){
        f[i] = get(i, i + x - 1);
    }
    sort(f + 1, f + u + 1);
    int v = 0;
    fi(i, 1, n){
        fi(j, 1, sz[i] - x + 1){
            g[++v] = get(i, j, j + x - 1);
        }
    }
    sort(g + 1, g + v + 1);
//    if (x == 1){
//        fi(i, 1, u) cout <<
//    }
    int j = 1;
    fi(i, 1, u){
        while (j <= v && g[j] < f[i]) j++;
        if (j > v || g[j] != f[i]) return true;
    }
    return false;
}
void getPos(int x){
    int u = m - x + 1;
    fi(i, 1, u){
        ff[i] = {get(i, i + x - 1), i};
    }
    sort(ff + 1, ff + u + 1);
    int v = 0;
    fi(i, 1, n){
        fi(j, 1, sz[i] - x + 1){
            g[++v] = get(i, j, j + x - 1);
        }
    }
    sort(g + 1, g + v + 1);
    int j = 1;
    fi(i, 1, u){
        while (j <= v && g[j] < ff[i].first) j++;
        if (j > v || g[j] != ff[i].first) pos.pb(ff[i].second);
    }
}
void findLengthAndPos(){
    while (d <= c){
        int g = (d + c) >> 1;
        if (check(g)) c = g - 1;
        else d = g + 1;
    }
    //fi(i, 1, m) cout << check(i);
    len = d;
    getPos(len);
}

bool cmp(int i, int j){
    int d = 1, c = len;
    while (d <= c){
        int g = (d + c) >> 1;
        if (get(i + d - 1, i + g - 1) != get(j + d - 1, j + g - 1)) c = g - 1;
        else d = g + 1;
    }
    return t[i + d - 1] < t[j + d - 1];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    enter();
    hashing();
    findLengthAndPos();
    sort(pos.begin(), pos.end(), cmp);
    fi(i, pos[0], pos[0] + len - 1) cout << t[i];
}
