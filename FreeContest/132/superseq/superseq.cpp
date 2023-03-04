#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define X first
#define Y second
#define pb push_back
#define ll long long
#define Irelia "superseq"
const int maxn = 1e5 + 5;
const int base = 2e5 + 5;
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 9;
using namespace std;

int n, m, res, len;
int a[maxn];
pii h[maxn];
pii b[maxn];
pii now;

pii add(pii a, int b){
    return {(a.X + b) % mod1, (a.Y + b) % mod2};
}
pii mul(pii a, int b){
    return {1ll * a.X * b % mod1, 1ll * a.Y * b % mod2};
}
pii add(pii a, pii b){
    return {(a.X + b.X) % mod1, (a.Y + b.Y) % mod2};
}
pii sub(pii a, pii b){
    return {(a.X - b.X + mod1) % mod1, (a.Y - b.Y + mod2) % mod2};
}
pii get(int l, int r){
    return sub(b[r], b[l - 1]);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i];
    m = sqrt(n * 2);
    h[0] = {1, 1};
    fi(i, 1, m){
        h[i] = mul(h[i - 1], base);
    }
    fi(i, 1, n){
        if (a[i] <= m){
            b[i] = add(b[i - 1], h[a[i]]);
        }
        else {
            b[i] = b[i - 1];
        }
    }
    fi(j, 1, m){
        len += j;
        now = add(now, mul(h[j], j));
        fi(i, 1, n - len + 1){
            if (get(i, i + len - 1) == now) res++;
        }
    }
    cout << res;
}
