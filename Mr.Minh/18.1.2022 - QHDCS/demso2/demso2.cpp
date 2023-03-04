#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "demso2"
const int maxn = 16;
using namespace std;

ll f[20][2][13][20][2];
int n, a[20], m;
string s;

ll calc(int len, bool flag, int en, int k, bool nz){
    if (k > m) return 0;
    if (len > n) return 1;
    if (~f[len][flag][en][k][nz]) return f[len][flag][en][k][nz];
    ll& cnt = f[len][flag][en][k][nz];
    cnt = 0;
    int ub = flag ? a[len] : 9;
    fi(i, 0, ub){
        if (flag && i == a[len])
            cnt += calc(len + 1, 1, i, k + (i == en && (nz || i)), nz || i);
        else
            cnt += calc(len + 1, 0, i, k + (i == en && (nz || i)), nz || i);
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> s >> m;
    n = s.size();
    fi(i, 1, n) a[i] = s[i - 1] - '0';
    memset(f, -1, sizeof f);
    cout << calc(1, 1, 10, 0, 0);
}
