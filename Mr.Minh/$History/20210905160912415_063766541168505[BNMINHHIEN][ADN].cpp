#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "ADN"
const int maxn = 1e5+5, base = 29, mod = 1e9+7;

using namespace std;

int n;
ll u[maxn], v[maxn], h[maxn], res1, res2;
string a, b;

int get_hash(int l, int r){
    return (u[r] - u[l-1] * h[r-l+1] + 1ll*mod*mod) % mod;
}

int get_hash2(int l, int r){
    return (v[r] - v[l-1] * h[r-l+1] + 1ll*mod*mod) % mod;
}

vector<pii> ss;

bool check(int g){
    ss.clear();
    fi(i, 1, n/2){
        ss.pb({get_hash(i, i+g-1), i});
    }
    sort(ss.begin(), ss.end());
    fi(i, 1, n/2){
        int t = get_hash2(i, i+g-1);
        int d = 0, c = n/2-1;
        while (d <= c){
            int gg = (d + c) >> 1;
            if (t <= ss[gg].first) c = gg-1;
            else d = gg+1;
        }
        //cout << d << ' ';
        while (ss[d].first == t && d < n/2){
            //cout << 1;
            bool flag = 1;
            fi(j, 0, g-1){
                if (a[ss[d].second+j] != b[i+j]) flag = 0;
            }
            if (flag){
                res1 = ss[d].second+g-1, res2 = i+g-1;
                return 1;
            }
            d++;
        }
    }
    return 0;
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> a >> b;
    a += a;
    b += b;
    n = a.size();
    a = ' ' + a;
    b = ' ' + b;
    h[0] = 1;
    fi(i, 1, n){
        u[i] = (u[i-1] * base + a[i]) % mod;
        v[i] = (v[i-1] * base + b[i]) % mod;
        h[i] = (h[i-1] * base) % mod;
    }
    int d = 1, c = n/2;
    while (d <= c){
        int g = (d + c) >> 1;
        if (check(g)) d = g+1;
        else c = g-1;
    }
    cout << c << '\n';
    check(c);
    fi(i, res1-n/2+1, res1) {cout << a[i];} cout << '\n';
    fi(i, res2-n/2+1, res2) {cout << b[i];} cout << '\n';
}
