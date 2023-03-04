#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "fct025_median"
const int maxn = 1e5 + 5;
using namespace std;

int n, a[maxn], b[maxn], c[maxn];
int bit[maxn * 2];

void update(int x){
    while (x <= (n << 1)){
        bit[x]++;
        x += x & -x;
    }
}

int get(int x){
    int ans = 0;
    while (x > 0){
        ans += bit[x];
        x -= x & -x;
    }
    return ans;
}

bool check(int g){
    fi(i, 1, n){
        if (a[i] >= g) c[i] = c[i - 1] + 1;
        else c[i] = c[i - 1] - 1;
    }
    fi(i, 0, n * 2) bit[i] = 0;
    ll cnt = 0;
    fi(i, 1, n){
        update(c[i - 1] + n);
        cnt += get(c[i] + n);
        if (cnt * 4 >= 1ll * n * (n + 1)) return 1;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i], b[i] = a[i];
    sort(b + 1, b + n + 1);
    int d = 1, c = n;
    while (d <= c){
        int g = (d + c) >> 1;
        if (check(b[g])) d = g + 1;
        else c = g - 1;
    }
    cout << b[c];
}
