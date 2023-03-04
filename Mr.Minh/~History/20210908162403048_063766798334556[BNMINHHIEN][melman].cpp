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
    fi(i, 1, m-k){
        ll u1 = get2(1, i-1), u2 = get2(i+1, i+k-1), u3 = get2(i+k+1, m);
        fi(j, 1, n-m+1){
            ll v1 = get1(j, j+i-2), v2 = get1(j+i, j+i+k-2), v3 = get1(j+i+k, j+m-1);
            //cout << u1 << ' ' << v1 << ' ' << u2 << ' ' << v2 << ' ' << u3 << ' ' << v3 << '\n';
            if (u1 == v1 && u2 == v2 && u3 == v3 && s1[j+i-1] != s2[i] && s1[j+i+k-1] != s2[i+k]){
                res.pb(j);
            }
        }
    }
    sort(res.begin(), res.end());
    res.resize(unique(res.begin(), res.end()) - res.begin());
    cout << res.size() << '\n';
    for (auto v : res) cout << v << ' ';
}
