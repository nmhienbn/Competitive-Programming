#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define F first
#define S second
#define pii pair <int, int>
#define pb push_back
#define Irelia "imprison"
const int maxn = 1e5+5;
using namespace std;

int n, res, l[maxn], r[maxn];
bool flag[maxn];
pii a[maxn];

int get_root(int u){
    return l[u] == u ? u : l[u] = get_root(l[u]);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i].S >> a[i].F;
    sort(a + 1, a + n + 1);
    fi(i, 1, n) l[i] = i, r[i] = i + 1;
    fi(i, 1, n - 1){
        if (flag[i]){
            res += a[i + 1].F - a[i].F;
            continue;
        }
        while (true){
            if (l[i] == 0 || r[i] == n + 1)
                break;
            int d = a[r[i]].F - a[l[i]].F;
            if (d > a[l[i]].S){
                l[i] = get_root(l[i]-1);
                r[i] = max(r[i], r[l[i]]);
            }
            else
                if (d > a[r[i]].S)
                    r[i]++;
                else
                    break;
        }
        if (1 <= l[i] && r[i] <= n){
            res += a[i+1].F - a[i].F;
            fi(j, i, r[i] - 1) l[j] = i, flag[j] = 1;
        }
    }
    cout << res;
}
