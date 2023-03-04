#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "medsum"
const int maxn = 205, maxm = 20005, mod = 1e9;
using namespace std;

int a[maxn][maxm], n, l;
ll res;

bool check(int gt, int i, int j){
    return upper_bound(a[i]+1, a[i]+l+1, gt) - a[i]
    + upper_bound(a[j]+1, a[j]+l+1, gt) - a[j] - 2 >= l;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> l;
    fi(i, 1, n) fi(j, 1, l) cin >> a[i][j];
    fi(i, 1, n){
        fi(j, 1, i-1){
            int d = -1e9, c = 1e9;
            while (d <= c){
                int g = (d + c) >> 1;
                if (check(g, i, j)) c = g-1;
                else d = g+1;
            }
            res = (res + d + mod) % mod;
        }
    }
    cout << res;
}
