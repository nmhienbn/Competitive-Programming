#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "queen"
const int maxn = 1005;
using namespace std;

int n, m, a[maxn][maxn];
ll ngg[maxn], doc[maxn], cc[maxn*2], cp[maxn*2], res = -1e18;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> m >> n;
    fi(i, 1, m){
        fi(j, 1, n){
            int x;
            cin >> x;
            a[i][j] = x;
            ngg[i] += x;
            doc[j] += x;
            cc[i-j+n] += x;
            cp[i+j] += x;
        }
    }
    fi(i, 1, m){
        fi(j, 1, n){
            res = max(res, ngg[i] + doc[j] + cc[i-j+n] + cp[i+j] - a[i][j] * 3);
        }
    }
    cout << res;
}
