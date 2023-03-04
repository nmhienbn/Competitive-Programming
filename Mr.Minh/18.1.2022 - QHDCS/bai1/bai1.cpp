#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "bai1"
const int maxn = 20;
using namespace std;

int n, a[maxn], p[maxn * 9];
ll f[maxn][2][maxn * 9];
string s;

void Erathosenes(int n){
    p[0] = p[1] = 1;
    for (int i = 2; i * i <= n; i++) if (!p[i]){
        for (int j = i * i; j <= n; j += i){
            p[j] = 1;
        }
    }
}

ll calc(int len, bool flag, int sum){
    if (len > n) return !p[sum];
    ll& dem = f[len][flag][sum];
    if (~dem) return dem;
    dem = 0;
    int ub = flag ? a[len] : 9;
    fi(i, 0, ub){
        if (flag && i == a[len])
            dem += calc(len + 1, 1, sum + i);
        else
            dem += calc(len + 1, 0, sum + i);
    }
    return dem;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> s;
    n = s.size();
    fi(i, 1, n) a[i] = s[i - 1] - '0';
    Erathosenes(n * 9);
    memset(f, -1, sizeof f);
    cout << calc(1, 1, 0);
}
