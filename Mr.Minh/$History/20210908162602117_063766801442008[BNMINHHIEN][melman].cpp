#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "melman"
const int maxn = 2e5+5, base = 29, mod = 1e9+7;

using namespace std;

int k, n, m;
string s1, s2;
ll a[maxn], b[maxn], h[maxn];
vector<int> res;
vector< pair<ll, int> > hh;

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
    fi(i, 1, n-k){
        hh.pb({get1(i+1, i+k-1), i});
    }
    sort(hh.begin(), hh.end());
    fi(i, 1, m-k){
        ll u1 = get2(1, i-1), u2 = get2(i+1, i+k-1), u3 = get2(i+k+1, m);
        pair<ll, int> uu2 = {u2, 0};
        auto it = lower_bound(hh.begin(), hh.end(), uu2);
        while (it->first == u2){
            int j = it->second;
            if (j-i+1 < 1 && m+j-i > n){
                it++;
                continue;
            }
            ll v1 = get1(j-i+1, j-1), v2 = get1(j+1, j+k-1), v3 = get1(j+k+1, m+j-i);
            //cout << u1 << ' ' << v1 << ' ' << u2 << ' ' << v2 << ' ' << u3 << ' ' << v3 << '\n';
            if (u1 == v1 && u2 == v2 && u3 == v3 && s1[j] != s2[i] && s1[j+k] != s2[i+k]){
                res.pb(j-i+1);
            }
            it++;
        }
    }
    sort(res.begin(), res.end());
    res.resize(unique(res.begin(), res.end()) - res.begin());
    cout << res.size() << '\n';
    for (auto v : res) cout << v << ' ';
}
