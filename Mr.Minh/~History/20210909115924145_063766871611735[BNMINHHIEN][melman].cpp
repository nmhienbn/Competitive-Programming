#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "melman"
const int maxn = 1e6+5, base = 101, mod = 1e9+9;

using namespace std;

int k, n, m, z[maxn*2];
string s1, s2, s;
ll a[maxn], b[maxn], h[maxn];
vector<int> res;

void z_algo(){
    int l = 0, r = 0;
    for (int i=1; i < s.size(); i++) {
        if (z[i-l] < r-i+1) z[i] = z[i-l];
        else {
            r = max(r, i);
            while (s[r-i] == s[r]) r += 1;
            z[i] = r - i;
            r -= 1;
            l = i;
        }
    }
}

ll get1(int l, int r){
    return (a[r] - a[l-1] * h[r-l+1] + 1ll*mod*mod) % mod;
}

ll get2(int l, int r){
    return (b[r] - b[l-1] * h[r-l+1] + 1ll*mod*mod) % mod;
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> s1 >> s2 >> k;
    s = s2 + ' ' + s1;
    n = s1.size();
    m = s2.size();
    s1 = " " + s1;
    s2 = " " + s2;
    h[0] = 1;
    fi(i, 1, n){
        a[i] = (a[i-1] * base + s1[i]) % mod;
        h[i] = (h[i-1]* base) % mod;
    }
    fi(i, 1, m){
        b[i] = (b[i-1] * base + s2[i]) % mod;
    }
    z_algo();
    fi(i, 1, n-m+1){
        int d = z[i+m]+1;
        if (d > m-k) continue;
        if (get1(i+d, i+d+k-2) == get2(d+1, d+k-1)
        && get1(i+d+k, m+i-1) == get2(d+k+1, m)){
            res.pb(i);
        }
    }

    cout << res.size() << '\n';
    for (auto v : res) cout << v << ' ';
}

