#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "mincost"
const int maxn = 205;

using namespace std;

struct pii {
    int f, s;
    bool operator < (const pii& x) const {
        return (f-s != x.f-x.s ? f-s < x.f-x.s : f < x.f);
    }
};

int n, L[maxn][maxn];
pii a[maxn];
ll res = 1e18;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        fi(j, 1, n){
            cin >> L[i][j];
        }
    }
    fi(i, 2, n){
        fi(j, 1, i-1){
            int m = 0;
            ll ans = 0;
            fi(t, 1, n) if (t != i && t != j){
                a[++m] = {L[i][t], L[j][t]};
            }
            fi(i, 1, m/2) ans += a[i].f;
            fi(i, m/2+1, m) ans += a[i].s;
            res = min(res, ans);
        }
    }
    cout << res;
}
