#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "palinx"
const int maxn = 1e6 + 5, base = 131, mod = 1e9 + 427;
const ll M = 1ll * mod * mod;
using namespace std;

int n, m;
string s[maxn];
ll h[maxn], res, ans;
vector<ll> a[maxn], b[maxn];

int geta(int i, int l, int r){
    if (l > r) return 0;
    return (a[i][r] - a[i][l - 1] * h[r - l + 1] + M) % mod;
}

int getb(int i, int l, int r){
    if (l > r) return 0;
    return (b[i][l] - b[i][r + 1] * h[r - l + 1] + M) % mod;
}

int cnt;
struct node {
    int child[26];
    int deg, cnt;
} T[maxn];

void add(string s, int m, int j){
    int x = 0;
    fi(i, 1, m){
        int now = s[i] - 'a';
        if (!T[x].child[now]) T[x].child[now] = ++cnt;
        x = T[x].child[now];
        if (geta(j, i + 1, m) == b[j][i + 1]){
            T[x].deg++;
        }
    }
    T[x].cnt++;
}

void get(string s, int m, int j){
    int x = 0;
    fid(i, m, 1){
        int now = s[i] - 'a';
        if (!T[x].child[now]) return;
        x = T[x].child[now];
        if (a[j][i-1] == getb(j, 1, i-1)) res += T[x].cnt;
    }
    res += T[x].deg - T[x].cnt;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    h[0] = 1;
    fi(i, 1, 1000004) h[i] = h[i - 1] * base % mod;
    fi(i, 1, n){
        cin >> m >> s[i];
        s[i] = ' ' + s[i];
        a[i].assign(m + 2, 0);
        b[i].assign(m + 2, 0);
        fi(j, 1, m){
            a[i][j] = (a[i][j - 1] * base + s[i][j]) % mod;
        }
        fid(j, m, 1){
            b[i][j] = (b[i][j + 1] * base + s[i][j]) % mod;
        }
        add(s[i], m, i);
    }
    fi(i, 1, n){
        get(s[i], s[i].size() - 1, i);
    }
    cout << res;// << ' ' << ans;
}
