#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "dttui1"
const int maxn = 11e5;

using namespace std;

struct pii {
    ll f, s;
    bool operator < (const pii& x) const {
        return f != x.f ? f < x.f : s < x.s;
    }
};

int n, m, w, u, v;
pii a[25], b[25], L[maxn], M[maxn];
ll res, d[maxn], maxx;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> w;
    m = n - n/2;
    n = n/2;
    fi(i, 1, n) cin >> a[i].f >> a[i].s;
    fi(i, 1, m) cin >> b[i].f >> b[i].s;

    u = (1 << n) - 1;
    fi(x, 1, u){
        fi(i, 0, n-1){
            if ((x >> i) & 1){
                L[x] = {L[x - (1 << i)].f + a[i+1].f, L[x - (1 << i)].s + a[i+1].s};
                break;
            }
        }
    }

    v = (1 << m) - 1;
    fi(x, 1, v){
        fi(i, 0, m-1){
            if ((x >> i) & 1){
                M[x] = {M[x - (1 << i)].f + b[i+1].f, M[x - (1 << i)].s + b[i+1].s};
                break;
            }
        }
    }

    sort(L, L+u+1);
    sort(M, M+v+1);
    fi(i, 1, v) d[i] = max(d[i-1], M[i].s);

    int j = v;
    fi(i, 0, u){
        maxx = max(maxx, L[i].s);
        while (L[i].f + M[j].f > w && j >= 0) j--;
        if (L[i].f + M[j].f <= w) res = max(res, maxx + d[j]);
    }
    cout << res;
}
