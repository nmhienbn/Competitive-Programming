#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "collect"
const int maxn = 70;
using namespace std;

ll n;
int k, m, a[maxn];
ll f[maxn], g[maxn];

void preprocess(){
    f[2] = k - 1;
    fi(i, 3, 64){
        fi(j, 2, i - 1){
            f[i] += f[j];
        }
        if (i % 2 == 0) f[i]++;
        f[i] *= k - 1;
    }
    fi(i, 2, 64) g[i] = g[i - 1] + f[i];
}

ll calc(ll n){
    m = 0;
    int t = 0;
    while (n > 0){
        a[++m] = n % k;
        n /= k;
    }
    fi(i, 1, m) if (a[i] != 0){
        t = i;
        break;
    }
    ll ans = g[m - 1];
    fid(i, m, t){
        fi(j, 0, a[i] - 1) if (j > 0 || i < m){
            ans += g[i - 1];
            if (j && i % 2 == 0) ans++;
        }
        if (a[i] && i % 2 == 0) ans++;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> k;
    preprocess();
    ll d = 1, c = 1e18;
    while (d <= c){
        ll g = (d + c) >> 1;
        //cout << g << ' ' << calc(g) << '\n';
        if (calc(g) >= n) c = g - 1;
        else d = g + 1;
    }
    cout << d;
}
