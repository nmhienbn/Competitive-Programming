#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "steel"
const int maxn = 5e5 + 5;
using namespace std;

int n, m;
pii a[maxn], b[maxn];
ll res;

ll area(int i, int j){
    return 1ll * (b[j].first - a[i].first) * (b[j].second - a[i].second);
}

void calc(int l, int r, int d, int c){
    if (l > r || d > c) return;
    int g = (d + c) >> 1;
    int pos = 0;
    ll ans = 0;
    fi(i, l, r) if (b[i].second > a[g].second){
        if (ans < area(g, i)) pos = i, ans = area(g, i);
    }
    res = max(res, ans);
    calc(l, pos, d, g - 1);
    calc(pos, r, g + 1, c);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, n) cin >> a[i].first >> a[i].second;
    sort(a + 1, a + n + 1);
    int cnt = 0;
    a[0].second = 1e9 + 1;
    fi(i, 1, n) if (a[i].second < a[cnt].second){
        a[++cnt] = a[i];
    }
    n = cnt;
    //fi(i, 1, n) cout << a[i].first << ' ' << a[i].second << '\n';
    fi(i, 1, m) cin >> b[i].first >> b[i].second;
    sort(b + 1, b + m + 1, greater<pii>());
    cnt = 0;
    fi(i, 1, m) if (b[i].second > b[cnt].second){
        b[++cnt] = b[i];
    }
    m = cnt;
    sort(b + 1, b + m + 1);
    //fi(i, 1, m) cout << b[i].first << ' ' << b[i].second << '\n';
    calc(1, m, 1, n);
    cout << res;
}
