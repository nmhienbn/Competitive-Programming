#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "medsum"
const int maxn = 205, maxm = 2e4 + 5, mod = 1e9;
using namespace std;

int m, n, a[maxn][maxm], res;

int cnt(int i, int x){
    return upper_bound(a[i] + 1, a[i] + n + 1, x) - a[i] - 1;
}

bool check(int i, int j, int x){
    return cnt(i, x) + cnt(j, x) >= n;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> m >> n;
    fi(i, 1, m) fi(j, 1, n)
        cin >> a[i][j];
    fi(i, 1, m) fi(j, i + 1, m){
        int d = 0, c = mod;
        while (d <= c){
            int g = (d + c) >> 1;
            if (check(i, j, g)) c = g - 1;
            else d = g + 1;
        }
        res += d;
        if (res >= mod) res -= mod;
    }
    cout << res;
}
