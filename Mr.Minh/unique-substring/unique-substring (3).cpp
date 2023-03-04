#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pli pair <ll, int>
#define pb push_back
#define Irelia "unique-substring"
const int maxn = 5e4+5, mod = 1e9+427, base = 29;
const ll MM = 1ll*mod*mod;
using namespace std;

int n, d, c;
ll h[maxn], a[maxn];
string s;
ll val[maxn];
pli gt[maxn];
vector<int> vt;

ll get_hash(int l, int r){
    return (a[r] - a[l-1] * h[r-l+1] + MM) % mod;
}

bool check(int g){
    if (g == n) return true;
    int m = n-g+1;
    fi(i, 1, m){
        val[i] = get_hash(i, i+g-1);
    }
    sort(val+1, val+m+1);
    if (val[1] != val[2]) return true;
    if (val[m] != val[m-1]) return true;
    fi(i, 2, m-1){
        if (val[i] != val[i-1] && val[i] != val[i+1]) return true;
    }
    return false;
}

bool cmp(int i, int j){
    int l = 0, r = d;
    while (l <= r){
        int m = (l + r) >> 1;
        if (get_hash(i, i+m-1) == get_hash(j, j+m-1)) l = m + 1;
        else r = m - 1;
    }
    return s[i+r] < s[j+r];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> s;
    n = s.size();
    s = ' ' + s;
    h[0] = 1;
    fi(i, 1, n){
        a[i] = (a[i-1] * base + s[i] - 'a') % mod;
        h[i] = h[i-1] * base % mod;
    }
    d = 1, c = n;
    while (d <= c){
        int g = (d + c) >> 1;
        if (check(g)) c = g-1;
        else d = g+1;
    }
    if (d == n){
        fi(i, 1, n) cout << s[i];
        exit(0);
    }
    int m = n-d+1;
    fi(i, 1, m){
        gt[i] = {get_hash(i, i+d-1), i};
        //cout << gt[i].first << '\n';
    }
    sort(gt+1, gt+m+1);
    if (gt[1].first != gt[2].first) vt.pb(gt[1].second);
    if (gt[m].first != gt[m-1].first) vt.pb(gt[m].second);
    fi(i, 2, m-1){
        if (gt[i].first != gt[i-1].first && gt[i].first != gt[i+1].first){
            vt.pb(gt[i].second);
        }
    }
    sort(vt.begin(), vt.end(), cmp);
    //for (auto v : vt) cout << v << ' ';
    fi(i, vt[0], vt[0]+d-1) cout << s[i];
}
