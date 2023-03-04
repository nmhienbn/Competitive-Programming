#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "HT"
const int maxn = 45, mod = 1e9+7;
using namespace std;

int n;
ll a[maxn], h[maxn], t[10];
string s;

int get_hash(int l, int r){
    return (a[r] - a[l-1] * h[r-l+1] + 1ll*mod*mod) % mod;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> s;
    n = s.size();
    s = ' ' + s;
    h[0] = 1;
    fi(i, 1, n){
        a[i] = (a[i-1]*2 + (s[i] == 'H' ? 1 : 0)) % mod;
        h[i] = (h[i-1]*2) % mod;
    }
    fi(i, 1, n-2){
        int now = get_hash(i, i+2);
        t[now]++;
    }
    fi(i, 0, 7) cout << t[i] << ' ';
}
